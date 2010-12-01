// Copyright 2010 by Russell Miller
// Please see included license information in file
// COPYING or visit
// http://opensource.org/licenses/mit-license.php


#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>
#include <QString>
#include <QPixmap>
#include "gamegrid.hh"

GameGrid::GameGrid()
{
}

QRectF
GameGrid::boundingRect() const
{
    return QRectF(0,0,300,300);
}

void
GameGrid::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    // draw the lines for the tictactoe grid
    QLineF first_vert(0,99, 300,99);
    painter->drawLine(first_vert);
    QLineF second_vert(0,199, 300,199);
    painter->drawLine(second_vert);
    QLineF first_horiz(99,0, 99,300);
    painter->drawLine(first_horiz);
    QLineF second_horiz(199,0, 199,300);
    painter->drawLine(second_horiz);

}

QPainterPath
GameGrid::shape () const
{
    QPainterPath path;
    path.addRect(0,0,300,300);
    return path;
}
