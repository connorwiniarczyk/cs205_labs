#include "gametoken.h"

GameToken::GameToken(){
	position = Point(0,0); 
}

GameToken::GameToken(Point _position){
	position = _position; 
}

std::string GameToken::render(){
	return "❖";
}

std::string Player::render(){
	return "X";
}



void GameToken::update(std::string input) {}

void Player::update(std::string input) {
	Point direction;
	if		(input == "up")		direction = Point( 0, -1);
	else if (input == "down")	direction = Point( 0,  1);
	else if (input == "left")	direction = Point(-1,  0);
	else if (input == "right")	direction = Point( 1,  0);
	else						direction = Point( 0,  0);

	position = position + direction;
}