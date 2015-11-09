#include <stdlib.h>
#include <stdio.h> //TODO [C++11] - Remove

#include "chess_master.h"
#include "logger.h"

/**
 * CONSTRUCTOR
 */
ChessMaster::ChessMaster() {
	this->game       = new GameManager();
	this->display    = new Display();
	this->controller = new UserController();

	//- Log Successful Allocation ------------------------=
	//
	// TODO [C++11] - Switch to std::string stream
	char* s = (char*) malloc(sizeof(char) * 128);
	sprintf(s, "ChessMaster_GAME::[%lub]_DISPLAY::[%lub]_CONTROLLER::[%lub]",
		sizeof(this->game), sizeof(this->display), sizeof(this->controller));
	log_memory(s, true);
	free(s);
}

/**
 * DESTRUCTOR
 *
 * Member Memory to Destruct:
 *  - [1] Game Model Instance [Game Manager]
 *  - [2] Display Driver      [Display]
 *  - [3] User Controller     [UserController]
 */
ChessMaster::~ChessMaster() {
	//- Log Imminent Deallocation ------------------------=
	//
	// TODO [C++11] - Switch to std::string stream
	char* s = (char*) malloc(sizeof(char) * 128);
	sprintf(s, "ChessMaster_GAME::[%lub]_DISPLAY::[%lub]_CONTROLLER::[%lub]",
		sizeof(this->game), sizeof(this->display), sizeof(this->controller));
	log_memory(s, false);
	free(s);

	delete(this->game);                          // [1]
	delete(this->display);                       // [2]
	delete(this->controller);                    // [3]
}

/**
 * Game Start
 *
 * Set up the Board and get ready to rock.
 * 
 * @return False iff Game has not been reset.
 */
bool ChessMaster::startGame() {
	if (this->game->getGame()->getPlayState() != NOT_STARTED) {
		log_action("[ChessMaster::startGame] Cannot Start - Play State has not been reset.");
		return false;
	}

	log_action("Setting Up Board.");
	this->game->setupBoard();

	log_action("Starting Game!");

	// TODO: Set Game Model's Play State in Progress
	return true;
}

/**
 * Resets a game that is in progress or completed.
 *
 * @return False iff game has already been reset.
 */
bool ChessMaster::resetGame() {
	if (this->game->getGame()->getPlayState() == NOT_STARTED) {
		log_action("[ChessMaster::resetGame] Nothing to do - Game is already reset.");
		return false;
	}

	log_action("Resetting Game.");

	// TODO: Reset Game Model's Play State
	return true;
}

/**
 * Execute the next turn of the game.
 * 
 * @return True iff Game can continue.
 */
bool ChessMaster::nextTurn() {
	// TODO [Interactive] - Get Piece Move

	// TODO [Interactive] - Get Piece Move

	// TODO [Interactive] - Get Piece Move

	this->display->renderGame(this->game->getGame());

	return true;
}