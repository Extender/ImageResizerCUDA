#include "graphicssceneex.h"

GraphicsSceneEx::GraphicsSceneEx(QObject *parent) :
    QGraphicsScene(parent)
{
}

void GraphicsSceneEx::dragEnterEvent(QGraphicsSceneDragDropEvent *e)
{
    QGraphicsScene::dragEnterEvent(e);
    if(((GraphicsViewEx*)parent())->acceptDrops())
    {
        if(e->mimeData()->hasUrls())
        {
            QString u=e->mimeData()->urls().first().toString().toLower();
            if(u.endsWith(".tif")||u.endsWith(".tiff"))
            {
                e->acceptProposedAction();
                e->accept();
            }
        }
    }
}

void GraphicsSceneEx::dragLeaveEvent(QGraphicsSceneDragDropEvent *e)
{
    QGraphicsScene::dragLeaveEvent(e);
}

void GraphicsSceneEx::dragMoveEvent(QGraphicsSceneDragDropEvent *e)
{
    QGraphicsScene::dragMoveEvent(e);
    if(((GraphicsViewEx*)parent())->acceptDrops())
    {
        if(e->mimeData()->hasUrls())
        {
            QString u=e->mimeData()->urls().first().toString().toLower();
            if(u.endsWith(".tif")||u.endsWith(".tiff"))
            {
                e->acceptProposedAction();
                e->accept();
            }
        }
    }
}

void GraphicsSceneEx::dropEvent(QGraphicsSceneDragDropEvent *e)
{
    QGraphicsScene::dropEvent(e);
    if(((GraphicsViewEx*)parent())->acceptDrops())
    {
        if(e->mimeData()->hasUrls())
        {
            QString u=e->mimeData()->urls().first().toString().toLower();
            if(u.endsWith(".tif")||u.endsWith(".tiff"))
            {
                QDropEvent *dE=new QDropEvent(e->pos(),e->dropAction(),e->mimeData(),e->buttons(),e->modifiers(),e->type());
                ((GraphicsViewEx*)parent())->dropEvent(dE);
            }
        }
    }
}
