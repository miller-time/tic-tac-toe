#ifndef GAMEGRID_H
#define GAMEGRID_H

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
