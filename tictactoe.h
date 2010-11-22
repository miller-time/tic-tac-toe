#ifndef TICTACCONTROLLER_H
#define TICTACCONTROLLER_H

#include <QGraphicsScene>
#include "gamesquare.h"
#include "gamegrid.h"

class TicTacController
{

public:
    TicTacController();
    GameSquare *addToken(char, int);
    QGraphicsScene * getScene();
private:
    GameGrid *grid;
    QGraphicsScene scene;

};

#endif // TICTACTOE_H
