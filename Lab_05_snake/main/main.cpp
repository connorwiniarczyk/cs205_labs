#include <iostream>
#include "gameboard.h"
#include "render_engine.h"
#include <chrono>
#include <thread>

int main() {
	render_engine::init();

	GameBoard* board = new GameBoard();
	Player* player = new Player(Point(3, 3));

	for(int i=0; i<3; i++){
		Tail* tail = new Tail(Point(0, 0));
		player -> addToTail(tail);
		board -> add(tail);
	}

	board -> add(player);

	for(int i=0; i<GameBoard::WIDTH; i++) {
		board -> add(new Wall(Point(i, 0)));
	}

	for(int i=0; i<GameBoard::WIDTH; i++) {
		board -> add(new Wall(Point(i, GameBoard::HEIGHT - 1)));
	}

	for(int i=0; i<GameBoard::HEIGHT; i++) {
		board -> add(new Wall(Point(0, i)));
	}

	for(int i=0; i<GameBoard::HEIGHT; i++) {
		board -> add(new Wall(Point(GameBoard::WIDTH - 1, i)));
	}


	int input;
	std::thread listen([&](){
		while(true) {
			input = getch();
		}
	});

	//gameloop
	while(true) {
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
		board = board -> map([&](GameToken* token){
			token -> update(input);
		});
		render_engine::render(board);
	}

	return 0;
}