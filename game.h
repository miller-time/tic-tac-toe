#ifndef GAME_H
#define GAME_H
class Game
{

public:
    Game();
    void showBoard();
    bool takeTurn();
    void changeTurn();
    void start();
    bool isOver();
private:
    char whoseTurn;
    char tokens[9];
};
#endif
