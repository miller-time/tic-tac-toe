// Copyright 2010 by Russell Miller
// Please see included license information in file
// COPYING or visit
// http://opensource.org/licenses/mit-license.php

// gameengine.hh
// GameEngine is a class designed to handle the behind the scenes work of
// a Tic Tac Toe game. It's really a central location for the game state.
// The current turn, the state of each square on the board, and whether
// or not the game is over, are all determined by this class.

#ifndef _WF_GAMEENGINE_H
#define _WF_GAMEENGINE_H

#include <QString>

class GameEngine
{

public:
    GameEngine();
    void changeTurn();
    char isOver();
    char whoseTurnIsIt();
    void update(char, int);
    char whatIsSelected();
    void changeSelect(char);
    void reset();
    QString tokenstring();
private:
    bool drawn();
    char whoseTurn;         // keep track of whose turn it is
    char selected;          // keep track of what piece is selected
    char tokens[9];         // the state of each square on the board
};
#endif
