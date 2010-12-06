// Copyright 2010 by Russell Miller
// Please see included license information in file
// COPYING or visit
// http://opensource.org/licenses/mit-license.php

// gamesquare.hh
// GameSquare is a class inheriting from QGraphicsItem. It is a custom
// graphics class I designed to draw X's and O's on the game board. They
// are slightly smarter than that, though. When clicked on, they check
// some game state information and update themselves. Then they tell the game
// board class what just happened.

#ifndef _WF_GAMESQUARE_H
#define _WF_GAMESQUARE_H

#include <QGraphicsItem>
#include <QObject>
#include "gameengine.hh"

class GameSquare
    : public QObject
    , public QGraphicsItem
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)
public:
    GameSquare(char, int, GameEngine*);

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *,
               QWidget *);
    void changeToken();
    char getToken();
    int getLoc();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
signals:
    void tokenChange(GameSquare *);   // here's how the board knows what happened
private:
    char current_letter;              // what is currently displayed on this square
    int location;                     // which square this is
    GameEngine *engine;               // the direct contact to centralized game info
};

#endif // GAMESQUARE_H
