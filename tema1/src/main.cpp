#include "headers/stdafx.hpp"

bool esteCuvantValid(ParserClasses::Parser& myDFA, ParserClasses::State* currState, char* word)
{
    while(word[0] != '\0') {
        char token[1] = {word[0]};
        strcpy(word, word+1);
        if(myDFA.isFinalState(currState)) return true;
        currState = myDFA.nextState(
            currState,
            ParserClasses::Letter(token)
        );
    }
    if(currState == nullptr) return false;
}

int main(int argc, char* argv[])
{
    std::cout<<"Testez cuvantul..."<<std::endl;
    if(argc!=2) std::cout<<"Usage: ./tema1 <cuvant>"<<std::endl;
    else {
        std::ifstream states("var/states.txt");
        std::ifstream alphabet("var/alphabet.txt");
        std::ifstream automat("var/automat.txt");
        ParserClasses::Parser myParser(states, alphabet);
        myParser.readAutomata(automat);

        if(esteCuvantValid(myParser, myParser.getFirstState(), argv[1])){
            std::cout<<"Cuvant acceptat!\n";
        }
        else std::cout<<"Cuvantul nu este acceptat!\n";
    }
    return 0;
}