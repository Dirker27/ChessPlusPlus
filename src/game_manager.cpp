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

	//- Set Default Game States --------------------------=
	//
	this->gameState    = NOT_STARTED;
	this->turnState    = WHITE_MOVE;
	//this->endGameState = NONE;

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
 * Game Start
 *
 * Set up the Board and get ready to rock.
 * 
 * @return False iff Game has not been reset.
 */
bool GameManager::startGame() {
	if (this->gameState != NOT_STARTED) {
		log_action("[GameManager::startGame] Cannot Start - Game State has not been reset.");
		return false;
	}

	log_action("Starting Game!");
	this->setup();

	gameState = IN_PROGRESS;
	return true;
}

/**
 * Resets a game that is in progress or completed.
 *
 * @return False iff game has already been reset.
 */
bool GameManager::resetGame() {
	if (this->gameState == NOT_STARTED) {
		log_action("[GameManager::resetGame] Nothing to do - Game is already reset.");
		return false;
	}

	log_action("Resetting Game.");

	gameState = NOT_STARTED;
	return true;
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


/**
 * Update both the Board and the Piece with a new location
 *  IF the board deems it legal.
 * 
 * @return False iff space is out of bounds or occupied.
 */
bool GameManager::placePiece(Piece* piece, int x, int y) {
	bool success = this->gameBoard->placePiece(piece, x, y);
	
	if (success) {
		piece->updateLocation(x, y);
	}

	// Failures already logged at Board level. Would be excessive here.

	return success;
}

/**
 * Set up a new game.
 * 
 * @return True iff Game Has successfully been set up.
 */
void GameManager::setup(void) {
	this->_setWhite();
	this->_setBlack();
}


void GameManager::_setWhite() {
	//- Pawns --------------------------------------------=
	//
	for (int i = 0; i < 8; i++) {
		Piece* pawn = new Piece(WHITE, PAWN);
		this->placePiece(pawn, i, 1);
		whiteTeam->recruitPiece(pawn);
	}

	//- Rooks --------------------------------------------=
	//
	Piece* rook = new Piece(WHITE, ROOK);
	this->placePiece(rook, 0, 0);
	whiteTeam->recruitPiece(rook);
	//
	rook = new Piece(WHITE, ROOK);
	this->placePiece(rook, 7, 0);
	whiteTeam->recruitPiece(rook);

	//- Knights ------------------------------------------=
	//
	Piece* knight = new Piece(WHITE, KNIGHT);
	this->placePiece(knight, 1, 0);
	whiteTeam->recruitPiece(knight);
	//
	knight = new Piece(WHITE, KNIGHT);
	this->placePiece(knight, 6, 0);
	whiteTeam->recruitPiece(knight);

	//- Bishops ------------------------------------------=
	//
	Piece* bishop = new Piece(WHITE, BISHOP);
	this->placePiece(bishop, 2, 0);
	whiteTeam->recruitPiece(bishop);
	//
	bishop = new Piece(WHITE, BISHOP);
	this->placePiece(bishop, 5, 0);
	whiteTeam->recruitPiece(bishop);

	//- Queen --------------------------------------------=
	//
	Piece* queen = new Piece(WHITE, QUEEN);
	this->placePiece(queen, 3, 0);
	whiteTeam->recruitPiece(queen);
	
	//- King ---------------------------------------------=
	//
	Piece* king = new Piece(WHITE, KING);
	this->placePiece(king, 4, 0);
	whiteTeam->recruitPiece(king);
}

void GameManager::_setBlack() {
	//- Pawns --------------------------------------------=
	//
	for (int i = 0; i < 8; i++) {
		Piece* pawn = new Piece(BLACK, PAWN);
		this->placePiece(pawn, i, 6);
		blackTeam->recruitPiece(pawn);
	}

	//- Rooks --------------------------------------------=
	//
	Piece* rook = new Piece(BLACK, ROOK);
	this->placePiece(rook, 0, 7);
	blackTeam->recruitPiece(rook);
	//
	rook = new Piece(BLACK, ROOK);
	this->placePiece(rook, 7, 7);
	blackTeam->recruitPiece(rook);

	//- Knights ------------------------------------------=
	//
	Piece* knight = new Piece(BLACK, KNIGHT);
	this->placePiece(knight, 1, 7);
	blackTeam->recruitPiece(knight);
	//
	knight = new Piece(BLACK, KNIGHT);
	this->placePiece(knight, 6, 7);
	blackTeam->recruitPiece(knight);

	//- Bishops ------------------------------------------=
	//
	Piece* bishop = new Piece(BLACK, BISHOP);
	this->placePiece(bishop, 2, 7);
	blackTeam->recruitPiece(bishop);
	//
	bishop = new Piece(BLACK, BISHOP);
	this->placePiece(bishop, 5, 7);
	blackTeam->recruitPiece(bishop);

	//- Queen --------------------------------------------=
	//
	Piece* queen = new Piece(BLACK, QUEEN);
	this->placePiece(queen, 4, 7);
	blackTeam->recruitPiece(queen);
	
	//- King ---------------------------------------------=
	//
	Piece* king = new Piece(BLACK, KING);
	this->placePiece(king, 3, 7);
	blackTeam->recruitPiece(king);
}