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
	gameMenu.game.createBoard();
	while (play) {
		gameMenu.game.printBoard();
		if (gameMenu.game.checkComplete()) {
			cout << endl << endl << "You have solved the sudoku!" << endl;
			gameMenu.game.clearBoard( );
			gameMenu.game.createBoard( );
			continue;
		}
		gameMenu.mainMenu();
	}

	return 0;
}
