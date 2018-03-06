#include "headers/stdafx.hpp"

int main(int argc, char* argv[])
{
    std::cout<<"Hello, world!"<<std::endl;
    std::ifstream states("var/states.txt");
    ParserClasses::Parser myParser;
    myParser.readStates(states);
    return 0;
}