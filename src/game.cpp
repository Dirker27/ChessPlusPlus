#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "board.h"
#include "piece.h"

Board* _init_game() {
	Board* b = new Board();
	Piece* p = new Piece(WHITE, PAWN);
	b->placePiece(p, 0, 0);

	return b;
}



void runGame() {
	Board* b = _init_game();

	bool shutdown = false;
	while (! shutdown) {
		// TODO
		Piece* p = new Piece(BLACK, PAWN);
		b->placePiece(p, 1, 1);

		shutdown = true;
	}

	delete(b);
}