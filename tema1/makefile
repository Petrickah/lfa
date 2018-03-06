all: tema1

bin/main.o lib/stdafx.lib lib/parser.lib: src/main.cpp src/stdafx.cpp src/parser.cpp
	g++ -c -o bin/main.o src/main.cpp
	g++ -c -o lib/stdafx.lib src/stdafx.cpp
	g++ -c -o lib/parser.lib src/parser.cpp
tema1: bin/main.o lib/stdafx.lib lib/parser.lib
	g++ -o tema1 bin/main.o lib/stdafx.lib lib/parser.lib
clean: 
	rm lib/*.lib bin/*.o tema1