#include "headers/parser.hpp"

void ParserClasses::Parser::initTransMatrix(int nrStates) {
    this->transMatrix = new std::vector<Letter*> [nrStates + 1];
    for(int i=0; i<=nrStates; i++)
        this->transMatrix[i] = 
            std::vector<Letter*> (
                nrStates + 1,
                new Letter("~")
            );
}
void ParserClasses::Parser::readStates(std::ifstream& in) {
    char row[250];

    #define readVectorStates(vect) \
        int k=0; \
        while(row[k] != '{') k++; \
        char* token = strtok(&row[k], "{, }"); \
        while(token != nullptr) \
        { \
            (vect).push_back(State(atoi(token))); \
            token = strtok(nullptr, "{, }"); \
        } \

    while(!in.eof()) {
        in.getline(row, 250);
        if(row[0] == 'S') {
            readVectorStates(vStates);
        }
        else if(row[0] == 'Q') {
            readVectorStates(vFinalStates);
        }
        else if(row[0] == 'q') {
            int k=0;
            while(row[k] != '=') k++;
            this->firstState = new State(atoi(&row[k+1]));
        }
        else {
            this->nrStates = atoi(row);
        }
    }
}
void ParserClasses::Parser::readAlphabet(std::ifstream& in) {
    char row[250];
    while(!in.eof())
    {
        in.getline(row, 250);
        char* token = strtok(row, ", ");
        while(token != nullptr)
        {
            this->vAlphabet.push_back(new Letter(token));
            token = strtok(nullptr, ", ");
        }
    }
}
void ParserClasses::Parser::readAutomata(std::ifstream& in) {
    int x, y; char token[20];
    while(!in.eof())
    {
        in>>x>>y>>token;
        this->transMatrix[x][y] = new Letter(token);
    }
}
ParserClasses::State* ParserClasses::Parser::nextState(
    ParserClasses::State* currState, ParserClasses::Letter token) 
{
    auto currRow = this->transMatrix[currState->getState()];
    int k = -1;
    for(auto letter: currRow) {
        k++;
        if(strcmp(letter->getLetter(), token.getLetter()) == 0)
            return new ParserClasses::State(k);
    }
    return nullptr;
}
bool ParserClasses::Parser::isFinalState(ParserClasses::State* myState){
    for(auto state: this->vFinalStates)
    {
        if(state.getState() == myState->getState()) return true;
    }
    return false;
}