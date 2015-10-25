#include <stdlib.h>

#include "board.h"

/**
 * CONSTRUCTOR
 */
Board::Board() {
	// TODO [Logger] - Board Alloc Start

	//- Allocate Primary Board ---------------------------=
	// | ---------------------
	// | Allocating as a Pointer->ArrayOfRows :: Row->ArrayOfColumnVals
	//
	// Array of Rows
	this->board = (Piece***) malloc(sizeof(Piece**) * BOARD_SIZE);
	//
	// All Rows get a Column
	for (int i = 0; i < BOARD_SIZE; i++) {
		this->board[i] = (Piece**) malloc(sizeof(Piece*) * BOARD_SIZE);
	}

	// TODO [Logger] - Board Alloc End
}

/**
 * DESTRUCTOR
 *
 * Member Memory to Destruct:
 *  - [1] Board Contents [2d Pointer Array]
 *    - [1.1] All Members inside Column
 *    - [1.2] Column Array of each Row
 *    - [1.3] Array of Rows in Board
 */
Board::~Board() {
	// TODO [Logger] - Board Dealloc Start

	//- [1] Deallocate Board -----------------------------=
	//
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			delete(board[i][j]);                 // [1.1]
		}
		free(board[i]);                          // [1.2]
	}
	free(board);                                 // [1.3]

	// TODO [Logger] - Board Dealloc End
}

/**
 * Place a Piece on the board.
 * 
 * If a space is in-bounds and empty, place the piece. Fail otherwise.
 *   Does NOT check for legality of piece's move. Only places it on the board.
 *
 * @return Successful Piece Placement
 */
bool Board::placePiece(Piece* p, int x, int y) {
	//- Legality Checks ----------------------------------=
	//
	// X-Bounds
	if (x < 0 || x > BOARD_SIZE) {
		// TODO [Logger] - Illegal Placement
		return false;
	}
	// Y-Bounds
	if (y < 0 || y > BOARD_SIZE) {
		// TODO [Logger] - Illegal Placement
		return false;
	}
	// Space Occupied
	if (this->board[x][y] != NULL) {
		// TODO [Logger] - Illegal Placement
		return false;
	}

	//- Place Piece --------------------------------------=
	//
	this->board[x][y] = p;

	return true;
}