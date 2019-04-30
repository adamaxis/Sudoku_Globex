#ifndef _MENU_H
#define _MENU_H
#include "Sudoku_Globex.h"
#include "Timer.h"

class Menu {
public:
	int board[GRID_SIZE][GRID_SIZE],
	response,
	columnChoice,
	rowChoice,
	valueChoice,
	difficulty;
	bool fixed[GRID_SIZE][GRID_SIZE],
	ok[GRID_SIZE][GRID_SIZE];
	Timer clock;
	void mainMenu();
	void createBoard( );
	void printBoard( );
	void clearBoard( );
	bool legalMove(int, int, int);
	bool freeSpot(int &, int &);
	bool solve( );

	Menu( ) {
		response = columnChoice = rowChoice = valueChoice = difficulty = 0;
		clearBoard( );
	}
};
#endif