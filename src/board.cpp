#include <stdlib.h>

#include "board.h"

Board::Board() {
	this->size = 8;
	this->board = (Piece***) malloc(sizeof(Piece*) * size);
	for (int i=0; i<this->size; i++) {
		this->board[i] = (Piece**) malloc(sizeof(Piece) * size);
	}
}

void Board::placePiece(Piece* p, int x, int y) {
	if (x < 0 || x > this->size) { return; }
	if (y < 0 || y > this->size) { return; }

	this->board[x][y] = p;
}