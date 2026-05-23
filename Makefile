CC = g++

CFLAGS = -Wall

LIBS = -lraylib -lopengl32 -lgdi32 -lwinmm

OBJ = main.o player.o track.o

OUT = jogo

all: $(OUT)

$(OUT): $(OBJ)
	$(CC) $(OBJ) -o $(OUT) $(LIBS)

main.o: main.cpp player.hpp track.hpp
	$(CC) -c main.cpp $(CFLAGS)

player.o: player.cpp player.hpp track.hpp
	$(CC) -c player.cpp $(CFLAGS)

track.o: track.cpp track.hpp
	$(CC) -c track.cpp $(CFLAGS)

clean:
	del *.o
	del $(OUT).exe
