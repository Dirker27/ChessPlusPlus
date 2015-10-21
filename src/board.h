#ifndef BOARD_H
#define BOARD_H

#include "piece.h"

class Board {
	private:
		int size;
		Piece*** board;

	public:
		Board(void);
		void placePiece(Piece*, int, int);

};

#endif