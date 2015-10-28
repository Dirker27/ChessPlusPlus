#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "game.h"

/**
 * Manages a Game Instance
 *
 * The Game Object is just the collection of objects to represent the virtual
 *   virtual conflict. The Game Manager is how we link it to the world.
 * 
 * Essentially an abstraction layer for the true(er) model. Responsible for:
 *   - Facilitating Setup
 *   - Calculating if a piece has entered Check
 *   - 
 *
 * @author Dirk Hortensius [Dirker27]
 */
class GameManager {
	private:
		// Core Model
		Game* game;

		// TODO: Game Logic Plugins (Check Calculator, Move Calculator, etc)

		//- Helper Functions -----------------------------=
		// | ---------------/
		// | TODO: This is temporary. Move out w/ Business Logic Plugins.
		// 
		void _setWhite(void);
		void _setBlack(void);

	public:
		//- (De)Allocation -------------------------------=
		//
		GameManager(void);
		~GameManager(void);

		//- Operations -----------------------------------=
		// 
		bool setupBoard(void);

		// Accessor
		Game* getGame(void) { return this->game; };
};

#endif