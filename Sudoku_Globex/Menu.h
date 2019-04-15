#pragma once

class Menu {
public:
	int board[9][9],
		response, 
		columnChoice, 
		rowChoice, 
		valueChoice;
	void mainMenu();
};