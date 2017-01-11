#pragma once

#include <iostream>

class GameState {
public:

	// 6 7 8
	// 3 4 5
	// 0 1 2
	char marks[8];

	bool checkTurn();
	bool isCatsEye();
	
	void init();
	char doMove();
	void drawRound() const;
	void checkRound() const;

};