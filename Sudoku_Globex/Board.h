#ifndef _BOARD_H
#define _BOARD_H
#include <Windows.h>
#include "Sudoku_Globex.h"
#include "Timer.h"

class Board {
	public:
	int board[GRID_SIZE][GRID_SIZE],
		difficulty;
	bool fixed[GRID_SIZE][GRID_SIZE];
	Timer clock;
	CONSOLE_SCREEN_BUFFER_INFO *origConsole;
	void createBoard( );
	void printBoard( );
	void clearBoard( );
	void setColor(int);
	void revertColor( );
	void setBox(int, int, int);
	int getBox(int, int);
	void setFixed(int, int);
	bool isFixed(int, int);
	void setEmpty(int, int);
	bool isEmpty(int, int);
	bool legalMove(int, int, int);
	bool freeSpot(int &, int &);
	bool checkComplete( );
	bool solve( );
	Board( ) {
		difficulty = 0;
		clearBoard( );
		origConsole = new CONSOLE_SCREEN_BUFFER_INFO();
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), origConsole);
	}

	~Board( ) {
		delete origConsole;
	}
};

#endif