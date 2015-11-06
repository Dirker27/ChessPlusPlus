#include <stdlib.h>
#include <stdio.h> //TODO [C++11] - Remove

#include "game_manager.h"
#include "logger.h"

/**
 * CONSTRUCTOR
 */
GameManager::GameManager() {
	this->game = new Game();
}

/**
 * DESTRUCTOR
 *
 * Member Memory to Destruct:
 *  - [1] Game Model Instance [Game]
 */
GameManager::~GameManager() {
	//- Log Imminent Deallocation ------------------------=
	//
	// TODO [C++11] - Switch to std::string stream
	char* s = (char*) malloc(sizeof(char) * 128);
	sprintf(s, "GameManager_GAME::[%lub]", sizeof(this->game));
	log_memory(s, false);
	free(s);

	delete(this->game);                          // [1]
}

bool GameManager::setupBoard() {
	bool b = this->game->flushGameState();

	this->_setWhite();
	this->_setBlack();

	return b;
}


void GameManager::_setWhite() {
    //- Pawns --------------------------------------------=
    //
    for (int i = 0; i < 8; i++) {
        Piece* pawn = new Piece(WHITE, PAWN);
        this->game->addPieceToGame(pawn, i, 1);
    }

    //- Rooks --------------------------------------------=
    //
    Piece* rook = new Piece(WHITE, ROOK);
    this->game->addPieceToGame(rook, 0, 0);
    //
    rook = new Piece(WHITE, ROOK);
    this->game->addPieceToGame(rook, 7, 0);

    //- Knights ------------------------------------------=
    //
    Piece* knight = new Piece(WHITE, KNIGHT);
    this->game->addPieceToGame(knight, 1, 0);
    //
    knight = new Piece(WHITE, KNIGHT);
    this->game->addPieceToGame(knight, 6, 0);

    //- Bishops ------------------------------------------=
    //
    Piece* bishop = new Piece(WHITE, BISHOP);
    this->game->addPieceToGame(bishop, 2, 0);
    //
    bishop = new Piece(WHITE, BISHOP);
    this->game->addPieceToGame(bishop, 5, 0);

    //- Queen --------------------------------------------=
    //
    Piece* queen = new Piece(WHITE, QUEEN);
    this->game->addPieceToGame(queen, 3, 0);
    
    //- King ---------------------------------------------=
    //
    Piece* king = new Piece(WHITE, KING);
    this->game->addPieceToGame(king, 4, 0);
}

void GameManager::_setBlack() {
    //- Pawns --------------------------------------------=
    //
    for (int i = 0; i < 8; i++) {
        Piece* pawn = new Piece(BLACK, PAWN);
        this->game->addPieceToGame(pawn, i, 6);
    }

    //- Rooks --------------------------------------------=
    //
    Piece* rook = new Piece(BLACK, ROOK);
    this->game->addPieceToGame(rook, 0, 7);
    //
    rook = new Piece(BLACK, ROOK);
    this->game->addPieceToGame(rook, 7, 7);

    //- Knights ------------------------------------------=
    //
    Piece* knight = new Piece(BLACK, KNIGHT);
    this->game->addPieceToGame(knight, 1, 7);
    //
    knight = new Piece(BLACK, KNIGHT);
    this->game->addPieceToGame(knight, 6, 7);

    //- Bishops ------------------------------------------=
    //
    Piece* bishop = new Piece(BLACK, BISHOP);
    this->game->addPieceToGame(bishop, 2, 7);
    //
    bishop = new Piece(BLACK, BISHOP);
    this->game->addPieceToGame(bishop, 5, 7);

    //- Queen --------------------------------------------=
    //
    Piece* queen = new Piece(BLACK, QUEEN);
    this->game->addPieceToGame(queen, 4, 7);
    
    //- King ---------------------------------------------=
    //
    Piece* king = new Piece(BLACK, KING);
    this->game->addPieceToGame(king, 3, 7);
}