// Copyright 2010 by Russell Miller
// Please see included license information in file
// COPYING or visit
// http://opensource.org/licenses/mit-license.php


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
    int drawn();
    char whoseTurn;
    char selected;
    char tokens[9];
};
#endif
