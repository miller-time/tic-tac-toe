// Copyright 2010 by Russell Miller
// Please see included license information in file
// COPYING or visit
// http://opensource.org/licenses/mit-license.php


#include <QtGui>
#include <QMessageBox>
#include <QDebug>
#include "tictactoe.hh"
#include "gamesquare.hh"
#include "gamegrid.hh"
#include "uiitem.hh"

TicTacController::TicTacController(QWidget *parent)
    : QWidget (parent)
{

    // initialize the scene
    scene.setSceneRect(0,0,500,300);
    scene.setItemIndexMethod(QGraphicsScene::NoIndex);

    // use the restart function to initialize objects to the scene
    restart();
}

void
TicTacController::restart()
{
    // not selecting anything initially
    current_selection = ' ';
    // clear background gameboard
    engine.reset();
    // remove anything added to scene
    scene.clear();

    // (re)add all objects to scene

    // draw the squares
    int i;
    for(i = 1; i < 10; i++)
        scene.addItem(addToken(' ', i));

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
    arrow->setPos(340,120);
    scene.addItem(arrow);
    UiItem *whoTurn = new UiItem('w', &engine);
    whoTurn->setPos(370,120);
    scene.addItem(whoTurn);
    connect(this, SIGNAL(updateUI()), whoTurn, SLOT(needToUpdate()));

    // quit button
    UiItem *quit = new UiItem('q', &engine);
    quit->setPos(450,250);
    scene.addItem(quit);
    connect(quit, SIGNAL(clicked()), this, SLOT(exitProgram()));
}

QGraphicsScene *
TicTacController::getScene()
{
    return &scene;
}

void
TicTacController::onTokenChange(GameSquare *square)
{
    char token = square->getToken();
    int location = square->getLoc();
    engine.update(token, location);
    engine.changeSelect(' ');
    engine.changeTurn();
/*
    QString allSquares = engine.tokenstring();
    qDebug() << allSquares;
*/
    emit updateUI();
    char status = engine.isOver();
    switch (status) {
    case 'd':       // code for "D"raw
        QMessageBox::information(this, tr("Game Over"), tr("Draw"));
        restart();
        break;
    case 'x':       // code for "X" Wins
        QMessageBox::information(this, tr("Game Over"), tr("X Wins!"));
        restart();
        break;
    case 'o':       // code for "O" Wins
        QMessageBox::information(this, tr("Game Over"), tr("O Wins!"));
        restart();
        break;
    case 'n':       // code for "N"ot over
        // do nothing
    default:
        break;
    }
}

void
TicTacController::onSelectChange(char toWhat)
{
    engine.changeSelect(toWhat);
}

void
TicTacController::exitProgram()
{
    exit(0);
}

GameSquare *
TicTacController::addToken(char token, int location)
{
    int x,y;
    // determine coordinate from location
    switch (location) {
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
