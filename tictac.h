#ifndef TICTAC_H
#define TICTAC_H

#include "player.h"

/*
 * Tictac class: to create a tictac game
 *
*/

class Tictac
{
public:
    Tictac();
    void run();
    void displayBoard();

private:
    // attributes
    static const int _size = 3;
    static const char _initChar = '.';
    static const char _endGame = 'N';
    static const char _resetGame = 'Y';
    char _board[_size][_size];
    player _player1;
    player _player2;
    player* _nextplayer;
    player* _otherplayer;
    string _result;

    // private helping functions
    void initialBoard();

    bool checkValid(int row, int col);
    bool checkAvailable(int row, int col);

    void writeOntoBoard(int row, int col, char symbol);

    void switchPlayerTurn();

    bool playerStep();

    bool checkWin();
    bool checkRowWin();
    bool checkColumnWin();
    bool checkDiagnolWin();

    bool checkTie();
};

#endif // TICTAC_H
