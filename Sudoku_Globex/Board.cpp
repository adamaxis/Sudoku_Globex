#include <iostream>
#include "Board.h"
using namespace std;

void Board::createBoard() {
	clock.start( );
	for (int i = 0; i <= 8; i++) {
		for (int j = 0; j <= 8; j++) {

		}
	}
	/*if (solve()) cout << "Board solved!" << endl;
	cout << "Difficulty:" << difficulty << endl;*/
}

// set a spot to fixed
void Board::setFixed(int row, int col) {
	fixed[row][col] = true;
}

// check if a spot is fixed
bool Board::isFixed(int row, int col) {
	return fixed[row][col];
}

// set a spot to empty
void Board::setEmpty(int row, int col) {
	board[row][col] = EMPTY;
}

// check if a spot is empty
bool Board::isEmpty(int row, int col) {
	return (board[row][col] == EMPTY);
}

void Board::printBoard() {
	cout << "Timer: ";
	clock.printTime( );
	for (int i = 0; i <= 8; i++) {
		cout << endl << "     ";
		for (int j = 0; j <= 8; j++) {
			cout << "|";
			if (isFixed(i, j)) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 128); // grey
			else if(!isEmpty(i, j)) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 32); // green
			else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 224); // red
			cout << " " << board[i][j] << " ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), origConsole->wAttributes); //original color
		}
		cout << "|" << endl;
	}
	cout << endl;
}

// clear board and fixed spaces
void Board::clearBoard( ) {
	for (int i = 0; i < GRID_SIZE; i++) {
		for (int j = 0; j < GRID_SIZE; j++) {
			board[i][j] = 0;
			fixed[i][j] = false;
		}
	}
}

// checks to ensure a move is legal
bool Board::legalMove(int row, int col, int num) {
	if (board[row][col] != EMPTY) return false;

	for (int row = 0; row < GRID_SIZE; row++)
		if (board[row][col] == num)
			return false;

	for (int col = 0; col < GRID_SIZE; col++)
		if (board[row][col] == num)
			return false;

	int bRow = row - (row % 3);
	int bCol = col - (col % 3);
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			if (board[row + bRow][col + bCol] == num) return false;
		}
	}
	return true;
}

// find free spot in board
bool Board::freeSpot(int &row, int &col) {
	for (row = 0; row < GRID_SIZE; row++) {
		for (col = 0; col < GRID_SIZE; col++) {
			if (board[row][col] == EMPTY) return true;
		}
	}
	return false;
}

// solve puzzle with brute-force
bool Board::solve() {
	int row, col;

	if (!freeSpot(row, col)) return true;

	for (int num = 1; num < 10; num++) {
		if (legalMove(row, col, num)) {
			board[row][col] = num;
			if (solve()) return true;
			board[row][col] = EMPTY;
		}
	}
	return false;
}
