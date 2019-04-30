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

		if (game.board[rowChoice][columnChoice] != 0) {
			cout << "  There is already a value of " << game.board[rowChoice][columnChoice] << " entered. Overwrite? y/n: ";
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
			if (response > 9 || response < 0) {
				cout << "   Please enter a number between 0 and 9.";
				CLEAR_INPUT( );
			} else {
				valueChoice = response;
				valueQuest = false;
			}
		}


		if ((!game.legalMove(rowChoice, columnChoice, valueChoice) && valueChoice != EMPTY) || (game.fixed[rowChoice][columnChoice])) {
			cout << "That is not a legal move." << endl;
		} else {
			game.board[rowChoice - 1][columnChoice - 1] = response;
		}
		askQuestions = false;
	}
}