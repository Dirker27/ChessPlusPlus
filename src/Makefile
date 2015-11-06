CPP=g++
CFLAGS=-Wall -Werror
IPATH=-I include/

DRIVER_O=main.o
LAUNCH_O=launcher.o
GAME_O=game_manager.o chess_master.o
COMP_O=board.o piece.o roster.o game.o
UTIL_O=logger.o list.o

all: chess

# Final Executable Build
#   Dynamically link .o files here.
chess: logging linked_list components game launch driver
	$(CPP) $(CFLAGS) $(IPATH) $(DRIVER_O) $(LAUNCH_O) $(GAME_O) $(COMP_O) $(UTIL_O) -o ./chess

# The Main Driver / CLI Interpreter
#   Compile Dependencies:
#     main.cpp
#     |- launcher.h
driver: main.cpp launch
	$(CPP) $(CFLAGS) $(IPATH) -c main.cpp

# Resource Loader / Game Launcher
#   Compile Dependencies:
#     launcher.cpp
#     |- game_manager.h
#       |- roster.h
#       |- board.h
launch: launcher.cpp game
	$(CPP) $(CFLAGS) $(IPATH) -c launcher.cpp

# Game Business Logic
#   Compile Dependencies:
#     game_manager.cpp
#     |- roster.h
#     |  |- list.h
#     |  |- piece.h
#     |- board.h
#     |  |- piece.h
#     |- logger.h
game: game/game_manager.cpp game/chess_master.cpp components logging
	$(CPP) $(CFLAGS) $(IPATH) -c game/game_manager.cpp game/chess_master.cpp

# Game Components
#   Compile Dependencies:
#     roster.cpp
#     |- list.h
#     |- piece.h
#     |  |- location_2d.h **
#     |  |- avatar.h **
#     |  |- logger.h
#     |- logger.h
#     piece.cpp 
#     |- location_2d.h **
#     |- avatar.h **
#     |- logger.h
#     board.cpp
#     |- piece.h
#     |- logging.h
components: game/roster.cpp game/piece.cpp game/board.cpp game/game.cpp logging linked_list
	$(CPP) $(CFLAGS) $(IPATH) -c game/roster.cpp game/piece.cpp game/board.cpp game/game.cpp

util: logging linked_list

# System Logging Utilities
#   Compile Dependencies:
#     logger.cpp
#     |- logger.h
logging: util/logger.cpp 
	$(CPP) $(CFLAGS) $(IPATH) -c util/logger.cpp

# AUXILARY DATA STRUCTURES
#   Compile Dependencies:
#     list.c
#     |- list.h
linked_list: util/list.cpp
	$(CPP) $(CFLAGS) $(IPATH) -c util/list.cpp

clean:
	rm -f *.o chess
