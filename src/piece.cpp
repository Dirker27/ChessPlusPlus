#include <stdlib.h>
#include <stdio.h> //TODO [C++11] - Remove

#include "piece.h"
#include "logger.h"

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

	//- Log Successful Allocation ------------------------=
	//
	// TODO [C++11] - Switch to std::string stream
	char* s = (char*) malloc(sizeof(char) * 32);
	sprintf(s, "Piece::%i", this->id);
	log_memory(s, true);
	free(s);
}

/**
 * DESTRUCTOR
 *
 * Member Memory to Destruct:
 *  - [1] Location
 *  - [2] Avatar
 */
Piece::~Piece() {
	//- Log Imminent Deallocation ------------------------=
	//
	// TODO [C++11] - Switch to std::string stream
	char* s = (char*) malloc(sizeof(char) * 32);
	sprintf(s, "Piece::%i", this->id);
	log_memory(s, false);
	free(s);

	free(this->location);                        // [1]
	free(this->avatar);                          // [2]
}