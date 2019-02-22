#include "headers/stdafx.hpp"

bool esteCuvantValid(ParserClasses::Parser& myDFA, ParserClasses::State currState, char* word) {
    while(word[0] != '\0') {
        char token[2] = {word[0], '\0'};
        if(strcmp(word, "~") == 0 && myDFA.isFinalState(currState)) return true;
        else {
            if(myDFA.isValidToken(token)) {
                currState = myDFA.nextState(
                    currState,
                    new ParserClasses::Letter(token)
                );
                if(currState.getState() == -1) {
                    std::cout<<"Nu am putut extrage starea urmatoare pentru: "<<token<<"\n";
                    return false;
                }
            } else {
                std::cout<<"Invalid token! "<<token<<std::endl;
                return false;
            }
            word = word+1;
            if(myDFA.isFinalState(currState) && strcmp(word, "") == 0) return true;
        }
    }
    return false;
}

int main(int argc, char* argv[])
{
    char word[100];
    std::cout<<"Introduceti cuvantul de verificat: "; std::cin>>word;
    std::cout<<"Testez cuvantul..."<<std::endl;

    std::ifstream states("var/states.txt");
    std::ifstream alphabet("var/alphabet.txt");
    std::ifstream automat("var/automat.txt");
    ParserClasses::Parser myParser(states, alphabet);
    myParser.readAutomata(automat);
    if(esteCuvantValid(myParser, myParser.getFirstState(), word)){
        std::cout<<"Cuvant acceptat!";
    }
    else std::cout<<"Cuvantul nu este acceptat!";

    return 0;
}