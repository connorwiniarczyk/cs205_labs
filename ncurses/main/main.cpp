#include <iostream>
#include "gameboard.h"
#include "render_engine.h"
#include <chrono>
#include <thread>

int main() {
	render_engine::init();

	GameBoard* board = new GameBoard();
	board -> add(new Player(Point(3, 3)));

	int input;

	std::thread listen([&](){
		while(true) {
			input = getch();
		}
	});

	Point velocity = Point(1, 0);

	//gameloop
	while(true) {

		std::this_thread::sleep_for(std::chrono::milliseconds(50));

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

		board = board -> map([&](GameToken* token){
			return new GameToken(token -> position + velocity);
		});

		render_engine::render(board);
	}

	return 0;
}