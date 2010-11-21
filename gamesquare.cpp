#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>
#include <QString>
#include <QPixmap>
#include "gamesquare.h"

GameSquare::GameSquare(char token) : current_letter(token)
{
}

QRectF GameSquare::boundingRect() const
{
    return QRectF(-50,-50,50,50);
}

void GameSquare::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QString fileName;
    if (current_letter == 'X')
        fileName = "images/x.png";
    else
        fileName = "images/o.png";
    QPixmap token(fileName, 0, Qt::AutoColor);
    painter->drawPixmap(0,0,token);
}

QPainterPath GameSquare::shape () const
{
    QPainterPath path;
    path.addRect(-50,-50,50,50);
    return path;
}
