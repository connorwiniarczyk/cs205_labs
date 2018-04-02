#include "gameboard.h"

GameBoard::GameBoard(int _width, int _height){
	width = _width; height = _height;
}

GameBoard::GameBoard(){
	width = 10; height = 10;
}

std::string GameBoard::render(){
	std::ostringstream output;

	for(int i=0; i<pieces.size(); i++){
		//for each piece, move the cursor to its location
		output << "\033[" << pieces.at(i) -> position.y << ";" << pieces.at(i) -> position.x << "f";

		//render individual piece
		output << pieces.at(i) -> render();
	}
	return output.str();
}

void GameBoard::update(std::string input){
	for(int i=0; i<pieces.size();  i++){
		pieces.at(i)->update(input);
	}
}

std::vector<GameToken*> GameBoard::filter(std::function<bool (GameToken*)> condition){
	std::vector<GameToken*> output = std::vector<GameToken*>();

	for(int i=0; i<pieces.size();i++) {
		if(condition(pieces.at(i))) {
			output.push_back(pieces.at(i));
		}
	}

	return output;
}

void GameBoard::check_for_collisions(){
	for(int i=0; i<pieces.size(); i++) {
		auto colliding = filter([&](const GameToken* elem){
			return elem -> position == pieces.at(i) -> position;
		});
		std::cout << colliding.size() << std::endl;
	}
}
