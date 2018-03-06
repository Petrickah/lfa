#include "headers/stdafx.hpp"

int main(int argc, char* argv[])
{
    std::cout<<"Hello, world!"<<std::endl;
    std::ifstream fin("var/automat.txt");
    myMainFunctions::getAutomata(fin);
    return 0;
}