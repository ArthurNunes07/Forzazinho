CC = g++

CFLAGS = -Wall -std=c++11 -Iinclude

LIBS = -lraylib -lopengl32 -lgdi32 -lwinmm

SRC = src/main.cpp src/player.cpp src/track.cpp

OBJ = build/main.o build/player.o build/track.o

OUT = build/jogo.exe

all: $(OUT)

$(OUT): $(OBJ)
	$(CC) $(OBJ) -o $(OUT) $(LIBS)

build/main.o: src/main.cpp include/player.hpp include/track.hpp
	$(CC) -c src/main.cpp -o build/main.o $(CFLAGS)

build/player.o: src/player.cpp include/player.hpp include/track.hpp
	$(CC) -c src/player.cpp -o build/player.o $(CFLAGS)

build/track.o: src/track.cpp include/track.hpp
	$(CC) -c src/track.cpp -o build/track.o $(CFLAGS)

run: $(OUT)
	.\build\jogo.exe

rebuild: clean all

clean:
	del build\*.o
	del build\jogo.exe