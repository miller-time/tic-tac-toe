#ifndef TICTACCONTROLLER_H
#define TICTACCONTROLLER_H

#include <QtGui>
#include "gamesquare.h"
#include "gamegrid.h"
#include "gameengine.h"

class TicTacController : public QWidget
{
    Q_OBJECT
public:
    TicTacController(QWidget *parent = 0);
    GameSquare *addToken(char, int);
    QGraphicsScene * getScene();
public slots:
    void onTokenChange(GameSquare *);
private:
    GameGrid *grid;
    QGraphicsScene scene;
    GameEngine engine;
};

#endif // TICTACTOE_H
