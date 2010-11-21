#ifndef GAMESQUARE_H
#define GAMESQUARE_H

#include <QGraphicsItem>

class GameSquare
    : public QGraphicsItem
{
public:
    GameSquare(char);

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *,
               QWidget *);

private:
    char current_letter;
};

#endif // GAMESQUARE_H
