#ifndef GAMEENGINE_H
#define GAMEENGINE_H
class GameEngine
{

public:
    GameEngine();
    void changeTurn();
    bool isOver();
    char whoseTurnIsIt();
    void update(char, int);
private:
    char whoseTurn;
    char tokens[9];
};
#endif
