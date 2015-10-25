#ifndef PIECE_H
#define PIECE_H

#include "location_2d.h"
#include "avatar.h"

enum PieceTeam {
	BLACK,
	WHITE
};

enum PieceType {
	PAWN,
	KNIGHT,
	BISHOP,
	ROOK,
	QUEEN,
	KING
};

/**
 * An Arbitrary Game Piece
 * 
 * A bare-bones implementatoin that can be placed on the board and rendered.
 * 
 * Piece-specific rules (ie: Pawn v Knight) will be defined in their respective
 *   subclasses for how they interpret movement and capturing.
 */
class Piece {
	private:
		//- Piece Attributes -----------------------------=
		//
		int id;
		PieceTeam team;
		PieceType type;
		Location* location;

		//- Rendering Attributes -------------------------=
		//
		Avatar* avatar;
		
	public:
		//- (De)Allocation -------------------------------=
		//
		Piece(PieceTeam, PieceType);
		~Piece(void);

		//- Accessors ------------------------------------=
		//
		int getId(void) {return this->id; };
		PieceTeam getTeam(void) { return this->team; };
		PieceType getType(void) { return this->type; };
};

#endif