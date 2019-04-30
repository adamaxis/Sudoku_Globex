#ifndef _MENU_H
#define _MENU_H
#include "Sudoku_Globex.h"
#include "Timer.h"
#include "Board.h"

class Menu {
public:
	int board[GRID_SIZE][GRID_SIZE],
	response,
	columnChoice,
	rowChoice,
	valueChoice,
	difficulty;
	Timer clock;
	Board game;
	bool fixed[GRID_SIZE][GRID_SIZE],
	ok[GRID_SIZE][GRID_SIZE];
	Menu( ) {
		response = columnChoice = rowChoice = valueChoice = difficulty = 0;
		game.clearBoard( );
	}
	void mainMenu();
};
#endif