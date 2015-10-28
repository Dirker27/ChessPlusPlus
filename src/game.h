#ifndef GAME_H
#define GAME_H

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

};

#endif