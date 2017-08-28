#ifndef GRAPHICSVIEWEX_H
#define GRAPHICSVIEWEX_H

#include <QGraphicsView>
#include <QWheelEvent>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QDebug>
#include <QScrollBar>
#include "graphicssceneex.h"

class GraphicsViewEx : public QGraphicsView
{
    Q_OBJECT
public:
    bool defaultHandlers;
    double zoomFactor;
    bool dragging;
    bool newItem;
    QPoint startPoint;
    QMap<QGraphicsItem*,QPoint> *posMap;
    QPoint offset;
    QGraphicsRectItem *newRectItem;

    GraphicsViewEx(QWidget *parent=0);
    void wheelEvent(QWheelEvent *e);
    void enterEvent(QEvent *e);
    void leaveEvent(QEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void mouseDoubleClickEvent(QMouseEvent *e);
    void dropEvent(QDropEvent *e); // Needed! Gets called by GraphicsSceneEx!
    void toggleNewItem();
    void setZoomFactor(double newZoomFactor);
    inline void resetZoom();

signals:
    void wheelEx(QWheelEvent *e);
    void mouseEnterEx(QEvent *e);
    void mouseLeaveEx(QEvent *e);
    void mouseMoveEx(QMouseEvent *e);
    void mouseDownEx(QMouseEvent *e);
    void mouseUpEx(QMouseEvent *e);
    void mouseDoubleClickEx(QMouseEvent *e);
    void dropEx(QDropEvent *e);
    void itemAdded(QGraphicsRectItem *rectItem);
};

#endif // GRAPHICSVIEWEX_H
