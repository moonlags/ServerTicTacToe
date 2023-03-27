#pragma once
#include <cstdint>

class Game
{
public:
	char getField(int x);
	bool setField(int x, char value);
	char checkWin();
private:
	uint32_t gameId;
	char field[9] = {};
};

