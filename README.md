# ChessPlusPlus
Chess++ written in C++ all for You++

Author: Dirk Hortensius [Dirker27]

Language: C/C++

Platform: Linux Terminal

## What is it?
A Chess Game.

In your Terminal.

Networked.

To People.

## Why is this a Thing?
Once upon a time, a nerdy little boy, whose physical size could never honestly be classified as "little", fell in love <3. Like most little boys, he had affections for Lightsabers and anatomically impossibly porportioned girls in Japanese cartoons. However, it was not these COMPLETELY NORMAL THINGS that stole his heart; No - with the passion normally reserved for a life of Piracy, this boy fell in love with the C.

So he was pissed as f*** when he realized he'd gotten rusty at it.

Now, with the realization that it'd be nice to have a Chess game up in his terminal at work, he decided to do something about that.

## How is it Gonna get Built?
Well, here's the high-level plan. Planning/Scoping is still a new thing for some of the authors (shh... I know there's just one).

### Milestones
Think of each of these as a public release candidate.

#### Milestone 0: Single-Player Chess
<i> One is the lonliest number... </i>

Target Deadline: 2015-10-24

###### Keystone Feature
A playable game.

###### Gameplay
The game of chess is controlled by a single [1] user, who will enter moves for both sides. The game will properly identify the states of Check and Checkmate, as well as disallow illegal moves. On checkmate, the game will display a "win screen" and close on next keystroke.

###### User Interface
Entirely through a dedicated terminal window, running in the foreground. Piece movement/selection will be input via text in the terminal prompt. Game updates will be in the form of the terminal prompt itself. Board/Piece display will be present via text-art that will clear/redraw for each display frame. The board borders will be drawn in ASCII, and the Pieces will be drawn as single ASCII characters.

Stretch Goal: Color Coding.

###### Networking
None. This is a local single-player instance.

###### Coding/Design Paradigm
The language will be C++, but a large portion of the paradigms used will be C. Classes and inheritence will be utilized heavily (would be an epic pain otherwise), but most of the std: libraries will be largely ignored. Instead we will be favoring more C-style pointers and structs for simpler objects.


#### Milestone 1: Two Player Chess via P2P Networking
<i> Better with friends! </i>

<font color="red"><b> MVP </b></font>

Target Deadline: 2015-10-26

###### Keystone Feature
Ability to play against another user over a network.

###### Gameplay
The game is controlled by up to two [1-2] users. In Single-Player Mode, a user can control both sides. In Two-Player Mode, the users will only be able to control their respective side, and will operate the game from their own different clients. This game will be played over a network connection. The game will properly identify the states of Check and Checkmate, as well as disallow illegal moves. On checkmate, the appropriate "win/lose screen" will display to the respective user. The game can then be either reset or exited based on the consensus of the players. A game can also end by forfeit if a player enters the correct option. A game will end in a draw if a user closes the connection or forces a stalemate.

###### User Interface
The clients will operate entirely through a terminal window. The board/pieces will still be entirely ASCII. Piece selection/movement will still be entirely handled via terminal prompt. The display will still clear/redraw for each display frame.

###### Networking
A user can connect to an opponent who is running their own game in a "listen" state by entering their opponent's IP:Socket address (note: this could still be the same machine). This will then open a TCP/HTTP-1.1 connection that will send game update packets between the clients. If either connection socket is closed, intentionally or accidentally, the game will be interpreted as a draw.

###### Coding/Design Paradigm
This will still be C++, and will adopt the 'proper' paradigms for the language. Namely, this will focus on using conventions and libraries brought in by the C++11 release.

See: (http://www.stroustrup.com/C++11FAQ.html) (and for the love of god, could someone please direct Bjarne to a css library?)


#### Milestone 2: Matchmaking - A Usable User Experience
<i> Yeah, your friends use it - but now they'll actually like it. </i>

Target Deadline: TBD

###### Keystone Features
- A Centralized Matchmaking Server.
- A Better UI
- "Roll-Back" View

###### Gameplay
[Mostly the same as Milestone 1] Offline Single-Player combating no Artificial Intelligence. Online Multiplayer against crappy Human Intelligence. Win/Lose Screen on Checkmate. A game MAY end in a draw if the connection is closed, and WILL end in a draw if a stalemate is forced.
[New] The ability for players to "roll-back" to previous moves and view previous states of the game. Players will also have the ability to find opponents on a centralized server for matchmaking.

###### User Interface
The clients will operate through a terminal window, but the window does not have to be dedicated. The game can be pushed to the background, transferred to another terminal, or interrupted. SIGINT will be interpreted as a forfeit, and the game will end gracefully. The board/pieces will still be drawn in UTF-8/ASCII, but will be responsive to the size of the window (If all pieces can now be 2x2 characters wide, then expand the board appropriately). Piece selection/movement will now support directional arrows and other non-alphanumeric keystrokes as a control mechanism. The display will no longer clear/redraw for each display frame, but rather update the currently drawn board. "Selected" pieces and their legal moves will now be highlighted.

###### Networking
A User will connect to a centralized server and sign in with a username (no account/password). They will then be directed to a "waiting room" where they can select an opponent and start a match. This will maintain a TCP/HTTP-1.1 connection between the clients, relayed through the server. On match start, a game will be assigned a "Match ID" for logging and transactional purposes. Game updates will be sent similar to P2P mode, but will also be recorded by the server, and stored for transactional purposes. In the event of a disconnect, the game result will be tentatively stored as a Draw. Users can resume a disconnected game from the waiting room if they are able to provide the original Match ID - at which point the most recent stored game state will be loaded and gameplay resumed.
P2P gameplay will still be supported, but cannot backed-up for resume.

###### Coding/Design Paradigm
While still using a C++11 paradigm base, we will start moving in some C++14 concepts and libraries. For educational (mostly curiousity) reasons.


#### Milestone 3: Voyeurism
<i> Vicariously I live while the whole world dies. </i>

Target Deadline: TBD

###### Keystone Feature
Spectator Mode.

###### Gameplay
Just like in Milestone 2, a user will be able to sign in and play a game. Now, however, they can also observe ongoing matches as a Spectator.

Stretch Goal: Ability to spectate old games via roll-back.

###### User Interface
Player LAF is identical to Milestone 2, but now they will be notified if their match is being spectated.

Spectators will view the game through their own terminal client, using the same ASCII LAF as the Player Experience.

###### Networking
From the network's standpoint, a spectator should be treated as a player receiving game updates. There will not be input accepted from this "Player". Anyone joining a match that's in-progress with both players present will be automatically determined a spectator.

P2P matches cannot be spectated. This can be used for "private" matches.

###### Coding/Design Paradigm
All hail thine incremented C.


#### Milestone 4: Something to bring home to the Parents
<i> Let's polish that turd! </i>

Target Deadline: 2038-06-66

TBD. I'd like to move in some real GUI elements so I can play with C++'s GL libraries. Too far out of scope at the moment to be worth fleshing out.


### Completion
Critical Milestones correspond to definitions above.

    [ ] == Not Started
    [/] == Blocked (want to start)
    [w] == Work-In-Progress
    [-] == Done-ish
    [x] == Done-Done

    - [ ] 0.0: Single-Player Chess
      - [x] Remember how to compile things in C/C++
        - [x] Makefile
      - [x] Base Implementation - Can Place Pieces in Code
        - [x] Location and Rendering Attrs broken out
        - [x] Can Deallocate Responsibly via Destructor
        - [x] Basic Logger Utility
        - [ ] Piece placement from Game Manager.
      - [ ] Draw Board
        - [ ] Draw Board
        - [ ] Draw Pieces
        - [ ] Colorize (if possible)
      - [ ] Interactive Piece Placement
      - [ ] Legal/Illegal Piece Movement
        - [ ] Create Piece Types
        - [ ] Movement Rules Definition
        - [ ] Capture Rules Definition (Basic)
      - [ ] Game Implementation
        - [ ] Checkmate Detection
        - [ ] Check Detection
        - [ ] Complete Rules Definition
      
    - [ ] 0.5: C++11 Refactor
      - [ ] Class Constants
      - [ ] std::Arrays - If applicable
      - [ ] Homebrew Unit Testing

    - [ ] 1.0: Two-Player Chess via P2P Networking
      - [ ] Spike: P2P or Central Server?
      - [ ] Task-Out

    - [ ] 2.0: Matchmaking - A Usable User Experience
      - [ ] Task-Out

    - [ ] 3.0: Voyeurism
      - [ ] Task-Out

    - [ ] 4.0: Something to bring home to the Parents
      - [ ] Figure out what to make
      - [ ] Task-Out
      - [ ] Put a Ring on it