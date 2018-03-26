#include "header/regex.hpp"

std::ostream& operator<<(std::ostream& out, const Token& tok) {
    out<<tok.string;
    return out;
}

bool Regex::isSpecialCharacter(char c) {
    for (int i=0; i<strlen(this->specialCharacters); i++)
        if(specialCharacters[i] == c) return true;
    return false;
}

void Regex::extractTokens() {
    char* tok = strtok(this->string, this->specialCharacters);
    while(tok != nullptr)
    {
        //std::cout<<tok<<" ";
        this->tokensList.push_back(new Token(tok));
        tok = strtok(nullptr, this->specialCharacters);
    }
}