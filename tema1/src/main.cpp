#include "headers/stdafx.hpp"

ParserClasses::Parser* myMainFunctions::getAutomata(std::ifstream& in)
{
    std::vector<ParserClasses::State> myStates, myFinalStates;
    std::vector<ParserClasses::Letter*> myAlphabet;

    ParserClasses::Parser* myParser = nullptr; int nrStates;
    char row[250];
    while(!in.eof()){
        in.getline(row, 250);
        if(row[0] == 'S'){
            int k = 0;
            nrStates = 0;
            while(row[k] != '{') k++;
            char* token = strtok(&row[k], "{, }");
            while(token != NULL)
            {
                int nrState = atoi(token); nrStates++;
                myStates.push_back(ParserClasses::State(nrState));
                token = strtok(NULL, "{, }");
            }
        }
        else if(row[0] == 'A'){
            int k = 0;
            while(row[k] != '{') k++;
            char* token = strtok(&row[k], "{, }");
            while(token != NULL)
            {
                myAlphabet.push_back(new ParserClasses::Letter(token));
                token = strtok(NULL, "{, }");
            }
        }
        else if(row[0] == 'Q'){
            int k=0;
            while(row[k] != '{') k++;
            char* token = strtok(&row[k], "{, }");
            while(token != NULL)
            {
                int state = atoi(token);
                myFinalStates.push_back(ParserClasses::State(state));
                token = strtok(NULL, "{, }");
            }
        }
        else if(row[0] == 'q'){
            int k = 0;
            while(row[k] != '=') k++;
            int state = atoi(&row[k+1]);
            myParser = new ParserClasses::Parser(state, nrStates);
        }
    }
}

int main(int argc, char* argv[])
{
    std::cout<<"Hello, world!"<<std::endl;
    std::ifstream fin("var/automat.txt");
    myMainFunctions::getAutomata(fin);
    return 0;
}