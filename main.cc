// Copyright 2010 by Russell Miller
// Please see included license information in file
// COPYING or visit
// http://opensource.org/licenses/mit-license.php

// main.cc
// This is the main entry point of the TicTacToe program that instantiates
// a game controller, and shows its board in a graphics scene, provided
// by the Qt Library.

#include <QtGui>
#include "tictactoe.hh"

int
main(int argc, char *argv[])
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
