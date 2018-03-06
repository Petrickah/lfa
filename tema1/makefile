all: tema1

bin/main.o lib/parser.lib: src/main.cpp src/parser.cpp
	g++ -c -o bin/main.o src/main.cpp
	g++ -c -o lib/parser.lib src/parser.cpp
bin/deprecated.o: src/deprecated.cpp
	g++ -c -o bin/deprecated.o src/deprecated.cpp
tema1: bin/main.o bin/deprecated.o lib/parser.lib
	g++ -o tema1 bin/main.o bin/deprecated.o lib/parser.lib
clean: 
	rm lib/*.lib bin/*.o tema1