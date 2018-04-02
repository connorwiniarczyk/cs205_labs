#ifndef GAMETOKEN_H
#define GAMETOKEN_H

#include <iostream>
#include <sstream>

using namespace std;

class Point {
public:
	int x;
	int y;

	Point(int _x, int _y){
		x = _x; 
		y = _y;
	};
	Point(){
		x = 0; 
		y = 0;
	};

	friend Point operator +(Point p1, Point p2) {
		return Point(p1.x + p2.x, p1.y + p2.y);
	}

	friend bool operator ==(Point p1, Point p2) {
		return p1.x == p2.x && p1.y == p2.y;
	}
};

class GameToken {
public:
	GameToken();
	GameToken(Point _position);

	virtual std::string render();
	virtual void update(std::string input);
	// virtual GameToken next(string input);

	Point position;
};

class Player : public GameToken {
public:
	Player(Point _position) : GameToken(_position) {};

	std::string render();
	void update(std::string update);
};

#endif