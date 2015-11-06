#ifndef USER_INPUT_HANDLER_H
#define USER_INPUT_HANDLER_H

/**
 * User-Facing Layer of the Controller
 * 
 * Translates Raw Input into a User Gesture
 *
 * @author Dirk Hortensius [Dirker27]
 */
class UserInputHandler {
    private:
        // I/O Sockets
        int inputStream;
        int outputStream;
        
    public:
        //- (De)Allocate ---------------------------------=
        //
        UserInputHandler(void) { /* TODO: Stub */ };
        ~UserInputHandler(void) { /* TODO: Stub */ };

        //- Operations -----------------------------------=
        // | ---------/
        // | TODO: Convert to Strings
        //
        char* getInputString(void) { /* TODO: Stub */ return NULL; };
        char* getInputStringFromPrompt(char* prompt) { /* TODO: Stub */ return NULL; };
};

#endif