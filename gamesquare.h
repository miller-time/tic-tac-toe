#ifndef GAMESQUARE_H
#define GAMESQUARE_H

#include <QGraphicsItem>
#include <QObject>

class GameSquare
    : public QObject
    , public QGraphicsItem
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)
public:
    GameSquare(char, int);

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
};

#endif // GAMESQUARE_H
