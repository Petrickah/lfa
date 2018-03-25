all: regex

bin/main.o: src/main.cpp
	g++ -c src/main.cpp -o bin/main.o

regex: bin/main.o
	g++ bin/main.o -o regex

clean:
	rm bin/*.o regex