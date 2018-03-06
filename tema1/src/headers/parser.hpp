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
    int nrStates; State *firstState;
    std::vector<State> vStates, vFinalStates;
    std::vector<Letter> vAlphabet;
    std::vector< std::vector<Letter> > *transMatrix;

    void initTransMatrix(int nrStates);
public:
    Parser() { this->firstState = new State(); }
    Parser(int intFirstState, int nrStates) { 
        this->firstState = new State(intFirstState); 
        this->nrStates = nrStates; initTransMatrix(this->nrStates);
    }
    Parser(State firstState) { this->firstState = new State(firstState); }
    ~Parser() { delete firstState; }
};
#endif // LFA_TEMA1_PARSER_H_