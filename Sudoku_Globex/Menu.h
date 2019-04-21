#ifndef _MENU_H
#define _MENU_H

class Menu {
public:
	int board[9][9],
		response,
		columnChoice,
		rowChoice,
		valueChoice;
	bool fixed[9][9],
		 ok[9][9];
	void mainMenu();
};
#endif