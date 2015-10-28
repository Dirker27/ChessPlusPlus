#ifndef USER_CONTROLLER_H
#define USER_CONTROLLER_H

#include "user_input_handler.h"

/**
 * The Game-Facing Layer of the Contoller.
 * 
 * Translates User Gestures into Desired Game Actions
 *
 * @author Dirk Hortensius [Dirker27]
 */
class UserController {
    private:
        // TODO: Convert to Unique Pointer
        UserInputHandler* inputHandler;

    public:
        //- (De)Allocate ---------------------------------=
        //
        UserController(void) { /* TODO: Stub */ };
        ~UserController(void) { /* TODO: Stub */ };

        //- Operations -----------------------------------=
        // | ---------/
        // | TODO: Return Smart Pointer
        // 
        // Action-Oriented Prompts
        Location* askForPieceLocation(void) { /* TODO: Stub */ return NULL; };
        Location* askForMoveLocation(void) { /* TODO: Stub */ return NULL; };
};

#endif