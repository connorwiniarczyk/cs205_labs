#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <list>
#include <functional>
#include <algorithm>

using namespace std;

class Point {
public:
	Point(int _x, int _y) {x = _x; y = _y;}
	Point() {x = 0; y = 0;}

	int x;
	int y;
};

Point operator+(Point a, Point b) {
	return Point(a.x + b.x, a.y + b.y);
}

bool operator==(Point a, Point b){
	return a.x == b.x && a.y == b.y;
}

class GameToken {
public:
	GameToken(Point _position) {
		position = _position;
		display = [](){return L'*';};
	}

	// create a copy of a a given GameToken pointer
	GameToken(GameToken* token) {
		position = token -> position;
		display = token -> display;
	}

	function<unsigned char ()> display;
	Point position;
};

class Player : public GameToken {
public:
	Player(Point _position) : GameToken(_position) {
		display = [](){return L'@';};
	}
};

class GameBoard {
public:
	GameBoard() {}

	void add(GameToken* token) {
		tokens.push_back(token);
	}

	// returns a deep copy of the GameBoard, with eath token mapped by a given function
	GameBoard* map(function<GameToken* (GameToken*)> operation){
		GameBoard* output = new GameBoard();
		this -> forEach([&](GameToken* token){

			output -> add(operation(token));
		});

		return output;
	}

	void forEach(function<void (GameToken*)> operation) {
		std::for_each(tokens.begin(), tokens.end(), operation);
	}

	list<GameToken*> tokens;

	static const int WIDTH = 30;
	static const int HEIGHT = 30;
};

#endif