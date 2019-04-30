#include <iostream>
#include <time.h>
#include "Menu.h"
using namespace std;

void Menu::mainMenu() {
	bool askQuestions = true, columnQuest = true, rowQuest = true, valueQuest = true;
	while (askQuestions != false) {
		while (columnQuest != false) {
			cout << "\n\t\tColumn: ";
			cin >> response;
			if (response > 9 || response < 1) {
				cout << "   Please enter a number between 1 and 9.";
				CLEAR_INPUT( );
			} else {
				columnChoice = response;
				columnQuest = false;
			}
		}

		while (rowQuest != false) {
			cout << "\n\t\t   Row: ";
			cin >> response;
			if (response > 9 || response < 1) {
				cout << "   Please enter a number between 1 and 9.";
				CLEAR_INPUT( );
			} else {
				rowChoice = response;
				rowQuest = false;
			}
		}

		if (board[rowChoice][columnChoice] != 0) {
			cout << "  There is already a value of " << board[rowChoice][columnChoice] << " entered. Overwrite? y/n: ";
			cin >> response;
			if (response == 'y') {
				valueQuest = true;
			} else if (response == 'n') {
				columnQuest = true;
				rowQuest = true;
			} else {
				cout << "   Please enter either y or n.";
				CLEAR_INPUT( );
			}
		}

		while (valueQuest != false) {
			cout << "\n\t\t Value: ";
			cin >> response;
			if (response > 9 || response < 1) {
				cout << "   Please enter a number between 1 and 9.";
				CLEAR_INPUT( );
			} else {
				valueChoice = response;
				valueQuest = false;
			}
		}


		if (!legalMove(rowChoice, columnChoice, valueChoice)) {
			cout << "That is not a legal move." << endl;
		} else {
			board[rowChoice - 1][columnChoice - 1] = response;
		}
		askQuestions = false;
	}
}


void Menu::createBoard() {
	clock.start( );
	board[0][0] = 5;
	board[5][5] = 5;
	board[8][8] = 5;
	for (int i = 0; i <= 8; i++) {
		for (int j = 0; j <= 8; j++) {

		}
	}
	if (solve()) cout << "Board solved!" << endl;
	cout << "Difficulty:" << difficulty << endl;
}

void Menu::printBoard() {
	cout << "Timer: ";
	clock.printTime( );
	for (int i = 0; i <= 8; i++) {
		cout << endl << "     ";
		for (int j = 0; j <= 8; j++) {
			cout << "| " << board[i][j] << " ";
		}
		cout << "|" << endl;
	}
	cout << endl;
}

void Menu::clearBoard( ) {
	for (int i = 0; i < GRID_SIZE; i++) {
		for (int j = 0; j < GRID_SIZE; j++) {
			board[i][j] = 0;
			fixed[i][j] = false;
			ok[i][j] = false;
		}
	}
}

// checks to ensure a move is legal
bool Menu::legalMove(int row, int col, int num) {
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
bool Menu::freeSpot(int &row, int &col) {
	for (row = 0; row < GRID_SIZE; row++) {
		for (col = 0; col < GRID_SIZE; col++) {
			if (board[row][col] == EMPTY) return true;
		}
	}
	return false;
}

// solve puzzle with brute-force
bool Menu::solve() {
	difficulty++;
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