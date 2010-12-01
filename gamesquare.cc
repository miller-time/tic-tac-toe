// Copyright 2010 by Russell Miller
// Please see included license information in file
// COPYING or visit
// http://opensource.org/licenses/mit-license.php


#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>
#include <QString>
#include <QPixmap>
#include <QDebug>
#include "gamesquare.hh"
#include "gameengine.hh"

GameSquare::GameSquare(char token, int loc, GameEngine *eng)
    : current_letter(token), location(loc), engine(eng)
{
}

QRectF
GameSquare::boundingRect() const
{
    return QRectF(0,0,100,100);
}

void
GameSquare::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QString fileName;
    if (current_letter == 'X')
    {
        fileName = ":/images/x.png";
    }
    else  if (current_letter == 'O')
    {
        fileName = ":/images/o.png";
    }
    else
        return;
    QPixmap token(fileName, 0, Qt::AutoColor);
    painter->drawPixmap(0,0,token);
}

QPainterPath
GameSquare::shape () const
{
    QPainterPath path;
    path.addRect(0,0,100,100);
    return path;
}

void
GameSquare::changeToken()
{
    if (current_letter == ' ')
    {
        current_letter = engine->whatIsSelected();
    }
}

char
GameSquare::getToken()
{
    return current_letter;
}

int
GameSquare::getLoc()
{
    return location;
}

void
GameSquare::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (!event)
        return;
    changeToken();
    QRect target(0,0,100,100);
    update(target);
    emit tokenChange(this);
}
