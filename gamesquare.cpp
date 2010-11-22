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
    return QRectF(0,0,100,100);
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
    path.addRect(0,0,100,100);
    return path;
}

void GameSquare::changeToken()
{
    if (current_letter == 'X')
        current_letter = 'O';
    else
        current_letter = 'X';
}

void GameSquare::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->changeToken();
    QRect target(0,0,100,100);
    update(target);
}
