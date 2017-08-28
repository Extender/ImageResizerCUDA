#include "io.h"

uint8_t io::readUInt8(char *&data)
{
    return (uint8_t)*(data++);
}

uint16_t io::readUInt16(char *&data)
{
    uint16_t out=(uint8_t)*(data++);
    out|=(uint16_t)((uint8_t)*(data++))<<8;
    return out;
}

uint32_t io::readUInt32(char *&data)
{
    uint32_t out=(uint8_t)*(data++);
    out|=(uint32_t)((uint8_t)*(data++))<<8;
    out|=(uint32_t)((uint8_t)*(data++))<<16;
    out|=(uint32_t)((uint8_t)*(data++))<<24;
    return out;
}

uint64_t io::readUInt64(char *&data)
{
    uint64_t out=(uint8_t)*(data++);
    out|=(uint64_t)((uint8_t)*(data++))<<8;
    out|=(uint64_t)((uint8_t)*(data++))<<16;
    out|=(uint64_t)((uint8_t)*(data++))<<24;
    out|=(uint64_t)((uint8_t)*(data++))<<32;
    out|=(uint64_t)((uint8_t)*(data++))<<40;
    out|=(uint64_t)((uint8_t)*(data++))<<48;
    out|=(uint64_t)((uint8_t)*(data++))<<56;
    return out;
}

fs_t io::readFsT(char *&data)
{
    return readUInt32(data);
}

float io::readFloat(char *&data, bool systemIsLittleEndian)
{
    uint32_t f=readUInt32(data);
    if(!systemIsLittleEndian)
        f=reverseUInt32BitOrder(f,false);
    void *ptr=&f;
    return (float)*((float*)ptr);
}

double io::readDouble(char *&data, bool systemIsLittleEndian)
{
    uint64_t f=readUInt64(data);
    if(!systemIsLittleEndian)
        f=reverseUInt64BitOrder(f,false);
    void *ptr=&f;
    return (double)*((double*)ptr);
}

double io::readDouble2(char *&data)
{
    int64_t i=readUInt64(data);
    uint64_t f=readUInt64(data);
    return (double)i+((double)f/pow(2,(double)52));
}

char *io::readFixedLengthData(char *&data, fs_t &length)
{
    length=readFsT(data);
    char *out=(char*)calloc(length,1);
    for(fs_t i=0;i<length;i++)
        out[i]=*(data++);
    return out;
}

char *io::readZeroTerminatedData(char *&data)
{
    fs_t length=strlen(data);
    char *out=(char*)calloc(length+1,1);
    for(fs_t i=0;i<length;i++)
        out[i]=*(data++);
    data++; // Zero-terminator
    return out;
}

uint8_t io::peekUInt8(char *data, fs_t pos)
{
    return (uint8_t)data[pos++];
}

uint16_t io::peekUInt16(char *data, fs_t pos)
{
    uint16_t out=(uint8_t)data[pos++];
    out|=((uint16_t)((uint8_t)data[pos++]))<<8;
    return out;
}

uint32_t io::peekUInt32(char *data, fs_t pos)
{
    uint32_t out=(uint8_t)data[pos++];
    out|=((uint32_t)((uint8_t)data[pos++]))<<8;
    out|=((uint32_t)((uint8_t)data[pos++]))<<16;
    out|=((uint32_t)((uint8_t)data[pos++]))<<24;
    return out;
}

uint64_t io::peekUInt64(char *data, fs_t pos)
{
    uint64_t out=(uint8_t)data[pos++];
    out|=((uint64_t)((uint8_t)data[pos++]))<<8;
    out|=((uint64_t)((uint8_t)data[pos++]))<<16;
    out|=((uint64_t)((uint8_t)data[pos++]))<<24;
    out|=((uint64_t)((uint8_t)data[pos++]))<<32;
    out|=((uint64_t)((uint8_t)data[pos++]))<<40;
    out|=((uint64_t)((uint8_t)data[pos++]))<<48;
    out|=((uint64_t)((uint8_t)data[pos++]))<<56;
    return out;
}

fs_t io::peekFsT(char *data, fs_t pos)
{
    return peekUInt32(data,pos);
}

double io::peekFloat(char *data, fs_t pos, bool systemIsLittleEndian)
{
    uint32_t f=peekUInt32(data,pos);
    if(!systemIsLittleEndian)
        f=reverseUInt32BitOrder(f,false);
    void *ptr=&f;
    return (float)*((float*)ptr);
}

double io::peekDouble(char *data, fs_t pos, bool systemIsLittleEndian)
{
    uint64_t f=peekUInt64(data,pos);
    if(!systemIsLittleEndian)
        f=reverseUInt64BitOrder(f,false);
    void *ptr=&f;
    return (double)*((double*)ptr);
}

double io::peekDouble2(char *data, fs_t pos)
{
    int64_t i=peekUInt64(data,pos);
    uint64_t f=peekUInt64(data,pos+sizeof(uint64_t));
    return (double)i+((double)f/pow(2,(double)52));
}

char *io::peekFixedLengthData(char *data, fs_t pos, fs_t &length)
{
    length=posBasedReadFsT(data,pos);
    char *out=(char*)calloc(length,1);
    for(fs_t i=0;i<length;i++)
        out[i]=data[pos++];
    return out;
}

char *io::peekZeroTerminatedData(char *data, fs_t pos)
{
    fs_t length=strlen(data);
    char *out=(char*)calloc(length+1,1);
    for(fs_t i=0;i<length;i++)
        out[i]=data[pos++];
    pos++; // Zero-terminator
    return out;
}

uint8_t io::posBasedReadUInt8(char *data, fs_t &pos)
{
    return (uint8_t)data[pos++];
}

uint16_t io::posBasedReadUInt16(char *data, fs_t &pos)
{
    uint16_t out=(uint8_t)data[pos++];
    out|=((uint16_t)((uint8_t)data[pos++]))<<8;
    return out;
}

uint32_t io::posBasedReadUInt32(char *data, fs_t &pos)
{
    uint32_t out=data[pos++];
    out|=((uint32_t)((uint8_t)data[pos++]))<<8;
    out|=((uint32_t)((uint8_t)data[pos++]))<<16;
    out|=((uint32_t)((uint8_t)data[pos++]))<<24;
    return out;
}

uint64_t io::posBasedReadUInt64(char *data, fs_t &pos)
{
    uint64_t out=(uint8_t)data[pos++];
    out|=((uint64_t)((uint8_t)data[pos++]))<<8;
    out|=((uint64_t)((uint8_t)data[pos++]))<<16;
    out|=((uint64_t)((uint8_t)data[pos++]))<<24;
    out|=((uint64_t)((uint8_t)data[pos++]))<<32;
    out|=((uint64_t)((uint8_t)data[pos++]))<<40;
    out|=((uint64_t)((uint8_t)data[pos++]))<<48;
    out|=((uint64_t)((uint8_t)data[pos++]))<<56;
    return out;
}

fs_t io::posBasedReadFsT(char *data, fs_t &pos)
{
    return posBasedReadUInt32(data,pos);
}

float io::posBasedReadFloat(char *data, fs_t &pos, bool systemIsLittleEndian)
{
    uint32_t f=posBasedReadUInt32(data,pos);
    if(!systemIsLittleEndian)
        f=reverseUInt32BitOrder(f,false);
    void *ptr=&f;
    return (float)*((float*)ptr);
}

double io::posBasedReadDouble(char *data, fs_t &pos, bool systemIsLittleEndian)
{
    uint64_t f=posBasedReadUInt64(data,pos);
    if(!systemIsLittleEndian)
        f=reverseUInt64BitOrder(f,false);
    void *ptr=&f;
    return (double)*((double*)ptr);
}

double io::posBasedReadDouble2(char *data, fs_t &pos)
{
    int64_t i=posBasedReadUInt64(data,pos);
    uint64_t f=posBasedReadUInt64(data,pos);
    return (double)i+((double)f/pow(2,(double)52));
}

char *io::posBasedReadFixedLengthData(char *data, fs_t &pos, fs_t &length)
{
    length=posBasedReadFsT(data,pos);
    char *out=(char*)calloc(length,1);
    for(fs_t i=0;i<length;i++)
        out[i]=data[pos++];
    return out;
}

char *io::posBasedReadZeroTerminatedData(char *data, fs_t &pos)
{
    fs_t length=strlen(data+pos);
    char *out=(char*)calloc(length+1,1);
    for(fs_t i=0;i<length;i++)
        out[i]=data[pos++];
    pos++; // Zero-terminator
    return out;
}

void io::writeUInt8(char *data, uint8_t i, fs_t &pos)
{
    data[pos++]=i;
}

void io::writeUInt16(char *data, uint16_t i, fs_t &pos)
{
    data[pos++]=(uint8_t)i;
    data[pos++]=(uint8_t)(i>>8);
}

void io::writeUInt32(char *data, uint32_t i, fs_t &pos)
{
    data[pos++]=(uint8_t)i;
    data[pos++]=(uint8_t)(i>>8);
    data[pos++]=(uint8_t)(i>>16);
    data[pos++]=(uint8_t)(i>>24);
}

void io::writeUInt64(char *data, uint64_t i, fs_t &pos)
{
    data[pos++]=(uint8_t)i;
    data[pos++]=(uint8_t)(i>>8);
    data[pos++]=(uint8_t)(i>>16);
    data[pos++]=(uint8_t)(i>>24);
    data[pos++]=(uint8_t)(i>>32);
    data[pos++]=(uint8_t)(i>>40);
    data[pos++]=(uint8_t)(i>>48);
    data[pos++]=(uint8_t)(i>>56);
}

void io::writeFsT(char *data, fs_t i, fs_t &pos)
{
    writeUInt32(data,i,pos);
}

void io::writeFloat(char *data, float i, fs_t &pos, bool systemIsLittleEndian)
{
    void *ptr=&i;
    uint32_t u=*((uint32_t*)ptr);
    if(!systemIsLittleEndian)
        u=reverseUInt32BitOrder(u,false);
    writeUInt32(data,u,pos);
}

void io::writeDouble(char *data, double i, fs_t &pos, bool systemIsLittleEndian)
{
    void *ptr=&i;
    uint64_t u=*((uint64_t*)ptr);
    if(!systemIsLittleEndian)
        u=reverseUInt64BitOrder(u,false);
    writeUInt64(data,u,pos);
}

void io::writeDouble2(char *data, double i, fs_t &pos)
{
    int64_t n=(int64_t)floorl(i); // Not uint64_t!
    double fd=(((double)i-(double)n)*pow(2,(double)52)); // 2^64 is too large for the double! This is the optimum!
    uint64_t fl=(uint64_t)floorl(fd);
    writeUInt64(data,n,pos);
    writeUInt64(data,fl,pos);
}

void io::writeFixedLengthData(char *data, fs_t length, const char *in, fs_t &pos)
{
    writeFsT(data,length,pos);
    for(fs_t i=0;i<length;i++)
        data[pos++]=(uint8_t)in[i];
}

void io::writeZeroTerminatedData(char *data, const char *in, fs_t &pos)
{
    fs_t length=strlen(in);
    for(fs_t i=0;i<length;i++)
        data[pos++]=(uint8_t)in[i];
    data[pos++]=0;
}

void io::writeRawData(char *data, const char *in, fs_t length, fs_t &pos)
{
    for(fs_t i=0;i<length;i++)
        data[pos++]=(uint8_t)in[i];
}


void io::putUInt8(char *data, uint8_t i, fs_t pos)
{
    data[pos++]=i;
}

void io::putUInt16(char *data, uint16_t i, fs_t pos)
{
    data[pos++]=(uint8_t)i;
    data[pos++]=(uint8_t)(i>>8);
}

void io::putUInt32(char *data, uint32_t i, fs_t pos)
{
    data[pos++]=(uint8_t)i;
    data[pos++]=(uint8_t)(i>>8);
    data[pos++]=(uint8_t)(i>>16);
    data[pos++]=(uint8_t)(i>>24);
}

void io::putUInt64(char *data, uint64_t i, fs_t pos)
{
    data[pos++]=(uint8_t)i;
    data[pos++]=(uint8_t)(i>>8);
    data[pos++]=(uint8_t)(i>>16);
    data[pos++]=(uint8_t)(i>>24);
    data[pos++]=(uint8_t)(i>>32);
    data[pos++]=(uint8_t)(i>>40);
    data[pos++]=(uint8_t)(i>>48);
    data[pos++]=(uint8_t)(i>>56);
}

void io::putFsT(char *data, fs_t i, fs_t pos)
{
    putUInt32(data,i,pos);
}

void io::putFloat(char *data, float i, fs_t pos, bool systemIsLittleEndian)
{
    void *ptr=&i;
    uint32_t u=*((uint32_t*)ptr);
    if(!systemIsLittleEndian)
        u=reverseUInt32BitOrder(u,false);
    putUInt32(data,u,pos);
}

void io::putDouble(char *data, double i, fs_t pos, bool systemIsLittleEndian)
{
    void *ptr=&i;
    uint64_t u=*((uint64_t*)ptr);
    if(!systemIsLittleEndian)
        u=reverseUInt64BitOrder(u,false);
    putUInt64(data,u,pos);
}

void io::putDouble2(char *data, double i, fs_t pos)
{
    int64_t n=(int64_t)floorl(i); // Not uint64_t!
    double fd=(((double)i-(double)n)*pow(2,(double)52)); // 2^64 is too large for the double! This is the optimum!
    uint64_t fl=(uint64_t)floorl(fd);
    putUInt64(data,n,pos);
    pos+=sizeof(uint64_t);
    putUInt64(data,fl,pos);
}

void io::putFixedLengthData(char *data, fs_t length, const char *in, fs_t pos)
{
    putFsT(data,length,pos);
    pos+=sizeof(fs_t);
    for(fs_t i=0;i<length;i++)
        data[pos++]=(uint8_t)in[i];
}

void io::putZeroTerminatedData(char *data, const char *in, fs_t pos)
{
    fs_t length=strlen(in);
    for(fs_t i=0;i<length;i++)
        data[pos++]=(uint8_t)in[i];
    data[pos++]=0;
}

void io::putRawData(char *data, const char *in, fs_t length, fs_t pos)
{
    for(fs_t i=0;i<length;i++)
        data[pos++]=(uint8_t)in[i];
}

void io::writeUInt8ToBuffer(char *&data, uint8_t i, fs_t &pos, fs_t &bufferSize)
{
    fs_t newPos=pos+sizeof(uint8_t);
    bufferCheck(data,newPos,bufferSize);
    writeUInt8(data,i,pos);
}

void io::writeUInt16ToBuffer(char *&data, uint16_t i, fs_t &pos, fs_t &bufferSize)
{
    fs_t newPos=pos+sizeof(uint16_t);
    bufferCheck(data,newPos,bufferSize);
    writeUInt16(data,i,pos);
}

void io::writeUInt32ToBuffer(char *&data, uint32_t i, fs_t &pos, fs_t &bufferSize)
{
    fs_t newPos=pos+sizeof(uint32_t);
    bufferCheck(data,newPos,bufferSize);
    writeUInt32(data,i,pos);
}

void io::writeUInt64ToBuffer(char *&data, uint64_t i, fs_t &pos, fs_t &bufferSize)
{
    fs_t newPos=pos+sizeof(uint64_t);
    bufferCheck(data,newPos,bufferSize);
    writeUInt64(data,i,pos);
}

void io::writeFsTToBuffer(char *&data, fs_t i, fs_t &pos, fs_t &bufferSize)
{
    writeUInt32ToBuffer(data,i,pos,bufferSize);
}

void io::writeFloatToBuffer(char *&data, float i, fs_t &pos, fs_t &bufferSize, bool systemIsLittleEndian)
{
    void *ptr=&i;
    uint32_t u=*((uint32_t*)ptr);
    if(!systemIsLittleEndian)
        u=reverseUInt32BitOrder(u,false);
    writeUInt32ToBuffer(data,u,pos,bufferSize);
}

void io::writeDoubleToBuffer(char *&data, double i, fs_t &pos, fs_t &bufferSize, bool systemIsLittleEndian)
{
    void *ptr=&i;
    uint64_t u=*((uint64_t*)ptr);
    if(!systemIsLittleEndian)
        u=reverseUInt64BitOrder(u,false);
    writeUInt64ToBuffer(data,u,pos,bufferSize);
}

void io::writeDoubleToBuffer2(char *&data, double i, fs_t &pos, fs_t &bufferSize)
{
    int64_t n=(int64_t)floorl((double)i); // Not uint64_t!
    double fd=((double)((double)i-n)*pow(2,(double)52));
    uint64_t fl=(uint64_t)floorl(fd);
    writeUInt64ToBuffer(data,n,pos,bufferSize);
    writeUInt64ToBuffer(data,fl,pos,bufferSize);
}

void io::writeFixedLengthDataToBuffer(char *&data, fs_t length, const char *in, fs_t &pos, fs_t &bufferSize)
{
    fs_t newPos=pos+length+sizeof(fs_t);
    bufferCheck(data,newPos,bufferSize);
    writeFixedLengthData(data,length,in,pos);
}

void io::writeZeroTerminatedDataToBuffer(char *&data, const char *in, fs_t &pos, fs_t &bufferSize)
{
    fs_t newPos=pos+strlen(in)+1;
    bufferCheck(data,newPos,bufferSize);
    writeZeroTerminatedData(data,in,pos);
}

void io::writeRawDataToBuffer(char *&data, const char *in, fs_t length, fs_t &pos, fs_t &bufferSize)
{
    fs_t newPos=pos+length;
    bufferCheck(data,newPos,bufferSize);
    writeRawData(data,in,length,pos);
}

void io::writeRawDataToLongBuffer(char *&data, const char *in, uint64_t length, uint64_t &pos, uint64_t &bufferSize)
{
    uint64_t newPos=pos+length;
    longBufferCheck(data,newPos,bufferSize);
    memcpy(data+((size_t)pos),in,(size_t)length);
    pos+=length;
}

void io::writeRawCharToBuffer(char *&data, unsigned char in, fs_t &pos, fs_t &bufferSize)
{
    if(pos+1==bufferSize) // Because we're only adding one character, == is permissible here.
    {
        extendBufferSize(bufferSize,pos+1);
        data=(char*)realloc(data,bufferSize);
    }
    data[pos++]=in;
}

void io::writeRawCharToLongBuffer(char *&data, unsigned char in, uint64_t &pos, uint64_t &bufferSize)
{
    longBufferCheck(data,pos+1,bufferSize);
    data[pos++]=in;
}

void io::terminateBuffer(char *&buffer, fs_t &pos, fs_t bufferSize)
{
    bufferCheck(buffer,pos,bufferSize);
    buffer[pos]=0; // Do not use pos++! Many functions use the parameter passed in "pos" as a string length indicator!
}

void *io::fixedLengthDataToString(char *data, fs_t length)
{
    char *out=(char*)malloc(length+1);
    out[length]=0;
    memcpy(out,data,length);
    return out;
}

bool io::bufferCheck(char *&buffer, fs_t pos, fs_t &bufferSize)
{
    bool ret=true;
    while(pos>=bufferSize) // Needed to check if sth would fit into the buffer.
    {
        extendBufferSize(bufferSize,pos);
        buffer=(char*)realloc(buffer,bufferSize);
        ret=false;
    }
    return ret;
}

bool io::longBufferCheck(char *&buffer, uint64_t pos, uint64_t &bufferSize)
{
    bool ret=true;
    while(pos>=bufferSize) // Needed to check if sth would fit into the buffer.
    {
        extendBufferSize(bufferSize,pos);
        buffer=(char*)realloc(buffer,(size_t)bufferSize);
        ret=false;
    }
    return ret;
}

bool io::getSystemIsLittleEndian()
{
    union
    {
        uint32_t i;
        char c[4];
    } b={0x01020304};
    return b.c[0]==0x04;
}

uint16_t io::reverseUInt16ByteOrder(uint16_t i)
{
    uint16_t r=(uint16_t)(i>>8);
    r|=(uint16_t)((uint16_t)(i&0xFF))<<8;
    return r;
}

uint32_t io::reverseUInt32ByteOrder(uint32_t i)
{
    uint32_t r=(uint32_t)(i>>24);
    r|=(uint32_t)((uint32_t)((i>>16)&0xFF))<<8;
    r|=(uint32_t)((uint32_t)((i>>8)&0xFF))<<16;
    r|=(uint32_t)((uint32_t)(i&0xFF))<<24;
    return r;
}

uint64_t io::reverseUInt64ByteOrder(uint64_t i)
{
    uint64_t r=(uint64_t)(i>>56);
    r|=(uint64_t)((uint64_t)((i>>48)&0xFF))<<8;
    r|=(uint64_t)((uint64_t)((i>>40)&0xFF))<<16;
    r|=(uint64_t)((uint64_t)((i>>32)&0xFF))<<24;
    r|=(uint64_t)((uint64_t)((i>>24)&0xFF))<<32;
    r|=(uint64_t)((uint64_t)((i>>16)&0xFF))<<40;
    r|=(uint64_t)((uint64_t)((i>>8)&0xFF))<<48;
    r|=(uint64_t)((uint64_t)(i&0xFF))<<56;
    return r;
}

void io::reverseByteOrder(char *data, fs_t length)
{
    // If length is uneven, the byte at the center doesn't need to be replaced.
    if(length<2)
        return;
    fs_t lastIndex=length-1;
    fs_t mirroredIndex;
    for(fs_t i=0;i<(fs_t)(length/2);i++)
    {
        mirroredIndex=lastIndex-i;
        uint8_t newByte=data[mirroredIndex];
        data[mirroredIndex]=data[i];
        data[i]=newByte;
    }
}

uint8_t io::reverseUInt8BitOrder(uint8_t i, bool systemIsLittleEndian)
{
    void *ptr=&i;
    reverseBitOrder((char*)ptr,sizeof(uint8_t)*8,systemIsLittleEndian);
    return (uint8_t)*((uint8_t*)ptr);
}

uint16_t io::reverseUInt16BitOrder(uint16_t i, bool systemIsLittleEndian)
{
    void *ptr=&i;
    reverseBitOrder((char*)ptr,sizeof(uint16_t)*8,systemIsLittleEndian);
    return (uint16_t)*((uint16_t*)ptr);
}

uint32_t io::reverseUInt32BitOrder(uint32_t i, bool systemIsLittleEndian)
{
    void *ptr=&i;
    reverseBitOrder((char*)ptr,sizeof(uint32_t)*8,systemIsLittleEndian);
    return (uint32_t)*((uint32_t*)ptr);
}

uint64_t io::reverseUInt64BitOrder(uint64_t i, bool systemIsLittleEndian)
{
    void *ptr=&i;
    reverseBitOrder((char*)ptr,sizeof(uint64_t)*8,systemIsLittleEndian);
    return (uint64_t)*((uint64_t*)ptr);
}

void io::reverseBitOrder(char *data, fs_t lengthInBits, bool systemIsLittleEndian)
{
    // Difference: direction of the bitshifts
    // If length is uneven, the bit at the center doesn't need to be replaced.
    fs_t lastIndex=lengthInBits-1;
    fs_t mirroredIndex=lengthInBits-1;
    fs_t nBit;
    fs_t mirroredNBit;
    fs_t nByte;
    fs_t mirroredNByte;
    if(systemIsLittleEndian)
    {
        for(fs_t i=0;i<(fs_t)(lengthInBits/2);i++)
        {
            nByte=(fs_t)(i/8);
            nBit=i-nByte*8;
            mirroredIndex=lastIndex-i;
            mirroredNByte=(fs_t)(mirroredIndex/8);
            mirroredNBit=mirroredIndex-mirroredNByte*8;
            bool bit=(data[nByte]&(1<<nBit))>0;
            bool mirroredBit=(data[mirroredNByte]&(1<<mirroredNBit))>0;
            uint8_t pattern=1<<(7-nBit);
            if(bit)
                data[mirroredNByte]|=pattern;
            else
                data[mirroredNByte]&=(~pattern);
            uint8_t nPattern=1<<(7-mirroredNBit);
            if(mirroredBit)
                data[nByte]|=nPattern;
            else
                data[nByte]&=(~nPattern);
        }
    }
    else
    {
        for(fs_t i=0;i<(fs_t)(lengthInBits/2);i++)
        {
            nByte=(fs_t)(i/8);
            nBit=i-nByte*8;
            mirroredIndex=lastIndex-i;
            mirroredNByte=(fs_t)(mirroredIndex/8);
            mirroredNBit=mirroredIndex-mirroredNByte*8;
            bool bit=(data[nByte]&(1>>nBit))>0;
            bool mirroredBit=(data[mirroredNByte]&(1>>mirroredNBit))>0;
            uint8_t pattern=1>>(7-nBit);
            if(bit)
                data[mirroredNByte]|=pattern;
            else
                data[mirroredNByte]&=(~pattern);
            uint8_t nPattern=1>>(7-mirroredNBit);
            if(mirroredBit)
                data[nByte]|=nPattern;
            else
                data[nByte]&=(~nPattern);
        }
    }
}
