#ifndef LFA_TEMA1_PARSER_H_
#define LFA_TEMA1_PARSER_H_

#include <vector>
#include <string.h>

class Letter {
    char* letter;
public:
    Letter() { this->letter = new char[1]; *(this->letter) = 'a'; }
    Letter(char* letter) { this->letter = new char[strlen(letter)]; strcpy(this->letter, letter); }
    ~Letter() { delete[] letter; }
    char* getLetter() { return letter; }
};

class State {
    int nrState;
public:
    State() { nrState = 0; }
    State(int nrState) { this->nrState = nrState; }
    int getState() { return nrState; }
};

class Parser {
    std::vector<State> vStates, vFinalStates;
    std::vector<Letter> vAlphabet;
    State *firstState;
public:
    Parser() { this->firstState = new State(); }
    Parser(int intFirstState) { this->firstState = new State(intFirstState); }
    Parser(State firstState) { this->firstState = new State(firstState); }
};
#endif // LFA_TEMA1_PARSER_H_