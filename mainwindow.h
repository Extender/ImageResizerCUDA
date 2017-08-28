#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <stdint.h>
#include <QMainWindow>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QStandardPaths>
#include <QGraphicsPixmapItem>
#include <QStringList>
#include <QTimer>

#include "colordefs.h"
#include "decimal.h"

// BEGIN FORWARD-DECLARATIONS OF CUDA FUNCTIONS

uint32_t *cudaNearestNeighborResize(uint32_t *origImageData,int origImgWidth,int origImgHeight,int newImgWidth,int newImgHeight,decimal_t resizeRatio);
uint32_t *cudaBilinearResize(uint32_t *origImageData,int origImgWidth,int origImgHeight,int newImgWidth,int newImgHeight,decimal_t resizeRatio);

// END FORWARD-DECLARATIONS OF CUDA FUNCTIONS

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QFileDialog *dialog;
    QImage *image;
    QGraphicsScene *scene;
    QGraphicsPixmapItem *pixmapItem;
    int originalImageWidth,originalImageHeight;
    uint32_t *originalImageData;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void loadImageFromPath(QString path);
    static uint32_t *qImageToBitmapData(QImage *image);
    inline decimal_t bilinearInterpolate(decimal_t c00, decimal_t c10, decimal_t c01, decimal_t c11, decimal_t w1, decimal_t w2, decimal_t w3, decimal_t w4);
    inline decimal_t bicubicInterpolate(int ix, int iy, decimal_t dx, decimal_t dy, size_t shift);
    inline static decimal_t cubicWeigh(decimal_t x);

public slots:
    void browseBtnClicked();
    void loadBtnClicked();
    void fitToWindow();
    void resetZoom();
    void saveAsBtnClicked();
    void dialogFileSelected(QString path);
    void resizeBtnClicked();
    void resetBtnClicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
