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
    char whatIsSelected();
    void changeSelect(char);
private:
    char whoseTurn;
    char selected;
    char tokens[9];
};
#endif
