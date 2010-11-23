#ifndef UIITEM_H
#define UIITEM_H

#include <QtGui>
#include "gameengine.h"

class UiItem
    : public QObject
    , public QGraphicsItem
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)
public:
    UiItem(char, GameEngine*);

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *,
               QWidget *);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
//signals:
//    void changedPic(GameSquare *);
private:
    char id;
    int xSize;
    int ySize;
    QString imageFile;
    GameEngine *engine;
};

#endif // UIITEM_H
