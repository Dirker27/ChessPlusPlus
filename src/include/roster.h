#ifndef ROSTER_H
#define ROSTER_H

#include "list.h"
#include "piece.h"

class Roster {
	private:
		PieceTeam team;
		struct list* activeDuty;
		struct list* benched;
		int _netSize;

	public:
		//- (De)Allocation -------------------------------=
		//
		Roster(PieceTeam);
		~Roster();

		//- Operations -----------------------------------=
		//
		bool recruitPiece(Piece*);
		bool benchPiece(int);
		bool benchPiece(Piece*);
		bool resurrectPiece(int);
		bool resurrectPiece(Piece*);

		//- Accessors ------------------------------------=
		//
		struct list* getAllPieces(void);
		struct list* getAllActivePieces(void) { return this->activeDuty; };
		struct list* getAllBenchedPieces(void) { return this->benched; };
		PieceTeam getTeam(void) { return this->team; };
};

#endif