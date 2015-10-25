#include <stdlib.h>
#include <stdio.h> //TODO [C++11] - Remove

#include "game_manager.h"
#include "logger.h"

/**
 * CONSTRUCTOR
 */
GameManager::GameManager() {
	this->whiteTeam = new Roster(WHITE);
	this->blackTeam = new Roster(BLACK);
	this->gameBoard = new Board();

	//- Log Successful Allocation ------------------------=
	//
	// TODO [C++11] - Switch to std::string stream
	char* s = (char*) malloc(sizeof(char) * 128);
	sprintf(s, "GameManager_WHITE::[%lub]_BLACK::[%lub]_BOARD::[%lub]",
		sizeof(this->whiteTeam), sizeof(this->blackTeam), sizeof(this->gameBoard));
	log_memory(s, true);
	free(s);
}

/**
 * DESTRUCTOR
 *
 * Member Memory to Destruct:
 *  - [1] White Team [Roster]
 *  - [2] Black Team [Roster]
 *  - [3] Game Board [Board]
 */
GameManager::~GameManager() {
	//- Log Imminent Deallocation ------------------------=
	//
	// TODO [C++11] - Switch to std::string stream
	char* s = (char*) malloc(sizeof(char) * 128);
	sprintf(s, "GameManager_WHITE::[%lub]_BLACK::[%lub]_BOARD::[%lub]",
		sizeof(this->whiteTeam), sizeof(this->blackTeam), sizeof(this->gameBoard));
	log_memory(s, false);
	free(s);

	delete(this->whiteTeam);                     // [1]
	delete(this->blackTeam);                     // [2]
	delete(this->gameBoard);                     // [3]
}

/**
 * Execute the next turn of the game.
 * 
 * @return True iff Game can continue.
 */
bool GameManager::nextTurn() {
	// TODO [Interactive] - Get Piece Move

	// TODO [Interactive] - Get Piece Move

	// TODO [Interactive] - Get Piece Move

	return true;
}