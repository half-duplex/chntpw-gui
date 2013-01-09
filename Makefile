CC = g++
CCFLAGS = -Wall -g -std=c++0x `pkg-config --cflags --libs gtkmm-3.0 blkid mount` # -static-libgcc -static-libstdc++ -static

all: main
clean:
	rm -rf *.core bin/
commonstuff:
	mkdir -p bin/object/

main: main.o Makefile commonstuff
	${CC} ${CCFLAGS} ${GTK} -o bin/chntpw-gui bin/object/main.o

main.o: Makefile commonstuff
	${CC} ${CCFLAGS} ${GTK} -o bin/object/main.o -c src/main.cpp

