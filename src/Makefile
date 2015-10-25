CC = g++
CFLAGS=-Wall -Werror

GAME_ASSETS=board.h piece.h avatar.h location_2d.h

all: chess

chess: main.cpp game.o logger.o
	$(CC) $(CFLAGS) main.cpp game.o piece.o board.o logger.o -o ./chess

game.o: game.cpp $(GAME_ASSETS) logger.o
	$(CC) $(CFLAGS) -c game.cpp board.cpp piece.cpp 

logger.o: logger.cpp
	$(CC) $(CFLAGS) -c logger.cpp

clean:
	rm -f *.o chess

