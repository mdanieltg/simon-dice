CPPFLAGS=-std=c++17 -Wall -Iheader

OBJS=random.o game.o main.o
EXE=simon


all: simon

simon: main.o
	g++ $(CPPFLAGS) -o $(EXE) $(OBJS)

main.o: main.cpp game.o
	g++ -c $(CPPFLAGS) main.cpp

game.o: source/game.cpp header/game.h random.o
	g++ -c $(CPPFLAGS) source/game.cpp

random.o: source/random.cpp header/random.h
	g++ -c $(CPPFLAGS) source/random.cpp

clean:
	rm -f $(OBJS)

distclean: clean
	rm -f $(EXE)
