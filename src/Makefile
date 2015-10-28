CC=gcc
CPP=g++
CFLAGS=-Wall -Werror

DRIVER_O=main.o
LAUNCH_O=launcher.o
GAME_O=game_manager.o chess_master.o
COMP_O=board.o piece.o roster.o
UTIL_O=logger.o list.o

all: chess

# Final Executable Build
#   Dynamically link .o files here.
chess: logging linked_list components game launch driver
	$(CPP) $(CFLAGS) $(DRIVER_O) $(LAUNCH_O) $(GAME_O) $(COMP_O) $(UTIL_O) -o ./chess

# The Main Driver / CLI Interpreter
#   Compile Dependencies:
#     main.cpp
#     |- launcher.h
driver: main.cpp launch
	$(CPP) $(CFLAGS) -c main.cpp

# Resource Loader / Game Launcher
#   Compile Dependencies:
#     launcher.cpp
#     |- game_manager.h
#       |- roster.h
#       |- board.h
launch: launcher.cpp game
	$(CPP) $(CFLAGS) -c launcher.cpp

# Game Business Logic
#   Compile Dependencies:
#     game_manager.cpp
#     |- roster.h
#     |  |- list.h
#     |  |- piece.h
#     |- board.h
#     |  |- piece.h
#     |- logger.h
game: game_manager.cpp chess_master.cpp components logging
	$(CPP) $(CFLAGS) -c game_manager.cpp chess_master.cpp

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
components: roster.cpp piece.cpp board.cpp game.cpp logging linked_list
	$(CPP) $(CFLAGS) -c roster.cpp piece.cpp board.cpp

# System Logging Utilities
#   Compile Dependencies:
#     logger.cpp
#     |- logger.h
logging: logger.cpp 
	$(CPP) $(CFLAGS) -c logger.cpp

# AUXILARY DATA STRUCTURES
#   Compile Dependencies:
#     list.c
#     |- list.h
linked_list: list.cpp
	$(CPP) $(CFLAGS) -c list.cpp

clean:
	rm -f *.o chess
