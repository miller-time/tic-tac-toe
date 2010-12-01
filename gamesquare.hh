// Copyright 2010 by Russell Miller
// Please see included license information in file
// COPYING or visit
// http://opensource.org/licenses/mit-license.php


#ifndef GAMESQUARE_H
#define GAMESQUARE_H

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
    void tokenChange(GameSquare *);
private:
    char current_letter;
    int location;
    GameEngine *engine;
};

#endif // GAMESQUARE_H
