#ifndef BOARD_H
#define BOARD_H

#include "piece.h"

const int BOARD_SIZE = 8;    // TODO [C++11] - Move to static class constant

/**
 * The Primary Game Board
 * 
 * Maintains the Locational Relationship of Pieces that are currently in play.
 * 
 * Not intended to be the master collection of pieces. Rather, the representation
 *   of where these pieces exist in the 2-dimensional game space. Intended to be
 *   quickly determine relative locations like "Who's on my Northeast Corner?".
 * 
 * The core "board" object is being stored as a Pointer, rather than a 2-D array,
 *   in order to optimize memory allocation.
 *   
 *   NOTE: If we stored board as a 2D array - board[][], passing board[n][n] as a
 *     Parameter would force us to allocate n^2 of memory from the STACK, where
 *     n is an arbitrary board width. For our 8-wide chess board, this would mean
 *     allocating 64 piece pointers (64 * int_32); in contrast to a single board
 *     pointer (1 * int_32) when we pass board as a pointer, while the actual
 *     8x8 board in the HEAP remains un-replicated.
 */
class Board {
	private:
		Piece*** board;

	public:
		//- (De)Allocation -------------------------------=
		//
		Board(void);
		~Board(void);

		//- Actions --------------------------------------=
		//
		bool placePiece(Piece*, int, int);
};

#endif