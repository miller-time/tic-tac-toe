#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>
#include "gamesquare.h"

GameSquare::GameSquare()
{
}

QRectF GameSquare::boundingRect() const
{
    return QRectF(-50,-50,50,50);
}

void GameSquare::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setBrush(Qt::black);
    painter->drawEllipse(-200,-200,200,200);
}

QPainterPath GameSquare::shape () const
{
    QPainterPath path;
    path.addRect(-200,-200,200,200);
    return path;
}
