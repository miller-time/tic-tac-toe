// Copyright 2010 by Russell Miller
// Please see included license information in file
// COPYING or visit
// http://opensource.org/licenses/mit-license.php


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
