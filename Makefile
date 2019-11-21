main : database.o test.o sequence.o
	g++ test.o database.o sequence.o bdata.h -o main

database.o : database.cpp bdata.h
	g++ -c database.cpp

test.o : test.cpp
	g++ -c test.cpp
sequence.o : sequence.cpp
	g++ -c sequence.cpp



