// Sudoku_Globex.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>
#include "Sudoku_Globex.h"

void mainMenu();
void createBoard();
void printBoard();
int board[9][9];
int columnChoice, rowChoice;
using namespace std;

int main()
{
    std::cout << "\n\t\t   GLO-DOKU\n"; 
	createBoard();
	printBoard();
	mainMenu();
}

void mainMenu()
{
	cout << "\nColumn: ";
	cin >> columnChoice;
	cout << "Row: ";
	cin >> rowChoice;
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
		cout << endl << endl;
		for (int j = 0; j <= 8; j++) {
			cout << "   " << board[i][j] << " ";
		}
	}

	cout << endl;
}

