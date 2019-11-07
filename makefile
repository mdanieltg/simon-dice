all: simon

simon: main.cpp
	g++ -std=c++17 -Wall main.cpp -o simon

clean:
	rm -f simon
