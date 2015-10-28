#ifndef GAME_H
#define GAME_H

#include "piece.h"
#include "roster.h"
#include "board.h"

/**
 * Is the game actively being played?
 */
enum PlayState {
    NOT_STARTED,
    IN_PROGRESS,
    COMPLETE
};

/**
 * Are we done yet?
 */
enum EndGameState {
    NONE,
    CHECK,
    CHECKMATE,
    STALEMATE
};

/**
 * The Virtial Game Model
 *
 * At this level, we don't care about the outside world. We're told to move
 *   pieces around the board and we do just that, provided they're legal. We
 *   will then calculate and update game state elements (In-Check, Current 
 *   Turn) accordingly.
 *   
 * If internal members were to be serialized and stored, you'd have a perfectly
 *   preserved game on de-serialization and load. And that's the plan for 
 *   later on.
 *
 * TODO: Write or import Serializer/Deserializer.
 *
 * @author Dirk Hortensius [Dirker27]
 */
class Game {
    private:
        //- States of the World --------------------------=
        //
        PlayState    playState;
        EndGameState endGameState;
        //TODO: Current Turn - Coming up in Component Migration
        // 
        Piece* selectedPiece;

        //- My Virtual Actors ----------------------------=
        // | ----------------/
        // | TODO: Convert to Smart Pointers
        // 
        // Pieces indexed in multiple data structures.
        //   (dealloc will be a nightmare without ARC)
        Roster* whiteTeam;
        Roster* blackTeam;
        Board*  gameBoard;

    public:
        //- (De)Allocate ---------------------------------=
        //
        Game() { /* TODO: Stub */ };
        ~Game() { /* TODO: Stub */ };

        //- Operations -----------------------------------=
        // | ---------/
        // | TODO: Convert to Params/Rets Smart Pointers
        //
        // Add a Piece
        bool addPieceToGame(Piece*) { /* TODO: Stub */ return true; };
        bool addPieceToGame(Piece*, int, int) { /* TODO: Stub */ return true; };
        //
        // Move a Piece
        bool movePieceToLocation(Piece*, Location*) { /* TODO: Stub */ return true; };
        bool movePieceToLocation(Piece*, int, int) { /* TODO: Stub */ return true; };
        //
        // Select a Piece
        Piece* selectPiece(Piece*) { /* TODO: Stub */ return NULL; };
        Piece* selectPieceAtLocation(Location*) { /* TODO: Stub */ return NULL; };
        Piece* selectPieceAtLocation(int, int) { /* TODO: Stub */ return NULL; };
        // 
        // Fetch Piece by Team/Classification
        // | TODO: Return Vectors
        struct list* getPiecesByType(PieceType) { /* TODO: Stub */ return NULL; };
        struct list* getPiecesByTypeAndTeam(PieceType, PieceTeam) { /* TODO: Stub */ return NULL; };
        //
        // Flush State
        bool flushGameState(void) { /* TODO: Stub */ return true; };

        
        //- Accessors ------------------------------------=
        // | --------/
        // | This is our Central Data Model, so we want to appropriately police
        // |   external access to members.
        //
        // playState: Read/Write (operated by Game Manager)
        PlayState getPlayState(void) { return this->playState; };
        void setPlayState(PlayState state) { this->playState = state; };
        //
        // endGame: Read-Only (used for Game Management)
        EndGameState getEndGame(void) { return this->endGameState; };
        //
        // selectedPiece: *Read-Only (used for Move Calculation)
        const Piece* getSelectedPiece(void) { return this->selectedPiece; };
        //
        // Game Components: *Read-Only (needed for render)
        const Roster* getWhiteTeam(void) { return this->whiteTeam; };
        const Roster* getBlackTeam(void) { return this->blackTeam; };
        const Board*  getGameBoard(void) { return this->gameBoard; };

};

#endif