CC = g++
CFLAGS = -Wall -g
OPT_FLAGS = -O3

all: main

main: main.o
	${CC} -o main main.o

main.o: main.cpp
	${CC} ${CFLAGS} ${OPT_FLAGS} -c main.cpp

debug: main
	gdb main

clean:
	rm main.o main

