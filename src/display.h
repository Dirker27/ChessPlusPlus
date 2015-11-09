#ifndef DISPLAY_H
#define DISPLAY_H

#include "game.h"

/**
 * For much later. Am I clearing/printing each frame, or updating in a
 *   continuous stream?
 */
enum RenderMode {
    STATIC,
    DYNAMIC
};

/**
 * Responsible for Displaying the Game World to the User.
 *   Our "View" in M-V-C
 * 
 * If we stick to M-V-C paradigm, should only need to look at the game model
 *   to know what to draw. So that's exactly what this thing cares about.
 *   "Tell me what I need to start drawing, and I'll figure out how."
 * 
 * @author Dirk Hortensius [Dirker27]
 */
class Display {
    private:
        RenderMode RENDER_MODE;

    public:
        //- (De)Allocate -------------------------------------=
        // | -----------/
        // | TODO: Set Render Mode by constructor param
        //
        Display(void);
        ~Display(void) { /* TODO: Stub */ };

        //- Operations ---------------------------------------=
        // | ---------/
        // | TODO: Convert to Shared Pointer
        //
        void renderGame(Game*);
};


#endif