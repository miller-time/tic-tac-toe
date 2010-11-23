#include "gameengine.h"

GameEngine::GameEngine():whoseTurn('X')
{
    int i;
    for (i = 0; i < 9; i++)
        tokens[i] = '-';
}

void GameEngine::changeTurn()
{
    if (whoseTurn == 'X')
        whoseTurn = 'O';
    else
        whoseTurn = 'X';
}

bool GameEngine::isOver()
{
    int tokenvalues[9];
    int i;
    for (i = 0; i < 10; i++)
    {
        switch (tokens[i])
        {
            case '-':
                tokenvalues[i] = 0;
                break;
            case 'X':
                tokenvalues[i] = -1;
                break;
            case 'O':
                tokenvalues[i] = 1;
                break;
        }
    }
    int rowvalues[8];
    //top row
    rowvalues[0] = tokenvalues[0] +
                   tokenvalues[1] +
                   tokenvalues[2];
    //left column
    rowvalues[1] = tokenvalues[0] +
                   tokenvalues[3] +
                   tokenvalues[6];
    // \ diagonal
    rowvalues[2] = tokenvalues[0] +
                   tokenvalues[4] +
                   tokenvalues[8];
    //2nd row
    rowvalues[3] = tokenvalues[3] +
                   tokenvalues[4] +
                   tokenvalues[5];
    //2nd column
    rowvalues[4] = tokenvalues[1] +
                   tokenvalues[4] +
                   tokenvalues[7];
    //3rd row
    rowvalues[5] = tokenvalues[6] +
                   tokenvalues[7] +
                   tokenvalues[8];
    //3rd column
    rowvalues[6] = tokenvalues[2] +
                   tokenvalues[5] +
                   tokenvalues[8];
    // / diagonal
    rowvalues[7] = tokenvalues[2] +
                   tokenvalues[4] +
                   tokenvalues[6];

    bool returnval = false;
    for (i = 0; i < 9; i++)
    {
        if ((rowvalues[i] == -3) ||
            (rowvalues[i] == 3))
            returnval = true;
    }
    return returnval;
}

void GameEngine::update(char t, int l)
{
    tokens[l - 1] = t;
}
