#include "player.h"

// constructor a player object with default values
player::player()
{
    _symbol = ' ';
    _name = "Default";
}

// constructor a player object with paramters
player::player(char symbol, string name)
{
    initialPlayer(symbol, name);
}

// initialize all the attributes based on parameters
void player::initialPlayer(char symbol, string name)
{
    _symbol = symbol;
    _name = name;
}

// access the symbol attribute
char player::getSymbol()
{
    return _symbol;
}

// access the name attribute
string player::getName()
{
    return _name;
}
