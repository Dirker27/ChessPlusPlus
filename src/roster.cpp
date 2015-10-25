#include <stdlib.h>
#include <stdio.h> //TODO [C++11] - Remove

#include "roster.h"
#include "logger.h"

/*
 * DUCT-TAPE - Piece
 */
typedef struct _PieceDt {
	struct Piece* piece;     // payload
	struct list_elem elem;   // list link
} PieceDt;

/**
 * CONSTRUCTOR
 */
Roster::Roster(PieceTeam team) {
	// TODO
}

/**
 * DESTRUCTOR
 * 
 * Member Memory to Destruct:
 *  - [1] Active Duty List [C expanding List]
 *  - [2] Benched List [C expanding List]
 */
Roster::~Roster() {
	// TODO
}


/**
 * Add a Piece to the Active Duty Roster
 * 
 * Preconditions:
 *   - The Piece must NOT be on this team's roster, benched or active.
 *   - The Piece cannot be a Member of the Opposing team.
 *
 * @return True iff Success
 */
bool Roster::recruitPiece(Piece* piece) {
	// TODO
	return true;
}

/**
 * Bench a Piece - by Piece ID
 *
 * Preconditions:
 *   - The Piece is on this team's Active Duty roster;
 *
 * @return True iff Success
 */
bool Roster::benchPiece(int pieceId) {
	// TODO
	return true;
}

/**
 * Bench a Piece - by Piece Object
 *
 * Preconditions:
 *   - The Piece is on this team's Active Duty roster;
 *
 * @return True iff Success
 */
bool Roster::benchPiece(Piece* piece) {
	// TODO
	return true;
}

/**
 * Bring back a Piece - by Piece ID
 *
 * Preconditions:
 *   - The Piece is on this team's Active Duty roster;
 *
 * @return True iff Success
 */
bool Roster::resurrectPiece(int pieceId) {
	// TODO
	return true;

}
/**
 * Bring back a Piece - by Piece Object
 *
 * Preconditions:
 *   - The Piece is on this team's Active Duty roster;
 *
 * @return True iff Success
 */
bool Roster::resurrectPiece(Piece* piece) {
	// TODO
	return true;
}

/**
 * Get a List of all pieces on this team. Active Duty AND Benched.
 * 
 * @return Master List. Will never be null.
 */
struct list* getAllPieces(void) {
	struct list* master = (struct list*) malloc(sizeof(list));

	// TODO

	return master;
}