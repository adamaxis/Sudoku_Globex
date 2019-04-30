// Sudoku_Globex.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>
#include "Sudoku_Globex.h"
#include "Menu.h"
using namespace std;
bool play = true;

int main()
{
	std::cout << "\n\t\t   GLO-DOKU\n";
	Menu gameMenu;
	gameMenu.createBoard();
	while (play) {
		gameMenu.printBoard();
		gameMenu.mainMenu();
	}

	return 0;
}
