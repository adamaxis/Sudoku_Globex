#include <iostream>
#include <time.h>
#include "Menu.h"
using namespace std;

void Menu::mainMenu()
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