#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "gametoken.h"
#include <vector>
#include <sstream>
#include <map>

using namespace std;

class GameBoard {
public:
	GameBoard();
	GameBoard(int, int);

	std::vector<GameToken*> pieces;
	std::string render();

	void update(std::string input);

	std::vector<GameToken*> filter(std::function<bool(GameToken*)>);

	void check_for_collisions();

	int width; int height;
};

#endif