#include <QtGui>
#include <QMessageBox>
#include "tictactoe.h"
#include "gamesquare.h"
#include "gamegrid.h"
#include "uiitem.h"

TicTacController::TicTacController(QWidget *parent)
    : QWidget (parent)
{
    current_selection = ' ';

    // initialize the scene
    scene.setSceneRect(0,0,500,300);
    scene.setItemIndexMethod(QGraphicsScene::NoIndex);

    // draw the squares
    int i;
    for(i = 1; i < 10; i++)
    {
        scene.addItem(addToken(' ', i));
    }

    // draw the grid
    GameGrid *grid = new GameGrid;
    grid->setPos(0,0);
    scene.addItem(grid);

    // selection indicators
    UiItem *selectX = new UiItem('x', &engine);
    selectX->setPos(300,0);
    scene.addItem(selectX);
    connect(selectX, SIGNAL(selectChanged(char)), this, SLOT(onSelectChange(char)));
    connect(this, SIGNAL(updateUI()), selectX, SLOT(needToUpdate()));
    UiItem *selectO = new UiItem('o', &engine);
    selectO->setPos(400,0);
    scene.addItem(selectO);
    connect(selectO, SIGNAL(selectChanged(char)), this, SLOT(onSelectChange(char)));
    connect(this, SIGNAL(updateUI()), selectO, SLOT(needToUpdate()));

    // turn indicator
    UiItem *arrow = new UiItem('a', &engine);
    arrow->setPos(300,100);
    scene.addItem(arrow);
    UiItem *whoTurn = new UiItem('w', &engine);
    whoTurn->setPos(350,100);
    scene.addItem(whoTurn);

    // quit button
    UiItem *quit = new UiItem('q', &engine);
    quit->setPos(400,210);
    scene.addItem(quit);
    connect(quit, SIGNAL(clicked()), this, SLOT(exitProgram()));
}

void TicTacController::restart()
{
    current_selection = ' ';

    engine.reset();
    scene.clear();
    int i;
    for(i = 1; i < 10; i++)
    {
        scene.addItem(addToken(' ', i));
    }
    GameGrid *grid = new GameGrid;
    grid->setPos(0,0);
    scene.addItem(grid);

    // selection indicators
    UiItem *selectX = new UiItem('x', &engine);
    selectX->setPos(300,0);
    scene.addItem(selectX);
    connect(selectX, SIGNAL(selectChanged(char)), this, SLOT(onSelectChange(char)));
    connect(this, SIGNAL(updateUI()), selectX, SLOT(needToUpdate()));
    UiItem *selectO = new UiItem('o', &engine);
    selectO->setPos(400,0);
    scene.addItem(selectO);
    connect(selectO, SIGNAL(selectChanged(char)), this, SLOT(onSelectChange(char)));
    connect(this, SIGNAL(updateUI()), selectO, SLOT(needToUpdate()));

    // turn indicator
    UiItem *arrow = new UiItem('a', &engine);
    arrow->setPos(300,100);
    scene.addItem(arrow);
    UiItem *whoTurn = new UiItem('w', &engine);
    whoTurn->setPos(350,100);
    scene.addItem(whoTurn);

    // quit button
    UiItem *quit = new UiItem('q', &engine);
    quit->setPos(400,210);
    scene.addItem(quit);
    connect(quit, SIGNAL(clicked()), this, SLOT(exitProgram()));
}

QGraphicsScene * TicTacController::getScene()
{
    return &scene;
}

void TicTacController::onTokenChange(GameSquare *square)
{
    char token = square->getToken();
    int location = square->getLoc();
    engine.update(token, location);
    engine.changeSelect(' ');
    engine.changeTurn();
    emit updateUI();
    if (engine.isOver())
    {
        QMessageBox::information(this, tr("Game Over"), tr("Game Over"));
        restart();
        int i;
        for (i = 1; i < 10; i++)
            engine.update('-', i);
    }
}

void TicTacController::onSelectChange(char toWhat)
{
    engine.changeSelect(toWhat);
}

void TicTacController::exitProgram()
{
    exit(0);
}

GameSquare * TicTacController::addToken(char token, int location)
{
    int x,y;
    // determine coordinate from location
    switch (location)
    {
        case 1:
            x = 0;
            y = 0;
            break;
        case 2:
            x = 100;
            y = 0;
            break;
        case 3:
            x = 200;
            y = 0;
            break;
        case 4:
            x = 0;
            y = 100;
            break;
        case 5:
            x = 100;
            y = 100;
            break;
        case 6:
            x = 200;
            y = 100;
            break;
        case 7:
            x = 0;
            y = 200;
            break;
        case 8:
            x = 100;
            y = 200;
            break;
        case 9:
            x = 200;
            y = 200;
            break;
        default:
            x = 300;
            y = 300;
    }
    GameSquare *newsquare = new GameSquare(token, location, &engine);
    newsquare->setPos(x,y);
    connect(newsquare, SIGNAL(tokenChange(GameSquare*)), this, SLOT(onTokenChange(GameSquare *)));
    return newsquare;
}
