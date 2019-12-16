main : database.o test.o sequence.o header.o
	g++ test.o database.o header.o sequence.o bdata.h -o main -pthread

database.o : database.cpp bdata.h
	g++ -c database.cpp

test.o : test.cpp
	g++ -c test.cpp
sequence.o : sequence.cpp
	g++ -c sequence.cpp

header.o : header.cpp
	g++ -c header.cpp

