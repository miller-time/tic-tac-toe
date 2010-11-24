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

char GameEngine::isOver()
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

    char returnval = 'n';       // code letter for "N"o, it's not over.
    // check for 3 in a row
    for (i = 0; i < 8; i++)
    {
        // note: check for previously declared winner first
        // to avoid 2 winners at the same time..
        if ((rowvalues[i] == -3) && (returnval == 'n'))
        {
            // 3 X's in a "row"
            returnval = 'x';    // code letter for "X" wins.
        }
        if ((rowvalues[i] == 3) && (returnval == 'n'))
        {
            // 3 O's in a "row"
            returnval = 'o';    // code letter for "O" wins.
        }
    }
    // check if board full
    bool full = true;
    for (i = 0; i < 9; i++)
    {
        if (tokenvalues[i] == 0)
            full = false;
    }
    // if there was no winner and board was full, declare draw
    if ((returnval == 'n') && (full))
        returnval = 'd';        // code letter for "D"raw.
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
