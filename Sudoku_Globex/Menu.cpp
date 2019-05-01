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
			if (stoi(response) > 9 || stoi(response) < 1) {
				cout << "   Please enter a number between 1 and 9.";
				CLEAR_INPUT( );
			} else {
				columnChoice = stoi(response);
				columnQuest = false;
			}
		}

		while (rowQuest != false) {
			cout << "\n\t\t   Row: ";
			cin >> response;
			if (stoi(response) > 9 || stoi(response) < 1) {
				cout << "   Please enter a number between 1 and 9.";
				CLEAR_INPUT( );
			} else {
				rowChoice = stoi(response);
				rowQuest = false;
			}
		}

		// update choices to reflect column
		rowChoice--;
		columnChoice--;

		if (game.board[rowChoice][columnChoice] != EMPTY) {
			cout << "  There is already a value of " << game.board[rowChoice][columnChoice] << " entered. Overwrite? y/n: ";
			while (1) {
				cin >> response;
				if (response.at(0) == 'y') {
					valueQuest = true;
					break;
				} else if (response.at(0) == 'n') {
					columnQuest = true;
					rowQuest = true;
				} else {
					cout << "   Please enter either y or n.";
					CLEAR_INPUT( );
				}
			}
		}

		while (valueQuest != false) {
			cout << "\n\t\t Value: ";
			cin >> response;
			if (stoi(response) > 9 || stoi(response) < 0) {
				cout << "   Please enter a number between 0 and 9.";
				CLEAR_INPUT( );
			} else {
				valueChoice = stoi(response);
				valueQuest = false;
			}
		}


		if ((!game.legalMove(rowChoice, columnChoice, valueChoice) && valueChoice != EMPTY) || (game.fixed[rowChoice][columnChoice])) {
			cout << "That is not a legal move." << endl;
		} else {
			game.board[rowChoice][columnChoice] = stoi(response);
		}
		askQuestions = false;
		CLEAR_INPUT( );
	}
}