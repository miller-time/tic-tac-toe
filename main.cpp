#include <QtGui>
#include "tictactoe.h"

int main(int argc, char *argv[])
{
    // make the program a Q Application
    QApplication app(argc, argv);

    TicTacController controller;

    // Make the view that displays the scene
    QGraphicsView view(controller.getScene());
    view.setRenderHint(QPainter::Antialiasing);
    view.setCacheMode(QGraphicsView::CacheBackground);
    view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view.setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "Tic Tac Toe"));
    view.show();

    return app.exec();

}
