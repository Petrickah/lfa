#include "headers/parser.hpp"

void ParserClasses::Parser::initTransMatrix(int nrStates) {
    this->transMatrix = new std::vector<State*> [nrStates + 1];
    for(int i=0; i<=nrStates; i++)
        this->transMatrix[i] = std::vector<State*> (
                this->vAlphabet.size() + 1, nullptr
            );
}
void ParserClasses::Parser::readStates(std::ifstream& in) {
    char row[250];

    #define readVectorStates(vect, contor) \
        int k=0; \
        while(row[k] != '{') k++; \
        char* token = strtok(&row[k], "{, }"); \
        while(token != nullptr) \
        { \
            (vect).push_back(State(atoi(token))); \
            (contor)++; \
            token = strtok(nullptr, "{, }"); \
        } \

    while(!in.eof()) {
        in.getline(row, 250);
        if(row[0] == 'Q') {
            this->nrStates = 0;
            readVectorStates(vStates, this->nrStates);
        }
        else if(row[0] == 'F') {
            int c= 0;
            readVectorStates(vFinalStates, c);
        }
        else if(row[0] == 'q') {
            int k=0;
            while(row[k] != '=') k++;
            this->firstState = new State(atoi(&row[k+1]));
        }
    }
    std::cout<<this->nrStates<<std::endl;
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

int ParserClasses::Parser::getIndexOfLetter(char* token) {
    int k = 0;
    for(Letter* l: this->vAlphabet)
    {
        if(strcmp(token, "~") == 0 || strcmp(l->getLetter(), token) == 0) return k;
        else k++;
    }
}
void ParserClasses::Parser::readAutomata(std::ifstream& in) {
    int x, y; char token[20];
    while(!in.eof())
    {
        in>>x>>y>>token;
        int k = this->getIndexOfLetter(token);
        this->transMatrix[x][k] = new State(y);
    }
}
ParserClasses::State* ParserClasses::Parser::nextState(
    ParserClasses::State* currState, ParserClasses::Letter* token)
{
    auto currRow = this->transMatrix[currState->getState()];
    int k = this->getIndexOfLetter(token->getLetter());
    return currRow[k];
}
bool ParserClasses::Parser::isFinalState(ParserClasses::State* myState){
    for(auto state: this->vFinalStates)
    {
        if(state.getState() == myState->getState()) return true;
    }
    return false;
}
bool ParserClasses::Parser::isValidToken(char* token){
    for(auto letter: this->vAlphabet)
    {
        if(strcmp(letter->getLetter(), token) == 0) return true;
    }
    return false;
}
