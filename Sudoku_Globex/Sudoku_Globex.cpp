// Sudoku_Globex.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>
#include "GameSetup.h"

#define EMPTY 0
#define GRID_SIZE 9
void mainMenu();
void createBoard();
void printBoard();
bool solve();
bool play = true;
int board[GRID_SIZE][GRID_SIZE];
int response, columnChoice, rowChoice, valueChoice;
using namespace std;

int main()
{
	std::cout << "\n\t\t   GLO-DOKU\n";
	createBoard();
	while (play) {
		printBoard();
		mainMenu();
	}

	return 0;
}

void mainMenu()
{
	bool askQuestions = true, columnQuest = true, rowQuest = true, valueQuest = true;

	while (askQuestions != false) {
		while (columnQuest != false) {
			cout << "\n\t\tColumn: ";
			cin >> response;
			if (response > 9 || response < 1) {
				cout << "   Please enter a number between 1 and 9.";
			}
			else {
				columnChoice = response;
				columnQuest = false;
			}
		}

		while (rowQuest != false) {
			cout << "\n\t\t   Row: ";
			cin >> response;
			if (response > 9 || response < 1) {
				cout << "   Please enter a number between 1 and 9.";
			}
			else {
				rowChoice = response;
				rowQuest = false;
			}
		}

		if (board[rowChoice][columnChoice] != 0) {
			cout << "  There is already a value of " << board[rowChoice][columnChoice] << " entered. Overwrite? y/n: ";
			cin >> response;
			if (response == 'y') {
				valueQuest = true;
			}
			else if (response == 'n') {
				columnQuest = true;
				rowQuest = true;
			}
			else {
				cout << "   Please enter either y or n.";
			}
		}

		while (valueQuest != false) {
			cout << "\n\t\t Value: ";
			cin >> response;
			if (response > 9 || response < 1) {
				cout << "   Please enter a number between 1 and 9.";
			}
			else {
				valueChoice = response;
				valueQuest = false;
			}
		}

		board[rowChoice - 1][columnChoice - 1] = response;
		askQuestions = false;

		//if (solve()) cout << "Board solved!" << endl;
	}
}

void createBoard() {
	for (int i = 0; i <= 8; i++) {
		for (int j = 0; j <= 8; j++) {

		}
	}
}

void printBoard() {
	for (int i = 0; i <= 8; i++) {
		cout << endl << "     ";
		for (int j = 0; j <= 8; j++) {
			cout << "| " << board[i][j] << " ";
		}
		cout << "|" << endl;
	}
	cout << endl;
}

// checks to ensure a move is legal
bool legalMove(int row, int col, int num) {
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
bool freeSpot(int &row, int &col) {
	for (row = 0; row < GRID_SIZE; row++) {
		for (col = 0; col < GRID_SIZE; col++) {
			if (board[row][col] == EMPTY) return true;
		}
	}
	return false;
}

// solve puzzle with brute-force
bool solve() {
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