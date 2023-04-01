#pragma once

#include <iostream>

using namespace std;

class Game
{
public:
	Game(uint32_t gameId,string player);
	~Game();

	uint32_t getGameId();

	void addPlayer(string player);

	char getField(int x);
	bool setField(int x, char value);
	char checkWin();
private:
	uint32_t gameId;
	char field[9];
	string players[2];
	int playersLen;
};

