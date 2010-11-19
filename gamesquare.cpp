#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>
#include <QString>
#include <QPixmap>
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
    QString xFile = "images/x.png";
    QPixmap xPiece(xFile, 0, Qt::AutoColor);
    painter->drawPixmap(0,0,xPiece);
}

QPainterPath GameSquare::shape () const
{
    QPainterPath path;
    path.addRect(-50,-50,50,50);
    return path;
}
