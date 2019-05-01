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
	// create new puzzle
	gameMenu.game.createBoard();
	while (play) {
		// show puzzle and menu
		gameMenu.game.printBoard( );
		gameMenu.mainMenu( );
		/* Commented out - it was a test to test solve methods
		* if (getchar( ) == 'S') gameMenu.game.solve( );
		*/
		if (gameMenu.game.checkComplete( )) {
			// puzzle solved, so generate new puzzle
			gameMenu.game.printBoard( );
			cout << endl << endl << "You have solved the sudoku!" << endl;
			cout << "Total solve time: ";
			gameMenu.game.clock.printTime( );
			cout << " seconds." << endl;
			gameMenu.game.clearBoard( );
			gameMenu.game.createBoard( );
			continue;
		}
	}
	return 0;
}
