#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "chess_master.h"

ChessMaster* _init_game() {
	ChessMaster* c = new ChessMaster();
	c->startGame();

	return c;
}

void launchGame() {
	ChessMaster* c = _init_game();

	bool shutdown = false;
	while (! shutdown) {
		bool gameCanContinue = c->nextTurn();

		// TODO [Interactive] - Properly handle shutdown cases.
		shutdown = gameCanContinue || true;
	}

	delete(c);
}