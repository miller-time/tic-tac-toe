// Copyright 2010 by Russell Miller
// Please see included license information in file
// COPYING or visit
// http://opensource.org/licenses/mit-license.php

// gamegrid.hh
// GameGrid is a class inheriting from QGraphicsItem. This means its sole
// purpose is to be added to a QGraphicsScene. This is a very simple class
// that is only used once and draws 2 horizontal lines and 2 vertical lines
// to play Tic Tac Toe within.

#ifndef _WF_GAMEGRID_H
#define _WF_GAMEGRID_H

#include <QGraphicsItem>

class GameGrid
    : public QGraphicsItem
{
public:
    GameGrid();

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *,
               QWidget *);

};

#endif // GAMEGRID_H
