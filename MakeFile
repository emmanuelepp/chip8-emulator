INCLUDES = -I ./include
FLAGS    = -g

OBJECTS =./build/chip8-memory.o

all: ${OBJECTS}
	gcc ${FLAGS} ${INCLUDES} ./src/main.c ${OBJECTS} ./lib/libSDL3.dll.a -o ./bin/main

./build/chip8-memory.o:src/chip8-memory.c
	gcc ${FLAGS} ${INCLUDES} ./src/chip8-memory.c -c -o ./build/chip8-memory.o

clean:
	del build\*