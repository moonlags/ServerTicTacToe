#include "Game.h"

char Game::getField(int x)
{
    return field[x];
}

bool Game::setField(int x, char value)
{
    if (field[x] ==0){
        field[x] = value;
        return true;
    }
    return false;
}

char Game::checkWin()
{
    return 0;
}
