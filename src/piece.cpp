#include <stdlib.h>
#include <stdio.h> //TODO [C++11] - Remove

#include "piece.h"
#include "location_2d.h"
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

/**
 * Move the piece's location to the designated spot
 *
 * Uptates internal location field for movement calculations
 */
void Piece::updateLocation(int x, int y) {
	this->location->x = x;
	this->location->y = y;
}

/**
 * Determine what spaces this piece can legally move to without capturing
 *   an opposing piece.
 *
 * A Legal movement location cannot result in the host team being put in check.
 *
 * @return An unbounded list of legal movement locations
 */
struct list* Piece::findMovementLocations() {
	struct list* movementLocations = (struct list*) malloc(sizeof(list));
	list_init(movementLocations);

	// TODO [Interactive Movement]

	return movementLocations;
}

/**
 * Determine if and where a capture is available for this piece.
 * 
 * A Legal capture location cannot result in the host team being put in check.
 * 
 * @return An unbounded list of legal capture locations
 */
struct list* Piece::findCaptureLocations() {
	struct list* captureLocations = (struct list*) malloc(sizeof(list));
	list_init(captureLocations);

	// TODO [Interactive Movement]

	return captureLocations;
}