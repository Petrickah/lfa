#include <iostream>
#include "header/regex.hpp"

int main(int argc, char* argv[]) {
    std::cout<<"Hello, world!"<<std::endl;
    Regex myRegex("(a|b)*abb");
    myRegex.extractTokens();
    return 0;
}