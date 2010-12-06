// Copyright 2010 by Russell Miller
// Please see included license information in file
// COPYING or visit
// http://opensource.org/licenses/mit-license.php

// tictactoe.hh
// TicTacController is a class that is in charge of everything.
// It has the entire scene instantiated, along with the behind the scenes
// game engine, and uses communication back and forth with both to keep
// everything up-to-date.

#ifndef _WF_TICTACCONTROLLER_H
#define _WF_TICTACCONTROLLER_H

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
    void updateUI();        // update certain controls in the main window
private:
    QGraphicsScene scene;   // the shinies
    GameEngine engine;      // behind the scenes
};

#endif // TICTACTOE_H
