#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
using namespace std;
#include <string>

/*
 * player class: to create a player object for games
*/

class player
{
public:

    // Constructor
    player();
    player(char symbol, string name);

    // initial function
    void initialPlayer(char symbol, string name);

    // Access functions
    char getSymbol();
    string getName();

private:
    string _name;
    char _symbol;
};

#endif // PLAYER_H
