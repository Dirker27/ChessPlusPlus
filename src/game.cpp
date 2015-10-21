#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "board.h"
#include "piece.h"

void runGame() {
	Board* b = new Board();
	Piece* p = new Piece(0);

	bool shutdown = false;
	while (! shutdown) {
		// TODO
		b->placePiece(p, 0, 0);

		shutdown = true;
	}
}