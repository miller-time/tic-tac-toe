#ifndef TICTACCONTROLLER_H
#define TICTACCONTROLLER_H

#include <QtGui>
#include "gamesquare.h"
#include "gamegrid.h"
#include "gameengine.h"

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
