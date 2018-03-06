#include "headers/parser.hpp"

void ParserClasses::Parser::initTransMatrix(int nrStates) {
    this->transMatrix = 
        new std::vector< std::vector< Letter > > (
            nrStates + 1, 
            std::vector< Letter >(
                nrStates + 1,
                Letter("~")
            )
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

    for(auto state: vStates)
        std::cout<<state.getState()<<" ";
    for(auto state: vFinalStates)
        std::cout<<state.getState()<<" ";
    std::cout<<firstState->getState()<<" ";
}