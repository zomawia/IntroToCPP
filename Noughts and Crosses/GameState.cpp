#include "GameState.h"

bool GameState::checkTurn()
{
	return false;
}

bool GameState::isCatsEye()
{
	return false;
}

void GameState::init()
{
	for (int i = 0; i < 8; ++i)	marks[i] = i;
}

char GameState::doMove()
{	
	if (checkTurn() == 0) printf("Player 1: ");
	else printf("Player 2: ");
	
	printf("Where put the piece?/n");
	
	if (checkTurn() == 0) return 'X';
	else return 'O';
}

void GameState::drawRound() const
{
	printf("                      ");

	printf("%c|%c|%c", marks[6], marks[7], marks[8]);
	printf("-----");
	printf("%c|%c|%c", marks[3], marks[4], marks[5]);
	printf("-----");
	printf("%c|%c|%c", marks[0], marks[1], marks[2]);

	printf("                      ");
	


}

void GameState::checkRound() const
{	
	//check X rows, columns, diag for win
	if ((marks[0] == 'X' && marks[1] == 'X' && marks[2]) ||
		(marks[3] == 'X' && marks[4] == 'X' && marks[5]) ||
		(marks[6] == 'X' && marks[7] == 'X' && marks[8]) ||

		(marks[0] == 'X' && marks[3] == 'X' && marks[6]) ||
		(marks[7] == 'X' && marks[4] == 'X' && marks[1]) ||
		(marks[8] == 'X' && marks[5] == 'X' && marks[2]) ||
		
		(marks[6] == 'X' && marks[4] == 'X' && marks[2]) ||
		(marks[0] == 'X' && marks[4] == 'X' && marks[8]) ){

	}

	//Check O rows, colums, diag for win
	if ((marks[0] == 'O' && marks[1] == 'O' && marks[2]) ||
		(marks[3] == 'O' && marks[4] == 'O' && marks[5]) ||
		(marks[6] == 'O' && marks[7] == 'O' && marks[8]) ||

		(marks[0] == 'O' && marks[3] == 'O' && marks[6]) ||
		(marks[7] == 'O' && marks[4] == 'O' && marks[1]) ||
		(marks[8] == 'O' && marks[5] == 'O' && marks[2]) ||

		(marks[6] == 'O' && marks[4] == 'O' && marks[2]) ||
		(marks[0] == 'O' && marks[4] == 'O' && marks[8])) {

	}

}
