#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dialog=new QFileDialog(this);
    dialog->setAcceptMode(QFileDialog::AcceptOpen);
    QStringList filters;
    filters<<"All images (*.jpg *.jpeg *.png *.gif *.bmp)"
           <<"JPEG images (*.jpg *.jpeg)"
           <<"PNG images (*.png)"
           <<"GIF images (*.gif)"
           <<"Bitmaps (*.bmp)";
    dialog->setNameFilters(filters);
    dialog->setDirectory(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation));
    connect(dialog,SIGNAL(fileSelected(QString)),this,SLOT(dialogFileSelected(QString)));
    connect(ui->browseBtn,SIGNAL(clicked(bool)),this,SLOT(browseBtnClicked()));
    connect(ui->loadBtn,SIGNAL(clicked(bool)),this,SLOT(loadBtnClicked()));
    connect(ui->fitToWindowBtn,SIGNAL(clicked(bool)),this,SLOT(fitToWindow()));
    connect(ui->resetZoomBtn,SIGNAL(clicked(bool)),this,SLOT(resetZoom()));
    image=0;
    originalImageData=0;
    scene=new QGraphicsScene();
    pixmapItem=new QGraphicsPixmapItem();
    scene->addItem(pixmapItem);
    ui->graphicsView->setScene(scene);

    connect(ui->resizeBtn,SIGNAL(clicked(bool)),this,SLOT(resizeBtnClicked()));
    connect(ui->saveAsBtn,SIGNAL(clicked(bool)),this,SLOT(saveAsBtnClicked()));
    connect(ui->resetBtn,SIGNAL(clicked(bool)),this,SLOT(resetBtnClicked()));
    ui->widthBtn->setChecked(true);

    /*
    // Quick example image loading code:
    QTimer *tmr=new QTimer(this);
    connect(tmr,&QTimer::timeout,[=]() {
        QString path="E:/1.jpg";
        this->setWindowState(Qt::WindowMaximized);
        ui->pathBox->setText(path);
        ui->ratioBtn->setChecked(true);
        ui->ratioSpinBox->setValue(0.5);
        ui->methodBox->setCurrentIndex(3);
        loadImageFromPath(path);
        ui->resetZoomBtn->click();
    });
    tmr->setSingleShot(true);
    tmr->start(100);
    */
}

MainWindow::~MainWindow()
{
    free(originalImageData);
    delete ui;
}

void MainWindow::loadImageFromPath(QString path)
{
    if(path.length()==0)
    {
        QMessageBox::critical(this,"Error","No file selected.");
        return;
    }
    QFile f(path);
    if(!f.exists())
    {
        QMessageBox::critical(this,"Error","The selected file does not exist.");
        return;
    }
    image=new QImage(path);
    if(image->isNull())
    {
        QMessageBox::critical(this,"Error","The selected file has an unsupported format.");
        return;
    }
    int imgWidth=image->width(),imgHeight=image->height();
    originalImageWidth=imgWidth;
    originalImageHeight=imgHeight;
    scene->setSceneRect(0,0,imgWidth,imgHeight);
    pixmapItem->setPixmap(QPixmap::fromImage(*image));
    ui->graphicsView->viewport()->update();
    fitToWindow();
    ui->widthSpinBox->setValue(imgWidth);
    ui->heightSpinBox->setValue(imgHeight);
    free(originalImageData);
    originalImageData=qImageToBitmapData(image);
}

void MainWindow::browseBtnClicked()
{
    dialog->exec();
}

void MainWindow::loadBtnClicked()
{
    loadImageFromPath(ui->pathBox->text());
}

void MainWindow::fitToWindow()
{
    if(image==0||image->isNull())
        return;
    int width=image->width();
    int height=image->height();
    QRect rect=ui->graphicsView->contentsRect();
    int availableWidth=rect.width()-ui->graphicsView->verticalScrollBar()->width();
    int availableHeight=rect.height()-ui->graphicsView->horizontalScrollBar()->height();
    if((width-availableWidth)>(height-availableHeight))
        ui->graphicsView->setZoomFactor((decimal_t)((decimal_t)availableWidth)/((decimal_t)width));
    else if(height>availableHeight)
        ui->graphicsView->setZoomFactor((decimal_t)((decimal_t)availableHeight)/((decimal_t)height));
    else
        ui->graphicsView->setZoomFactor(1.0);
}

void MainWindow::resetZoom()
{
    ui->graphicsView->setZoomFactor(1.0);
}

void MainWindow::saveAsBtnClicked()
{
    if(image==0||image->isNull())
        return;

    QString path=QFileDialog::getSaveFileName(this,"Save as...",QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation),"JPG image (*.jpg);;PNG image (*.png);;GIF image (*.gif);;Bitmap (*.bmp)");
    if(path=="")
        return;
    image->save(path,0,100);
}

void MainWindow::dialogFileSelected(QString path)
{
    ui->pathBox->setText(path);
    ui->loadBtn->click();
}

void MainWindow::resizeBtnClicked()
{
    if(image==0||image->isNull())
        return;

    bool useWidth=ui->widthBtn->isChecked();
    bool useHeight=ui->heightBtn->isChecked();
    int method=ui->methodBox->currentIndex();

    if(method==-1)
        return;

    int newWidth;
    int newHeight;
    decimal_t ratio;
    decimal_t rRatio;
    if(useWidth)
    {
        newWidth=ui->widthSpinBox->value();
        ratio=((decimal_t)newWidth)/((decimal_t)originalImageWidth);
        rRatio=(decimal_t)doubleDiv(1.0,ratio);
        newHeight=(int)round(ratio*((decimal_t)originalImageHeight));
    }
    else if(useHeight)
    {
        newHeight=ui->heightSpinBox->value();
        ratio=((decimal_t)newHeight)/((decimal_t)originalImageHeight);
        rRatio=(decimal_t)doubleDiv(1.0,ratio);
        newWidth=(int)round(ratio*((decimal_t)originalImageWidth));
    }
    else // if(useRatio)
    {
        ratio=ui->ratioSpinBox->value();
        rRatio=(decimal_t)doubleDiv(1.0,ratio);
        newWidth=(int)round(ratio*((decimal_t)originalImageWidth));
        newHeight=(int)round(ratio*((decimal_t)originalImageHeight));
    }

    if(method==0) // Nearest neighbor (CUDA)
    {
        uint32_t *newImageData=cudaNearestNeighborResize(originalImageData,originalImageWidth,originalImageHeight,newWidth,newHeight,ratio);
        if(newImageData==0)
        {
            QMessageBox::critical(this,"Error","Resulting image would be too large to process!");
            return;
        }
        delete image;
        image=new QImage((uchar*)newImageData,newWidth,newHeight,QImage::Format_ARGB32);
        scene->setSceneRect(0,0,newWidth,newHeight);
        pixmapItem->setPixmap(QPixmap::fromImage(*image));
        ui->graphicsView->viewport()->update();
        fitToWindow();
    }
    else if(method==1) // Bilinear (CUDA)
    {
        uint32_t *newImageData=cudaBilinearResize(originalImageData,originalImageWidth,originalImageHeight,newWidth,newHeight,ratio);
        if(newImageData==0)
        {
            QMessageBox::critical(this,"Error","Resulting image would be too large to process!");
            return;
        }
        delete image;
        image=new QImage((uchar*)newImageData,newWidth,newHeight,QImage::Format_ARGB32);
        scene->setSceneRect(0,0,newWidth,newHeight);
        pixmapItem->setPixmap(QPixmap::fromImage(*image));
        ui->graphicsView->viewport()->update();
        fitToWindow();
    }
    else if(method==2) // Nearest neighbor
    {
        uint32_t *newImageData=(uint32_t*)malloc(newWidth*newHeight*sizeof(uint32_t));
        for(int y=0;y<newHeight;y++)
        {
            int offset=y*newWidth;
            for(int x=0;x<newWidth;x++)
            {
                int oldX=(int)round(rRatio*x);
                int oldY=(int)round(rRatio*y);
                newImageData[offset+x]=originalImageData[oldY*originalImageWidth+oldX];
            }
        }
        delete image;
        image=new QImage((uchar*)newImageData,newWidth,newHeight,QImage::Format_ARGB32);
        scene->setSceneRect(0,0,newWidth,newHeight);
        pixmapItem->setPixmap(QPixmap::fromImage(*image));
        ui->graphicsView->viewport()->update();
        fitToWindow();
    }
    else if(method==3) // Bilinear
    {
        int xLim=originalImageWidth-1;
        int yLim=originalImageHeight-1;
        uint32_t *newImageData=(uint32_t*)malloc(newWidth*newHeight*sizeof(uint32_t));
        //const bool useAlpha=image->hasAlphaChannel();

        for(int y=0;y<newHeight;y++)
        {
            decimal_t oldYRF=rRatio*y;
            int oldY=(int)floor(oldYRF);
            decimal_t oldYF=(decimal_t)oldY;
            decimal_t yDiff=oldYRF-oldYF;
            decimal_t yDiffR=1.0-yDiff;
            int offset=y*newWidth;

            const bool checkVBounds=oldY<=1||oldY>=originalImageHeight-2;

            for(int x=0;x<newWidth;x++)
            {
                decimal_t oldXRF=rRatio*x;
                int oldX=(int)floor(oldXRF);
                decimal_t oldXF=(decimal_t)oldX;
                decimal_t xDiff=oldXRF-oldXF;
                decimal_t xDiffR=1.0f-xDiff;

                const bool checkBounds=checkVBounds||oldX<=1||oldX>=originalImageWidth-2;

                uint32_t c00,c01,c10,c11;

                if(checkBounds)
                {
                    c00=originalImageData[oldY*originalImageWidth+oldX];
                    c10=originalImageData[oldY*originalImageWidth+(oldX==xLim?oldX:oldX+1)];
                    c01=(oldY==yLim?c00:originalImageData[(oldY+1)*originalImageWidth+oldX]);
                    c11=(oldY==yLim?c10:(oldX==xLim?originalImageData[(oldY+1)*originalImageWidth+oldX]:originalImageData[(oldY+1)*originalImageWidth+(oldX+1)]));
                }
                else
                {
                    c00=originalImageData[oldY*originalImageWidth+oldX];
                    c10=originalImageData[oldY*originalImageWidth+oldX+1];
                    c01=originalImageData[(oldY+1)*originalImageWidth+oldX];
                    c11=originalImageData[(oldY+1)*originalImageWidth+(oldX+1)];
                }

                decimal_t w1=xDiffR*yDiffR;
                decimal_t w2=xDiff*yDiffR;
                decimal_t w3=xDiffR*yDiff;
                decimal_t w4=xDiff*yDiff;

                uint32_t newAlpha=bilinearInterpolate(getAlpha(c00),getAlpha(c01),getAlpha(c10),getAlpha(c11),w1,w2,w3,w4);
                uint32_t newRed=bilinearInterpolate(getRed(c00),getRed(c01),getRed(c10),getRed(c11),w1,w2,w3,w4);
                uint32_t newGreen=bilinearInterpolate(getGreen(c00),getGreen(c01),getGreen(c10),getGreen(c11),w1,w2,w3,w4);
                uint32_t newBlue=bilinearInterpolate(getBlue(c00),getBlue(c01),getBlue(c10),getBlue(c11),w1,w2,w3,w4);

                newImageData[offset+x]=getColor(newAlpha,newRed,newGreen,newBlue);
            }
        }
        delete image;
        image=new QImage((uchar*)newImageData,newWidth,newHeight,QImage::Format_ARGB32);
        scene->setSceneRect(0,0,newWidth,newHeight);
        pixmapItem->setPixmap(QPixmap::fromImage(*image));
        ui->graphicsView->viewport()->update();
        fitToWindow();
    }
    else if(method==4) // Bicubic
    {
        uint32_t *newImageData=(uint32_t*)malloc(newWidth*newHeight*sizeof(uint32_t));
        //const bool useAlpha=image->hasAlphaChannel();

        // Cache cubicWeigh (abbrevated as R) values for every row and column

        // Columns must be precached, rows can be cached on the run

        decimal_t *rColCache=(decimal_t*)malloc(4*newWidth*sizeof(decimal_t));

        for(int x=0;x<newWidth;x++)
        {
            decimal_t oldXRF=rRatio*x;
            int oldX=(int)oldXRF;
            decimal_t oldXF=(decimal_t)oldX;
            decimal_t xDiff=oldXRF-oldXF;
            for(int _x=-1;_x<=2;_x++)
            {
                size_t index=(_x+1)+4*x;
                rColCache[index]=cubicWeigh(((decimal_t)_x)-xDiff);
            }
        }

        for(int y=0;y<newHeight;y++)
        {
            int offset=y*newWidth;
            decimal_t oldYRF=rRatio*y;
            int oldY=(int)oldYRF;
            decimal_t oldYF=(decimal_t)oldY;
            decimal_t yDiff=oldYRF-oldYF;

            bool checkVBounds=oldY<=1||oldY>=originalImageHeight-2;

            decimal_t *rRowCache=(decimal_t*)malloc(4*sizeof(decimal_t));

            for(int _y=-1;_y<=2;_y++)
            {
                rRowCache[_y+1]=cubicWeigh(yDiff-((decimal_t)_y));
            }

            for(int x=0;x<newWidth;x++)
            {
                decimal_t oldXRF=rRatio*x;
                int oldX=(int)oldXRF;

                // This function uses optimized versions of bicubicInterpolate()

                uint32_t newAlpha;
                uint32_t newRed;
                uint32_t newGreen;
                uint32_t newBlue;

                decimal_t sumAlpha=0.0f;
                decimal_t sumRed=0.0f;
                decimal_t sumGreen=0.0f;
                decimal_t sumBlue=0.0f;

                const bool checkBounds=checkVBounds||oldX<=1||oldY>=originalImageHeight-2;

#define calculateColor \
                uint32_t color=originalImageData[ly*originalImageWidth+lx];\
                decimal_t orig=(decimal_t)((uint32_t)((color)>>24)&0xFF);\
                decimal_t prod=rColCache[4*x+_x+1]*rRowCache[_y+1];\
                sumAlpha+=orig*prod;\
                orig=(decimal_t)((uint32_t)((color)>>16)&0xFF);\
                sumRed+=orig*prod;\
                orig=(decimal_t)((uint32_t)((color)>>8)&0xFF);\
                sumGreen+=orig*prod;\
                orig=(decimal_t)((uint32_t)(color)&0xFF);\
                sumBlue+=orig*prod;\

                if(checkBounds)
                {
                    for(int _y=-1;_y<=2;_y++)
                    {
                        for(int _x=-1;_x<=2;_x++)
                        {
                            int lx=oldX+_x,ly=oldY+_y;
                            if(lx<0) lx=0;
                            if(lx>=originalImageWidth) lx=originalImageWidth-1;
                            if(ly<0) ly=0;
                            if(ly>=originalImageHeight) ly=originalImageHeight-1;

                            calculateColor;
                        }
                    }
                }
                else
                {
                    for(int _y=-1;_y<=2;_y++)
                    {
                        for(int _x=-1;_x<=2;_x++)
                        {
                            int lx=oldX+_x,ly=oldY+_y;
                            calculateColor;
                        }
                    }
                }

#undef calculateColor

                newAlpha=(uint32_t)round(sumAlpha);
                newRed=(uint32_t)round(sumRed);
                newGreen=(uint32_t)round(sumGreen);
                newBlue=(uint32_t)round(sumBlue);

                newImageData[offset+x]=getColor(newAlpha,newRed,newGreen,newBlue);
            }
            free(rRowCache);
        }

        free(rColCache);

        delete image;
        image=new QImage((uchar*)newImageData,newWidth,newHeight,QImage::Format_ARGB32);
        scene->setSceneRect(0,0,newWidth,newHeight);
        pixmapItem->setPixmap(QPixmap::fromImage(*image));
        ui->graphicsView->viewport()->update();
        fitToWindow();
    }
}

void MainWindow::resetBtnClicked()
{
    if(image==0||image->isNull())
        return;

    delete image;
    image=new QImage((uchar*)originalImageData,originalImageWidth,originalImageHeight,QImage::Format_ARGB32);
    scene->setSceneRect(0,0,originalImageWidth,originalImageHeight);
    pixmapItem->setPixmap(QPixmap::fromImage(*image));
    ui->graphicsView->viewport()->update();
    fitToWindow();
}

uint32_t *MainWindow::qImageToBitmapData(QImage *image)
{
    int32_t width=image->width();
    int32_t height=image->height();
    uint32_t *out=(uint32_t*)malloc(width*height*sizeof(uint32_t));
    for(int32_t y=0;y<height;y++)
    {
        int32_t offset=y*width;
        QRgb *scanLine=(QRgb*)image->scanLine(y); // Do not free!
        for(int32_t x=0;x<width;x++)
        {
            QRgb color=scanLine[x];
            uint32_t alpha=qAlpha(color);
            uint32_t red=qRed(color);
            uint32_t green=qGreen(color);
            uint32_t blue=qBlue(color);
            out[offset+x]=(alpha<<24)|(red<<16)|(green<<8)|blue;
        }
        // Do not free "scanLine"!
    }
    return out;
}

decimal_t MainWindow::bilinearInterpolate(decimal_t c00, decimal_t c10, decimal_t c01, decimal_t c11, decimal_t w1, decimal_t w2, decimal_t w3, decimal_t w4)
{
    return w1*c00+w2*c01+w3*c10+w4*c11;
}

decimal_t MainWindow::bicubicInterpolate(int ix, int iy, decimal_t dx, decimal_t dy, size_t shift)
{
    decimal_t sum=0.0f;
    for(int _y=-1;_y<=2;_y++)
    {
        for(int _x=-1;_x<=2;_x++)
        {
            int x=ix+_x,y=iy+_y;
            if(x<0) x=0;
            if(x>=originalImageWidth) x=originalImageWidth-1;
            if(y<0) y=0;
            if(y>=originalImageHeight) y=originalImageHeight-1;
            decimal_t orig=(decimal_t)((uint32_t)((originalImageData[y*originalImageWidth+x])>>shift)&0xFF);
            sum+=orig*cubicWeigh(((decimal_t)_x)-dx)*cubicWeigh(dy-((decimal_t)_y));
        }
    }
    return sum;
}

decimal_t MainWindow::cubicWeigh(decimal_t x)
{
    decimal_t ratio=(decimal_t)(1.0/6.0);
    return ratio*(ifGTZeroArg((x+2.0f),pow((x+2.0f),3.0f))-4.0f*ifGTZeroArg(x+1.0f,pow((x+1.0f),3.0f))+6.0f*ifGTZeroArg(x,pow(x,3.0f))-4.0f*ifGTZeroArg(x-1.0f,pow((x-1.0f),3.0f)));
}
