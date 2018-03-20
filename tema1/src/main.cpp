#include "headers/stdafx.hpp"

bool esteCuvantValid(ParserClasses::Parser& myDFA, ParserClasses::State* currState, char* word)
{
    while(word[0] != '\0') {
        char token[2] = {word[0], '\0'};
        if(strcmp(word, "~") == 0 && myDFA.isFinalState(currState)) return true;
        else {
            if(myDFA.isValidToken(token))
            {
                currState = myDFA.nextState(
                    currState,
                    new ParserClasses::Letter(token)
                );
            } else {
                std::cout<<"Invalid token!"<<std::endl;
                return false;
            }
            word = word+1;
            if(myDFA.isFinalState(currState) && strcmp(word, "") == 0) return true;
        }
    }
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
        std::cout<<argv[1]<<std::endl;
        myParser.readAutomata(automat);
        if(esteCuvantValid(myParser, myParser.getFirstState(), argv[1])){
            std::cout<<"Cuvant acceptat!\n";
        }
        else std::cout<<"Cuvantul nu este acceptat!\n";
    }
    return 0;
}