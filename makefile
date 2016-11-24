all: head.h main.cpp
	g++ -g -o final head.h main.cpp SimonGame.cpp userFunctions.cpp

