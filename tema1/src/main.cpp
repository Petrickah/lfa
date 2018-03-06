#include "headers/stdafx.hpp"

int main(int argc, char* argv[])
{
    std::cout<<"Hello, world!"<<std::endl;
    std::ifstream states("var/states.txt");
    std::ifstream alphabet("var/alphabet.txt");
    ParserClasses::Parser myParser;
    myParser.readAlphabet(alphabet);
    return 0;
}