#include <stdlib.h>

#include "piece.h"

int incrementalId = 0;

/**
 * CONSTRUCTOR
 */
Piece::Piece(PieceTeam team, PieceType type) {
	this->team = team;
	this->type = type;

	this->id = incrementalId++;

	this->location = (Location*) malloc(sizeof(Location));
	this->location-> x = -1;
	this->location-> y = -1;

	this->avatar = (Avatar*) malloc(sizeof(Avatar));
	this->avatar->icon = 'p';

	// TODO [Logger] - Allocated Piece
}

/**
 * DESTRUCTOR
 *
 * Member Memory to Destruct:
 *  - [1] Location
 *  - [2] Avatar
 */
Piece::~Piece() {
	// TODO [Logger] - Deallocating Piece

	free(this->location);                        // [1]
	free(this->avatar);                          // [2]
}