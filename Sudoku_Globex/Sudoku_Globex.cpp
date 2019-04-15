// Sudoku_Globex.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>

void mainMenu();
void createBoard();
void printBoard();
int board[9][9];
int response, columnChoice, rowChoice, valueChoice;
using namespace std;

int main()
{
    std::cout << "\n\t\t   GLO-DOKU\n"; 
	createBoard();
	printBoard();
	mainMenu();

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
			cout << "\n\t\t  Row: ";
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

		board[rowChoice][columnChoice] = response;
		askQuestions = false;
	}
}

void createBoard()
{
	for (int i = 0; i <= 8; i++) {
		for (int j = 0; j <= 8; j++) {

		}
	}
}

void printBoard()
{
	for (int i = 0; i <= 8; i++) {
		cout << endl << "     ";
		for (int j = 0; j <= 8; j++) {
			cout << "| " << board[i][j] << " ";
		}
		cout << "|" << endl;
	}

	cout << endl;
}

