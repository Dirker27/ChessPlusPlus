#include <stdlib.h>
#include <stdio.h> //TODO [C++11] - Remove

#include "board.h"
#include "logger.h"

/**
 * CONSTRUCTOR
 */
Board::Board() {
    this->size = DEFAULT_BOARD_SIZE;

    //- Allocate Primary Board ---------------------------=
    // | ---------------------
    // | Allocating as a Pointer->ArrayOfRows :: Row->ArrayOfColumnVals
    //
    // Array of Rows
    this->board = (Piece***) malloc(sizeof(Piece**) * this->size);
    //
    // All Rows get a Column
    for (int i = 0; i < size; i++) {
        this->board[i] = (Piece**) malloc(sizeof(Piece*) * this->size);
    }

    //- Log Successful Allocation ------------------------=
    //
    // TODO [C++11] - Switch to std::string stream
    char* s = (char*) malloc(sizeof(char) * 32);
    sprintf(s, "Board::[%i]x[%i]::Piece", this->size, this->size);
    log_memory(s, true);
    free(s);
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
    //- Log Imminent Deallocation ------------------------=
    //
    // TODO [C++11] - Switch to std::string stream
    char* s = (char*) malloc(sizeof(char) * 32);
    sprintf(s, "Board::[%i]x[%i]::Piece", this->size, this->size);
    log_memory(s, false);
    free(s);

    //- [1] Deallocate Board -----------------------------=
    //
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            delete(board[i][j]);                 // [1.1]
        }
        free(board[i]);                          // [1.2]
    }
    free(board);                                 // [1.3]
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
    if (x < 0 || x > this->size) {
        log_action("[Board::placePiece] Cannot place a piece at location. Out of Bounds");
        return false;
    }
    // Y-Bounds
    if (y < 0 || y > this->size) {
        log_action("[Board::placePiece] Cannot place a piece at location. Out of Bounds");
        return false;
    }
    // Space Occupied
    if (this->board[x][y] != NULL) {
        log_action("[Board::placePiece] Cannot place a piece at location. Space is Occupied.");
        return false;
    }

    //- Place Piece --------------------------------------=
    //
    this->board[x][y] = p;

    return true;
}


/**
 * Move a Piece to a new Location
 *
 * @return False iff no Piece exists at origin location.
 */
bool Board::movePieceFromLocationToLocation(Location* origin, Location* destination) {
    return this->movePieceFromLocationToLocation(
        origin->x, origin->y, 
        destination->x, destination->y);
}
bool Board::movePieceFromLocationToLocation(int ox, int oy, int dx, int dy) {
    Piece* toMove = this->getPieceAtLocation(ox, oy);
    if (toMove == NULL) {
        return false;
    }

    this->board[ox][oy] = NULL;
    this->board[dx][dy] = toMove;

    return true;
}


/**
 * Gets Piece At Location
 */
Piece* Board::getPieceAtLocation(Location* location) {
    return this->getPieceAtLocation(location->x, location->y);
}
Piece* Board::getPieceAtLocation(int x, int y);
        //- Legality Checks ----------------------------------=
    //
    // X-Bounds
    if (x < 0 || x > this->size) {
        log_action("[Board::placePiece] Cannot place a piece at location. Out of Bounds");
        return false;
    }
    // Y-Bounds
    if (y < 0 || y > this->size) {
        log_action("[Board::placePiece] Cannot place a piece at location. Out of Bounds");
        return false;
    }
    // Space Occupied
    if (this->board[x][y] != NULL) {
        log_action("[Board::placePiece] Cannot place a piece at location. Space is Occupied.");
        return false;
    }

    //- Place Piece --------------------------------------=
    //
    this->board[x][y] = p;

    return true;
}