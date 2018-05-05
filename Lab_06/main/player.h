#ifndef PLAYER_H
#define PLAYER_H

class Game;

#import "game.h"

class Player{
public:
	Player() {}
	~Player() {}

	std::string firstname;
	std::string lastname;
	std::string address;

	Game* game;
}

#endif