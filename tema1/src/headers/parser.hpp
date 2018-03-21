#ifndef LFA_TEMA1_PARSER_H_
#define LFA_TEMA1_PARSER_H_

#include <fstream>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string.h>

namespace ParserClasses {
    class Letter {
        char* letter;
    public:
        Letter() { this->letter = new char[1]; *(this->letter) = 'a'; }
        Letter(char* letter) { this->letter = new char[strlen(letter)+1]; strcpy(this->letter, letter); }
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
        std::vector<Letter*> vAlphabet;

        std::vector<State*> *transMatrix;

        void initTransMatrix(int nrStates);
        int getIndexOfLetter(char* token);
    public:
        Parser() { this->firstState = new State(); }
        Parser(int intFirstState, int nrStates) {
            this->firstState = new State(intFirstState);
            this->nrStates = nrStates; initTransMatrix(this->nrStates);
        }
        Parser(State firstState) { this->firstState = new State(firstState); }
        Parser(std::ifstream& states, std::ifstream& alphabet) {
            this->readStates(states);
            this->readAlphabet(alphabet);
            initTransMatrix(this->nrStates);
        }
        ~Parser() { delete firstState; }
        State* getFirstState() { return firstState; }

        //Metoda specifica starilor
        void readStates(std::ifstream& in);
        //Metoda specifica alfabetului
        void readAlphabet(std::ifstream& in);
        //Metoda specifica automatului
        void readAutomata(std::ifstream& in);

        State* nextState(State* currState, Letter* token);
        bool isFinalState(State* myState);
        bool isValidToken(char* token);
    };
}
#endif // LFA_TEMA1_PARSER_H_
