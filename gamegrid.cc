// Copyright 2010 by Russell Miller
// Please see included license information in file
// COPYING or visit
// http://opensource.org/licenses/mit-license.php

// gamegrid.cc
// GameGrid's implementation

#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>
#include <QString>
#include <QPixmap>
#include "gamegrid.hh"

GameGrid::GameGrid()
{
}

// 1st requirement for creating custom QGraphicsItem.
// Describes a rectangular shape around the object
QRectF
GameGrid::boundingRect() const
{
    return QRectF(0,0,300,300);
}

// 2nd requirement. This is what is drawn on the screen.
// The grid just needs 4 lines.
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

// 3rd requirement. Not sure what the difference is between
// this and boundingRect
QPainterPath
GameGrid::shape () const
{
    QPainterPath path;
    path.addRect(0,0,300,300);
    return path;
}
