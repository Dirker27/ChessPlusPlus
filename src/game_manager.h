#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "roster.h"
#include "board.h"

/**
 * Who's turn is it?
 */
enum TurnState {
	WHITE_MOVE,
	BLACK_MOVE
};

/**
 * Are we done yet?
 */
enum EndGameState {
	NONE,
	CHECK,
	CHECKMATE,
	STALEMATE
};

/**
 * Manages a Game Instance
 * 
 * Responsible for:
 *   - Initiating a Player's turn
 *   - Moving the Pieces on the Board
 *   - Determining if endgame conditions have been met
 */
class GameManager {
	private:
		// Game Data
		Roster* whiteTeam;
		Roster* blackTeam;
		Board*  gameBoard;

		// Game State
		TurnState turnState;
		EndGameState endGameState;

	public:
		//- (De)Allocation -------------------------------=
		//
		GameManager(void);
		~GameManager(void);

		//- Operations -----------------------------------=
		//
		bool nextTurn(void);

		//- Accessors ------------------------------------=
		//
		TurnState getTurnState(void) { return this->turnState; };
		EndGameState getEndGameState(void) { return this->endGameState; };
};

#endif