#ifndef CHESS_MASTER_H
#define CHESS_MASTER_H

#include "game_manager.h"
#include "display.h"
#include "user_controller.h"

/**
 * Master Game Runner
 * 
 * Responsibilities include:
 *   - Prompting Users for Input
 *   - Sending Game Commands to the internal models
 *   - Calling for Render Passes
 *   - Handling any rejected moves gracefully, notifying the user.
 *
 * @author Dirk Hortensius [Dirker27]
 */
class ChessMaster {
    private:
        //- MVC Components -------------------------------=
        // | -------------/
        // | TODO: Convert to Smart Pointers
        // 
        // Model
        GameManager* game;
        // View
        Display* display;
        // Controller
        UserController* controller;

    public:
        //- (De)Allocation -------------------------------=
        //
        ChessMaster(void);
        ~ChessMaster(void);

        //- Operations -----------------------------------=
        //
        bool startGame(void);
        bool resetGame(void);
        bool nextTurn(void);        
};

#endif