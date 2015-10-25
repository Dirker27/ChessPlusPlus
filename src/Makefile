CC=gcc
CPP=g++
CFLAGS=-Wall -Werror

GAME_ASSETS=board.h piece.h avatar.h location_2d.h

all: chess

chess: main.cpp launcher.o
	$(CPP) $(CFLAGS) main.cpp launcher.o game_manager.o logger.o list.o -o ./chess

launcher.o: launcher.cpp game logger.o
	$(CPP) $(CFLAGS) -c launcher.cpp game_manager.o logger.o

game: game_manager.cpp roster.cpp components list.o
	$(CPP) $(CFLAGS) -c game_manager.cpp roster.cpp

components: piece.cpp board.cpp logger.o
	$(CPP) $(CFLAGS) -c board.cpp piece.cpp

logger.o: logger.cpp
	$(CPP) $(CFLAGS) -c logger.cpp

list.o: list.c
	$(CC) $(CFLAGS) -c list.c

clean:
	rm -f *.o chess

