#include "Game.h"

Game::Game(uint32_t gameIdm, string player): gameId(gameIdm), playersLen(1)
{   
    memset(&players, 0, 2);
    addPlayer(player);
    memset(&field, 0, 9);
}

Game::~Game()
{
    memset(&players, 0, 2);
    memset(&field, 0, 9);
}

uint32_t Game::getGameId()
{
    return gameId;
}

void Game::addPlayer(string player)
{
    players[playersLen] = player;
    playersLen++;
}

char Game::getField(int x)
{
    return field[x];
}

bool Game::setField(int x, char value)
{
    if (!field[x]){
        field[x] = value;
        return true;
    }
    return false;
}

char Game::checkWin()
{
    return 0;
}
