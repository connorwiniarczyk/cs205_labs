#ifndef GAME_H
#define GAME_H

class Player;

#import "player.h"

class Game{
public:
	Game(){

	}	

	~Game(){

	}

	std::string name;
	int score;

	Player* player;
};

#endif