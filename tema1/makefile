all: tema1

bin/main.o lib/stdafx.lib: src/main.cpp src/stdafx.cpp
	g++ -c -o bin/main.o src/main.cpp
	g++ -c -o lib/stdafx.lib src/stdafx.cpp
tema1: bin/main.o lib/stdafx.lib
	g++ -o tema1 bin/main.o lib/stdafx.lib
clean: 
	rm lib/*.lib bin/*.o tema1