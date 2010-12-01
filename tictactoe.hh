// Copyright 2010 by Russell Miller
// Please see included license information in file
// COPYING or visit
// http://opensource.org/licenses/mit-license.php


#ifndef TICTACCONTROLLER_H
#define TICTACCONTROLLER_H

#include <QtGui>
#include "gamesquare.hh"
#include "gamegrid.hh"
#include "gameengine.hh"

class TicTacController : public QWidget
{
    Q_OBJECT
public:
    TicTacController(QWidget *parent = 0);
    void restart();
    GameSquare *addToken(char, int);
    QGraphicsScene * getScene();
public slots:
    void onTokenChange(GameSquare *);
    void exitProgram();
    void onSelectChange(char);
signals:
    void updateUI();
private:
    GameGrid *grid;
    QGraphicsScene scene;
    GameEngine engine;
    char current_selection;
};

#endif // TICTACTOE_H
