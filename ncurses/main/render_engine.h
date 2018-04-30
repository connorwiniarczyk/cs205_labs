#ifndef SCREEN_H
#define SCREEN_H

#include <curses.h>
#include "gameboard.h"

namespace render_engine {

	WINDOW* win;

	void init() {
		initscr();	// initialize the screen
		cbreak();	// one character at at time
		noecho();	// don't echo input back to us
		keypad(stdscr, TRUE);	// enable special characters like arrow keys and backspace

		win = newwin(GameBoard::WIDTH,GameBoard::HEIGHT, 0, 0);
	}

	// render the state of a given gameboard to the screen
	void render(GameBoard* board) {
		werase(win);
		wrefresh(win);

		board -> forEach([](GameToken* token){
			mvwaddch(win, token -> position.y, token -> position.x, token -> display() );
		});

		wrefresh(win);

	}
}

#endif