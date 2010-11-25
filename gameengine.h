#ifndef GAMEENGINE_H
#define GAMEENGINE_H

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
    char whoseTurn;
    char selected;
    char tokens[9];
};
#endif
