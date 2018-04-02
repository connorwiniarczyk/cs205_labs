#include <iostream>
// #include <>
#include "gameboard.h"
#include "gametoken.h"

using namespace std;

int main (){
	//game setup
	GameBoard board = GameBoard(10, 10);

	board.pieces.push_back(new GameToken(Point(1, 1)));
	board.pieces.push_back(new GameToken(Point(1, 10)));
	board.pieces.push_back(new GameToken(Point(20, 1)));
	board.pieces.push_back(new GameToken(Point(20,10)));

	board.pieces.push_back(new Player(Point(10,5)));

	//game loop
	while(1){
		// clear the screen
		system("clear");

		// cout << Player(Point(10,10)).render();
		cout << board.render();

		//to finish move the cursor to just below the board
		cout << "\033[" << (board.height + 2) << ";0f";

		//wait for user input
		std::string input;
		cin >> input;
		board.update(input);
		board.check_for_collisions();
	}
}