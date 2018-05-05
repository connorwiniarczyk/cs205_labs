#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <list>
#include <functional>
#include <algorithm>
#include <curses.h>

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

	virtual void update(int input){
		/* do nothing */
	}

	virtual GameToken* clone(){
		GameToken* output = new GameToken(this);
		return output;
	}

	function<unsigned char ()> display;
	Point position;
};

class Tail : public GameToken {
public:
	Tail(Point _position) : GameToken(_position) {
			// tokenToFollow = _tokenToFollow;
			display = [](){return L'*';};
	}

	void update(int input) override {
		this -> position = tokenToFollow -> position;
	}

	GameToken* clone() override {
		Tail* output = new Tail(position);
		output -> tokenToFollow = tokenToFollow;
		return output;
	}

	GameToken* tokenToFollow;
};

class Player : public GameToken {
public:
	Player(Point _position) : GameToken(_position) {
		display = [](){return L'@';};
	}

	void update(int input) override {
		Point velocity = Point( 0,  0);

		switch(input) {
			case KEY_UP:
				velocity = Point( 0, -1);
				break; 
			case KEY_DOWN:
				velocity = Point( 0,  1);
				break;
			case KEY_LEFT:
				velocity = Point(-2,  0);
				break;
			case KEY_RIGHT:
				velocity = Point( 2,  0);
		}
		this -> position = this -> position + velocity;
	}

	GameToken* clone() override {
		Player* output = new Player(position);
		output -> tail = tail;
		return output;
	}

	void addToTail(Tail* token){
		token -> tokenToFollow = (tail.size() == 0) ? static_cast<GameToken*>(this) : static_cast<GameToken*>(tail.back());
		tail.push_back(token);
	}

	list<Tail*> tail;
};

class Wall : public GameToken {
public:
	Wall(Point _position) : GameToken(_position) {
		display = [](){return L'#';};
	}
};

class GameBoard {
public:
	GameBoard() {}

	void add(GameToken* token) {
		tokens.push_back(token);
	}

	// returns a deep copy of the GameBoard, with eath token mapped by a given function
	GameBoard* map(function<void (GameToken*)> operation){
		GameBoard* output = new GameBoard();
		this -> forEach([&](GameToken* token){
			GameToken* newToken = token -> clone();
			operation(newToken);
			output -> add(newToken);
		});

		return output;
	}

	void forEach(function<void (GameToken*)> operation) {
		std::for_each(tokens.begin(), tokens.end(), operation);
	}

	list<GameToken*> tokens;

	static const int WIDTH = 60;
	static const int HEIGHT = 30;
};

#endif