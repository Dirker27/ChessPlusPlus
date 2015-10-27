#include <stdlib.h>
#include <stdio.h> //TODO [C++11] - Remove

#include "roster.h"
#include "logger.h"

/*
 * DUCT-TAPE - Piece
 */
typedef struct _PieceDt {
	Piece* piece;            // payload
	struct list_elem elem;   // list link
} PieceDt;

/**
 * CONSTRUCTOR
 */
Roster::Roster(PieceTeam team) {
	this->team = team;

	this->activeDuty = (struct list*) malloc(sizeof(struct list));
	list_init(this->activeDuty);

	this->benched = (struct list*) malloc(sizeof(struct list));
	list_init(this->benched);

	//- Log Successful Allocation ------------------------=
	//
	// TODO [C++11] - Switch to std::string stream
	char* s = (char*) malloc(sizeof(char) * 32);
	sprintf(s, "Roster::[%lub]", sizeof(this->team));
	log_memory(s, true);
	free(s);
}

/**
 * DESTRUCTOR
 * 
 * Member Memory to Destruct:
 *  - [1] Active Duty List [C expanding List]
 *    - [1.1] All Members inside Column
 *    - [1.2] List Duct-tape elements
 *    - [1.3] List Root
 *  - [2] Benched List [C expanding List]
 *    - [2.1] All Members inside Column
 *    - [2.2] List Duct-tape elements
 *    - [2.3] List Root
 */
Roster::~Roster() {
	//- Log Imminent Deallocation ------------------------=
	//
	// TODO [C++11] - Switch to std::string stream
	char* s = (char*) malloc(sizeof(char) * 32);
	sprintf(s, "Roster::[%lub]", sizeof(this->team));
	log_memory(s, false);
	// Don't free 's' yet, there's more logging to do.

	//- [1] Active Duty List -----------------------------=
	//
	// Log
	// ---	
	// |> TODO [C++11] - Switch to std::string stream
	sprintf(s, "List::[%lub]", sizeof(this->team));
	log_memory(s, false);
	//
	// Iterative Pop + Delete
	while(! list_empty(this->activeDuty)) {
		// Pop From List
		struct list_elem * e = list_pop_front(this->activeDuty);
		PieceDt * tape = list_entry(e, PieceDt, elem);
		//
		// Deallocate
		delete(tape->piece);                     // [1.1]
		free(tape);                              // [1.2]
	}
	// Delete List
	free(this->activeDuty);                      // [1.3]


	//- [2] Benched List ---------------------------------=
	//
	// Log
	// ---
	// |> TODO [C++11] - Switch to std::string stream
	sprintf(s, "List::[%lub]", sizeof(this->team));
	log_memory(s, false);
	free(s); // now we're done.
	// 
	// Iterative Pop + Delete
	while(! list_empty(this->benched)) {
		// Pop From List
		struct list_elem * e = list_pop_front(this->benched);
		PieceDt * tape = list_entry(e, PieceDt, elem);
		//
		// Deallocate
		delete(tape->piece);                     // [2.1]
		free(tape);                              // [2.2]
	}
	// Delete List
	free(this->benched);                         // [2.3]
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