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
	}

	// create a copy of a a given GameToken pointer
	GameToken(GameToken* token) {
		position = token -> position;
	}

	virtual unsigned char display(){
		return L'*';
	}

	Point position;
};

//forward declare
class GameBoard;
GameBoard* deep_copy(GameBoard* board);

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


		// GameBoard* output = deep_copy(this);
		// output -> forEach(operation);
		return output;
	}

	void forEach(function<void (GameToken*)> operation) {
		std::for_each(tokens.begin(), tokens.end(), operation);
	}

	list<GameToken*> tokens;

	static const int WIDTH = 20;
	static const int HEIGHT = 20;
};

// int GameBoard::WIDTH = 20;
// int GameBoard::HEIGHT = 20;

// creates a deep copy of a given gameboard and returns a pointer to it
GameBoard* deep_copy(GameBoard* board) {
	GameBoard* output = new GameBoard();

	for_each(board -> tokens.begin(), board -> tokens.end(), [&](GameToken* token){
		output -> tokens.push_back(new GameToken(token));
	});

	return output;
}

#endif