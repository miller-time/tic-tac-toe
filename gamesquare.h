#ifndef GAMESQUARE_H
#define GAMESQUARE_H

#include <QGraphicsItem>

class GameSquare
    : public QGraphicsItem
{
public:
    GameSquare();

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *,
               QWidget *);

private:
    QString current_letter;
};

#endif // GAMESQUARE_H
