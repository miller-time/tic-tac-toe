#include <QtGui>

#include "tictactoe.h"
#include "gamesquare.h"
#include "gamegrid.h"

TicTacController::TicTacController()
{
    // initialize the scene
    scene.setSceneRect(0,0,300,300);
    scene.setItemIndexMethod(QGraphicsScene::NoIndex);

    // draw the squares
    int i;
    for(i = 1; i < 10; i++)
    {
        scene.addItem(addToken(' ', i));
    }

    // draw the grid
    GameGrid *grid = new GameGrid;
    grid->setPos(0,0);
    scene.addItem(grid);

}

QGraphicsScene * TicTacController::getScene()
{
    return &scene;
}

GameSquare * TicTacController::addToken(char token, int location)
{
    int x,y;
    // determine coordinate from location
    switch (location)
    {
        case 1:
            x = 0;
            y = 0;
            break;
        case 2:
            x = 100;
            y = 0;
            break;
        case 3:
            x = 200;
            y = 0;
            break;
        case 4:
            x = 0;
            y = 100;
            break;
        case 5:
            x = 100;
            y = 100;
            break;
        case 6:
            x = 200;
            y = 100;
            break;
        case 7:
            x = 0;
            y = 200;
            break;
        case 8:
            x = 100;
            y = 200;
            break;
        case 9:
            x = 200;
            y = 200;
            break;
        default:
            x = 300;
            y = 300;
    }
    GameSquare *newsquare = new GameSquare(token);
    newsquare->setPos(x,y);
    return newsquare;
}
