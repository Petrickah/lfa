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