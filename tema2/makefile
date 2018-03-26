all: regex

bin/regex.o: src/regex.cpp
	g++ -c src/regex.cpp -o bin/regex.o

bin/main.o: src/main.cpp
	g++ -c src/main.cpp -o bin/main.o

regex: bin/main.o bin/regex.o
	g++ bin/main.o bin/regex.o -o regex

clean:
	rm bin/*.o regex