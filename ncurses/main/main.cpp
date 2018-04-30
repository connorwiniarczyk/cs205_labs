#include <iostream>
#include "gameboard.h"
#include "render_engine.h"
#include <chrono>
#include <thread>

int main() {
	render_engine::init();

	GameBoard* board = new GameBoard();
	board -> add(new GameToken(Point(3, 3)));
	board -> add(new GameToken(Point(4, 4)));

	// int ch = getch();


	// switch(ch) {
	// 	case KEY_UP:
	// 		velocity = Point( 0, -1);
	// 		break; 
	// 	case KEY_DOWN:
	// 		velocity = Point( 0,  1);
	// 		break;
	// 	case KEY_LEFT:
	// 		velocity = Point( 1,  0);
	// 		break;
	// 	case KEY_RIGHT:
	// 		velocity = Point(-1,  0);
	// }

	Point velocity = Point(1, 0);

	//gameloop
	// std::thread gameloop([&](){
	// 	while(true) {

	// 		std::this_thread::sleep_for(std::chrono::milliseconds(1000));


	// 		board = board -> map([&](GameToken* token){
	// 			return new GameToken(token -> position + velocity);
	// 		});

	// 		render_engine::render(board);
	// 	}
	// });
	// gameloop.detach();

	return 0;
}