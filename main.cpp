#include <QtGui>

#include "tictactoe.h"
#include "gamesquare.h"

int main(int argc, char *argv[])
{
    // make the program a Q Application
    QApplication app(argc, argv);

    // Start a scene
    QGraphicsScene scene;
    scene.setSceneRect(0,0,300,300);
    scene.setItemIndexMethod(QGraphicsScene::NoIndex);

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

    // Make the view that displays the scene
    QGraphicsView view(&scene);
    view.setRenderHint(QPainter::Antialiasing);
    view.setCacheMode(QGraphicsView::CacheBackground);
    view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view.setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "Tic Tac Toe"));
    view.show();

    return app.exec();

}
