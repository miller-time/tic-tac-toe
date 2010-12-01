// Copyright 2010 by Russell Miller
// Please see included license information in file
// COPYING or visit
// http://opensource.org/licenses/mit-license.php


#include "gameengine.hh"

GameEngine::GameEngine():whoseTurn('X'),selected(' ')
{
    int i;
    for (i = 0; i < 9; i++)
        tokens[i] = '-';
}

void GameEngine::changeTurn()
{
    int i;
    int x = 0;
    int o = 0;
    for (i = 0; i < 9; i++)
    {
        if (tokens[i] == 'X')
            x += 1;
        if (tokens[i] == 'O')
            o += 1;
    }
    if (x > o)
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
    for (i = 0; i < 9; i++)
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
    //2nd row
    rowvalues[3] = tokenvalues[3] +
                   tokenvalues[4] +
                   tokenvalues[5];
    //3rd row
    rowvalues[5] = tokenvalues[6] +
                   tokenvalues[7] +
                   tokenvalues[8];
    //left column
    rowvalues[1] = tokenvalues[0] +
                   tokenvalues[3] +
                   tokenvalues[6];
    //2nd column
    rowvalues[4] = tokenvalues[1] +
                   tokenvalues[4] +
                   tokenvalues[7];
    //3rd column
    rowvalues[6] = tokenvalues[2] +
                   tokenvalues[5] +
                   tokenvalues[8];
    // \ diagonal
    rowvalues[2] = tokenvalues[0] +
                   tokenvalues[4] +
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
    // check if win impossible
    bool winImpossible = true;
    // every possible combination of X and O in same row
    if (!((tokens[0] == 'X') && (tokens[1] == 'O')) &&
        !((tokens[0] == 'X') && (tokens[2] == 'O')) && // top row
        !((tokens[1] == 'X') && (tokens[2] == 'O')) &&
        !((tokens[0] == 'O') && (tokens[1] == 'X')) &&
        !((tokens[0] == 'O') && (tokens[2] == 'X')) &&
        !((tokens[1] == 'O') && (tokens[2] == 'X')))
        winImpossible = false;
    if (!((tokens[3] == 'X') && (tokens[4] == 'O')) &&
        !((tokens[3] == 'X') && (tokens[5] == 'O')) && // middle row
        !((tokens[4] == 'X') && (tokens[5] == 'O')) &&
        !((tokens[3] == 'O') && (tokens[4] == 'X')) &&
        !((tokens[3] == 'O') && (tokens[5] == 'X')) &&
        !((tokens[4] == 'O') && (tokens[5] == 'X')))
        winImpossible = false;
    if (!((tokens[6] == 'X') && (tokens[7] == 'O')) &&
        !((tokens[6] == 'X') && (tokens[8] == 'O')) && // bottom row
        !((tokens[7] == 'X') && (tokens[8] == 'O')) &&
        !((tokens[6] == 'O') && (tokens[7] == 'X')) &&
        !((tokens[6] == 'O') && (tokens[8] == 'X')) &&
        !((tokens[7] == 'O') && (tokens[8] == 'X')))
        winImpossible = false;
    if (!((tokens[0] == 'X') && (tokens[3] == 'O')) &&
        !((tokens[0] == 'X') && (tokens[6] == 'O')) && // left column
        !((tokens[3] == 'X') && (tokens[6] == 'O')) &&
        !((tokens[0] == 'O') && (tokens[3] == 'X')) &&
        !((tokens[0] == 'O') && (tokens[6] == 'X')) &&
        !((tokens[3] == 'O') && (tokens[6] == 'X')))
        winImpossible = false;
    if (!((tokens[1] == 'X') && (tokens[4] == 'O')) &&
        !((tokens[1] == 'X') && (tokens[7] == 'O')) && // middle column
        !((tokens[4] == 'X') && (tokens[7] == 'O')) &&
        !((tokens[1] == 'O') && (tokens[4] == 'X')) &&
        !((tokens[1] == 'O') && (tokens[7] == 'X')) &&
        !((tokens[4] == 'O') && (tokens[7] == 'X')))
        winImpossible = false;
    if (!((tokens[2] == 'X') && (tokens[5] == 'O')) &&
        !((tokens[2] == 'X') && (tokens[8] == 'O')) && // right column
        !((tokens[5] == 'X') && (tokens[8] == 'O')) &&
        !((tokens[2] == 'O') && (tokens[5] == 'X')) &&
        !((tokens[2] == 'O') && (tokens[8] == 'X')) &&
        !((tokens[5] == 'O') && (tokens[8] == 'X')))
        winImpossible = false;
    if (!((tokens[0] == 'X') && (tokens[4] == 'O')) &&
        !((tokens[0] == 'X') && (tokens[8] == 'O')) && // '\' diagonal
        !((tokens[4] == 'X') && (tokens[8] == 'O')) &&
        !((tokens[0] == 'O') && (tokens[4] == 'X')) &&
        !((tokens[0] == 'O') && (tokens[8] == 'X')) &&
        !((tokens[4] == 'O') && (tokens[8] == 'X')))
        winImpossible = false;
    if (!((tokens[2] == 'X') && (tokens[4] == 'O')) &&
        !((tokens[2] == 'X') && (tokens[6] == 'O')) && // '/' diagonal
        !((tokens[4] == 'X') && (tokens[6] == 'O')) &&
        !((tokens[2] == 'O') && (tokens[4] == 'X')) &&
        !((tokens[2] == 'O') && (tokens[6] == 'X')) &&
        !((tokens[4] == 'O') && (tokens[6] == 'X')))
        winImpossible = false;

    // if there was no winner and board was full(or win is impossible), declare draw
    if ((returnval == 'n') && (full || winImpossible))
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

QString GameEngine::tokenstring()
{
    QString allSquares;
    int i;
    for(i = 0; i < 9; i++)
    {
        allSquares += tokens[i];
    }
    return allSquares;
}
