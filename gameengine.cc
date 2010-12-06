// Copyright 2010 by Russell Miller
// Please see included license information in file
// COPYING or visit
// http://opensource.org/licenses/mit-license.php

// gameengine.cc
// GameEngine implementation

#include "gameengine.hh"

// Need to initialize. X's turn first, nothing selected,
// and all squares blank.
GameEngine::GameEngine():whoseTurn('X'),selected(' ')
{
    int i;
    for (i = 0; i < 9; i++)
        tokens[i] = '-';
}

// count the X's and O's on the board. If there are more X's
// it is O's turn. Vice versa. It should be noted that when
// this function is called, whoseTurn does not always change.
void
GameEngine::changeTurn()
{
    int i;
    int x = 0;
    int o = 0;
    for (i = 0; i < 9; i++) {
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

char
GameEngine::whatIsSelected()
{
    return selected;
}

void
GameEngine::changeSelect(char toWhat)
{
    selected = toWhat;
}

// As the name suggests, checking various end-game states.
//  -By assinging positive or negative numbers to spots in
//   the array can check if there is a '-3' or '3' anywhere.
//  -If the board is full it's obviously over.
//  -Use Bart's awesome drawn function to check if win is impossible.
char
GameEngine::isOver()
{
    // count squares
    int tokenvalues[9];
    int i;
    for (i = 0; i < 9; i++) {
        switch (tokens[i]) {
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
    for (i = 0; i < 8; i++) {
        // note: check for previously declared winner first
        // to avoid 2 winners at the same time..
        if ((rowvalues[i] == -3) && (returnval == 'n')) {
            // 3 X's in a "row"
            returnval = 'x';    // code letter for "X" wins.
        }
        if ((rowvalues[i] == 3) && (returnval == 'n')) {
            // 3 O's in a "row"
            returnval = 'o';    // code letter for "O" wins.
        }
    }
    // check if board full
    bool full = true;
    for (i = 0; i < 9; i++) {
        if (tokenvalues[i] == 0)
            full = false;
    }
    // check if win impossible using Bart Massey's drawn function
    bool winImpossible = drawn();

    // if there was no winner and board was full(or win is impossible), declare draw
    if ((returnval == 'n') && (full || winImpossible))
        returnval = 'd';        // code letter for "D"raw.
    return returnval;
}

char
GameEngine::whoseTurnIsIt()
{
    return whoseTurn;
}

// Simple API function for allowing different objects an
// easy way to update the board. t is for token, l is for location.
void
GameEngine::update(char t, int l)
{
    tokens[l - 1] = t;
}

// Return to initial game state.
void
GameEngine::reset()
{
    int i;
    for(i = 0; i < 10; i++)
        tokens[i] = '-';
    whoseTurn = 'X';
    selected = ' ';
}

// Mainly for debugging. Could be used for logging games to a file.
// Converts the array of values to a string.
QString
GameEngine::tokenstring()
{
    QString allSquares;
    int i;
    for(i = 0; i < 9; i++)
        allSquares += tokens[i];
    return allSquares;
}

// Following code generously contributed by Bart Massey
bool
GameEngine::drawn()
{
    int lines[8][3] = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6}
    };

    int i, j;
    bool xflag, oflag;
    for (i = 0; i < 8; i++) {
	xflag = false;
	oflag = false;
	for (j = 0; j < 3; j++) {
	    if (tokens[lines[i][j]] == 'X')
		xflag = true;
	    else if(tokens[lines[i][j]] == 'O')
		oflag = true;
	}
        if (!xflag || !oflag)
	    return false;
    }
    return true;
}
