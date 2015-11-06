#include <stdlib.h>
#include <stdio.h> //TODO [C++11] - Remove

#include "game.h"
#include "logger.h"

/**
 * CONSTRUCTOR
 */
Game::Game() {
    this->whiteTeam = new Roster(WHITE);
    this->blackTeam = new Roster(BLACK);
    this->gameBoard = new Board();

    //- Set Default Game States --------------------------=
    //
    this->playState    = NOT_STARTED;
    this->endGameState = NONE;

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
Game::~Game() {
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
 * Add a Piece to the Game.
 * 
 * Index in the Game Model's Data Structures accordingly.
 */
bool Game::addPieceToGame(Piece* piece) {
    // TODO: Support Piece-only impl
    return false;
}
bool Game::addPieceToGame(Piece* piece, int x, int y) {
    bool success = this->gameBoard->placePiece(piece, x, y);

    if (success) {
        piece->updateLocation(x, y);
    }

    return success;
}

/**
 * Update both the Board and the Piece with a new location
 *  IF the board deems it legal.
 * 
 * @return False iff space is out of bounds or occupied.
 */
bool Game::movePieceToLocation(Piece* piece, Location* loc) {
    return this->movePieceToLocation(piece, loc->x, loc->y);
}
bool Game::movePieceToLocation(Piece* piece, int x, int y) {
    bool success = this->gameBoard->placePiece(piece, x, y);
    
    if (success) {
        piece->updateLocation(x, y);
    }

    // Failures already logged at Board level. Would be excessive here.

    return success;
}