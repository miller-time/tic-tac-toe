#include <QtGui>

#include "tictactoe.h"
#include "gamesquare.h"
#include "gamegrid.h"

GameSquare *addToken(char token, int location)
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

int main(int argc, char *argv[])
{
    // make the program a Q Application
    QApplication app(argc, argv);

    // Start a scene
    QGraphicsScene scene;
    scene.setSceneRect(0,0,300,300);
    scene.setItemIndexMethod(QGraphicsScene::NoIndex);

    int i;
    for(i = 1; i < 10; i++)
    {
        scene.addItem(addToken('X', i));
    }
/*
    // Make the 9 Tic Tac Toe squares, add them to scene
    GameSquare *square_1 = new GameSquare;
    square_1->setPos(0,0);
    scene.addItem(square_1);

    GameSquare *square_2 = new GameSquare;
    square_2->setPos(100,0);
    scene.addItem(square_2);

    GameSquare *square_3 = new GameSquare;
    square_3->setPos(200,0);
    scene.addItem(square_3);

    GameSquare *square_4 = new GameSquare;
    square_4->setPos(0,100);
    scene.addItem(square_4);

    GameSquare *square_5 = new GameSquare;
    square_5->setPos(100,100);
    scene.addItem(square_5);

    GameSquare *square_6 = new GameSquare;
    square_6->setPos(200,100);
    scene.addItem(square_6);

    GameSquare *square_7 = new GameSquare;
    square_7->setPos(0,200);
    scene.addItem(square_7);

    GameSquare *square_8 = new GameSquare;
    square_8->setPos(100,200);
    scene.addItem(square_8);

    GameSquare *square_9 = new GameSquare;
    square_9->setPos(200,200);
    scene.addItem(square_9);
*/

    GameGrid *grid = new GameGrid;
    grid->setPos(0,0);
    scene.addItem(grid);

    // Make the view that displays the scene
    QGraphicsView view(&scene);
    view.setRenderHint(QPainter::Antialiasing);
    view.setCacheMode(QGraphicsView::CacheBackground);
    view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view.setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "Tic Tac Toe"));
    view.show();

    return app.exec();

}
