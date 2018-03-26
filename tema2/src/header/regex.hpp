#ifndef REGEX_REGEX_H
#define REGEX_REGEX_H

// Du 25.03.2018, 16:21.35
// (Lu|Ma|Mi|Jo|Vi|Sa|Du)(\s)([\d.]+)(,\s)([\d:.]+)

/* 
Wildcards:
    •  . : any charactes
    • \b = [^0-9A-Za-z_]: non-word characters
    • \d = [0-9]: digit
    • \D = [ˆ\d]: non-digit
    • \w = [a-zA-Z0-9_]: alphanumeric
    • \W = [ˆ\w]: non-alphanumeric
    • \s = [\r\t\n\f]: whitespace character
        – \r: space, \t: tab, \n: newline, \f: formfeed
    • \S = [ˆ\s]: non-whitespace

<Token> : Any word in a sentence with one or more characters
*/

#include <iostream>
#include <cstring>
#include <vector>

class Token {
    char *string;
public:
    Token(int nrChars = 0) { string = new char[nrChars]; }
    Token(char* tok) { string = new char[strlen(tok)]; strcpy(string, tok); }
    ~Token() { delete[] string; }

    friend std::ostream& operator<<(std::ostream&, const Token&);
};

class Regex {
    char *string;
    char specialCharacters[6] = "|*+()";
    std::vector<Token*> tokensList;
public:
    Regex(int nrChars = 0) { string = new char[nrChars]; }
    Regex(char* reg) { string = new char[strlen(reg)]; strcpy(string, reg); }
    ~Regex() { delete[] string; }

    bool isSpecialCharacter(char);
    void extractTokens();
};
#endif