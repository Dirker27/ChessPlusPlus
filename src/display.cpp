#include <iostream>

#include "display.h"
#include "game.h"
#include "piece.h"

using namespace std;

string _renderSpace(bool, Piece*);

/**
 * CONSTRUCTOR
 * 
 * TODO: [Milestone 3] Assign Rendering Mode and delegate renderers accordingly
 */
Display::Display() {
    this->RENDER_MODE = STATIC;
}

/**
 * Default Rendering Implementation
 *
 * Prints the Board to the terminal after a clear.
 */
void Display::renderGame(Game* game) {
    //- Clear --------------------------------------------=
    //
    for (int i = 0; i < 64; i++) {
        cout << "\n";
    }

    //- Draw Board ---------------------------------------=
    //
    const string border = "|||";
    const Board* board = game->getBoard();

    for (int y = 7; y >= 0; y--) {
        cout << border;

        for (int x = 0; x < 8; x++) {
            cout << _renderSpace(board->getPieceAtLocation(x, y));
        }

        cout << border;
    }
}

string _renderSpace(bool white, Piece* piece) {

}