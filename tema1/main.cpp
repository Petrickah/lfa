#include "headers/stdafx.hpp"

bool esteCuvantValid(ParserClasses::Parser& myDFA, ParserClasses::State *currState, char* word)
{
    char *token = strtok(word, " ");
    while(token != nullptr) {
        std::cout<<token<<std::endl;
        if(strcmp(word, "~") == 0 && myDFA.isFinalState(currState)) return true;
        else {
            if(myDFA.isValidToken(token))
            {
                currState = myDFA.nextState(
                    currState,
                    new ParserClasses::Letter(token)
                );
                if(currState == nullptr) {
                    std::cout<<"Nu am putut extrage starea urmatoare pentru: "<<token<<"\n";
                    return false;
                }
            } else {
                std::cout<<"Invalid token! "<<token<<std::endl;
                return false;
            }
            token = strtok(NULL, " ");
            if(myDFA.isFinalState(currState) && token == nullptr) return true;
        }
    }
    return false;
}

int main(int argc, char* argv[])
{
    char word[100];
    std::cout<<"Introduceti cuvantul de verificat: "; std::cin.get(word, 100);
    std::cout<<"Testez cuvantul... ";

    std::ifstream states("var/states.txt");
    std::ifstream alphabet("var/alphabet.txt");
    std::ifstream automat("var/automat.txt");
    ParserClasses::Parser myParser(states, alphabet);
    std::cout<<word<<std::endl;
    myParser.readAutomata(automat);
    if(esteCuvantValid(myParser, myParser.getFirstState(), word)){
        std::cout<<"Cuvant acceptat!\n";
    }
    else std::cout<<"Cuvantul nu este acceptat!\n";

    return 0;
}
