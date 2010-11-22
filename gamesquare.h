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
    void changeToken();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    char current_letter;
};

#endif // GAMESQUARE_H
