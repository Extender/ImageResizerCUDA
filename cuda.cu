#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "decimal.h"
#include "colordefs.h"
#include "text.h"

#include <iostream>

#define bilinearInterpolate(c00,c01,c10,c11,w1,w2,w3,w4) (w1*c00+w2*c01+w3*c10+w4*c11)

#define CUDA_THREADS_PER_BLOCK 1024 // Optimal value (calculated)

#if 0==1
#define __shared__
#define __global__
#define __device__
#define __host__
#endif

void cudaLog(const char *str)
{
    std::cout<<str<<std::endl;
}

__global__ void device_bilinearResize(int origImgWidth,int origImgHeight,int newImgWidth,decimal_t origRatio,int blocksPerLine,uint32_t *origImgData,uint32_t *newImgData)
{
    // Each block is responsible for 1024 px of a single row. Do not use shared memory, as we cannot predict the distances between two lines we need in the source image.

    int threadId=threadIdx.x;
    int blockId=blockIdx.x;
    int newY=(blockId-(blockId%blocksPerLine))/blocksPerLine;
    int blockIdInLine=blockId-newY*blocksPerLine;
    int newX=blockIdInLine*CUDA_THREADS_PER_BLOCK+threadId;

    if(newX>=newImgWidth)
        return;

    // y-specific:

    decimal_t oldYRF;
    int oldY;
    decimal_t oldYF;
    decimal_t yDiff;
    decimal_t yDiffR;

    oldYRF=origRatio*(decimal_t)newY;
    oldY=(int)floor(oldYRF);
    oldYF=(decimal_t)oldY;
    yDiff=oldYRF-oldYF;
    yDiffR=1.0-yDiff;

    // x-specific:

    decimal_t oldXRF=origRatio*(decimal_t)newX;
    int oldX=(int)floor(oldXRF);
    decimal_t oldXF=(decimal_t)oldX;
    decimal_t xDiff=oldXRF-oldXF;
    decimal_t xDiffR=1.0-xDiff;

    // Each thread is responsible for a single pixel in the new image

    uint32_t c00,c01,c10,c11;
    int xLim=origImgWidth-1;
    int yLim=origImgHeight-1;

    const int currentLineOffset= oldY*origImgWidth;
    const int lineBelowOffset=(oldY==yLim?oldY:oldY+1)*origImgWidth;
    int oldXPlusOne=(oldX==xLim?oldX:oldX+1);

    c00=origImgData[currentLineOffset+oldX];
    c10=origImgData[currentLineOffset+oldXPlusOne];
    c01=origImgData[lineBelowOffset+oldX];
    c11=origImgData[lineBelowOffset+oldXPlusOne];

    decimal_t w1=xDiffR*yDiffR;
    decimal_t w2=xDiff*yDiffR;
    decimal_t w3=xDiffR*yDiff;
    decimal_t w4=xDiff*yDiff;

    uint32_t newAlpha=bilinearInterpolate(getAlpha(c00),getAlpha(c01),getAlpha(c10),getAlpha(c11),w1,w2,w3,w4);
    uint32_t newRed=bilinearInterpolate(getRed(c00),getRed(c01),getRed(c10),getRed(c11),w1,w2,w3,w4);
    uint32_t newGreen=bilinearInterpolate(getGreen(c00),getGreen(c01),getGreen(c10),getGreen(c11),w1,w2,w3,w4);
    uint32_t newBlue=bilinearInterpolate(getBlue(c00),getBlue(c01),getBlue(c10),getBlue(c11),w1,w2,w3,w4);

    newImgData[newY*newImgWidth+newX]=getColor(newAlpha,newRed,newGreen,newBlue);
}

__global__ void device_nearestNeighborResize(int origImgWidth,int newImgWidth,decimal_t origRatio,int blocksPerLine,uint32_t *origImgData,uint32_t *newImgData)
{
    // Each block is responsible for 1024 px of a single row. Do not use shared memory, as we cannot predict the distances between two lines we need in the source image.

    int threadId=threadIdx.x;
    int blockId=blockIdx.x;
    int newY=(blockId-(blockId%blocksPerLine))/blocksPerLine;
    int blockIdInLine=blockId-newY*blocksPerLine;
    int newX=blockIdInLine*CUDA_THREADS_PER_BLOCK+threadId;

    if(newX>=newImgWidth)
        return;

    int oldX=(int)round(origRatio*((decimal_t)newX));
    int oldY=(int)round(origRatio*((decimal_t)newY));

    newImgData[newY*newImgWidth+newX]=origImgData[oldY*origImgWidth+oldX];
}



uint32_t *cudaNearestNeighborResize(uint32_t *origImageData,int origImgWidth,int origImgHeight,int newImgWidth,int newImgHeight,decimal_t resizeRatio)
{
    int blocksPerLine=ceil(floatDiv(newImgWidth,CUDA_THREADS_PER_BLOCK));
    int totalNumBlocks=blocksPerLine*newImgHeight; // Each block is responsible for a single line

    if(totalNumBlocks>65535)
        return 0;

    uint32_t *device_origImageData_in;
    uint32_t *device_newImageData_out;
    size_t origImageSize=origImgWidth*origImgHeight*sizeof(uint32_t);
    size_t newImageSize=newImgWidth*newImgHeight*sizeof(uint32_t);
    cudaMalloc(&device_origImageData_in,origImageSize);
    cudaMalloc(&device_newImageData_out,newImageSize);

    cudaMemcpy(device_origImageData_in,origImageData,origImageSize,cudaMemcpyHostToDevice);

    decimal_t origRatio=decimalDiv(1.0,resizeRatio);
    device_nearestNeighborResize<<<totalNumBlocks,CUDA_THREADS_PER_BLOCK>>>(origImgWidth,newImgWidth,origRatio,blocksPerLine,device_origImageData_in,device_newImageData_out);

    uint32_t *newImageData=(uint32_t*)malloc(newImageSize);
    cudaMemcpy(newImageData,device_newImageData_out,newImageSize,cudaMemcpyDeviceToHost);

    cudaFree(device_newImageData_out);
    cudaFree(device_origImageData_in);

    return newImageData;
}

uint32_t *cudaBilinearResize(uint32_t *origImageData,int origImgWidth,int origImgHeight,int newImgWidth,int newImgHeight,decimal_t resizeRatio)
{
    int blocksPerLine=ceil(floatDiv(newImgWidth,CUDA_THREADS_PER_BLOCK));
    int totalNumBlocks=blocksPerLine*newImgHeight; // Each block is responsible for a single line

    if(totalNumBlocks>65535)
        return 0;

    uint32_t *device_origImageData_in;
    uint32_t *device_newImageData_out;
    size_t origImageSize=origImgWidth*origImgHeight*sizeof(uint32_t);
    size_t newImageSize=newImgWidth*newImgHeight*sizeof(uint32_t);
    cudaMalloc(&device_origImageData_in,origImageSize);
    cudaMalloc(&device_newImageData_out,newImageSize);

    cudaMemcpy(device_origImageData_in,origImageData,origImageSize,cudaMemcpyHostToDevice);

    decimal_t origRatio=decimalDiv(1.0,resizeRatio);
    device_bilinearResize<<<totalNumBlocks,CUDA_THREADS_PER_BLOCK>>>(origImgWidth,origImgHeight,newImgWidth,origRatio,blocksPerLine,device_origImageData_in,device_newImageData_out);

    uint32_t *newImageData=(uint32_t*)malloc(newImageSize);
    cudaMemcpy(newImageData,device_newImageData_out,newImageSize,cudaMemcpyDeviceToHost);

    cudaFree(device_newImageData_out);
    cudaFree(device_origImageData_in);

    return newImageData;
}
