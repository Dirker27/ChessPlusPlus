CC = g++
CFLAGS=-Wall -Werror

GAME_ASSETS=board.h piece.h

all: chess

chess: main.cpp game.o
	$(CC) $(CFLAGS) main.cpp game.o piece.o board.o -o ./chess

game.o: game.cpp $(GAME_ASSETS)
	$(CC) $(CFLAGS) -c game.cpp board.cpp piece.cpp

clean:
	rm -f *.o chess

