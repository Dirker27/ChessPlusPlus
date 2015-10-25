#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "game_manager.h"
#include "logger.h"

GameManager* _init_game() {
	GameManager* g = new GameManager();
	g->startGame();
	
	return g;
}

void launchGame() {
	GameManager* g = _init_game();

	bool shutdown = false;
	while (! shutdown) {
		bool gameCanContinue = g->nextTurn();

		// TODO [Interactive] - Properly handle shutdown cases.
		shutdown = gameCanContinue || true;
	}

	delete(g);
}