#include "gameengine.h"

GameEngine::GameEngine():whoseTurn('X'),selected(' ')
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

char GameEngine::whatIsSelected()
{
    return selected;
}

void GameEngine::changeSelect(char toWhat)
{
    selected = toWhat;
}

bool GameEngine::isOver()
{
    // count squares
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
    // get values for each row, column, diagonal
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
    // check for 3 in a row
    for (i = 0; i < 8; i++)
    {
        if ((rowvalues[i] == -3) ||
            (rowvalues[i] == 3))
            returnval = true;
    }
    // check if board full
    bool full = true;
    for (i = 0; i < 9; i++)
    {
        if (tokenvalues[i] == 0)
            full = false;
    }
    // if there was no winner check if board was full
    if (!returnval)
        returnval = full; // if this is true, it was tie
    return returnval;
}

char GameEngine::whoseTurnIsIt()
{
    return whoseTurn;
}

void GameEngine::update(char t, int l)
{
    tokens[l - 1] = t;
}

void GameEngine::reset()
{
    int i;
    for(i = 0; i < 10; i++)
        tokens[i] = '-';
    whoseTurn = 'X';
    selected = ' ';
}
