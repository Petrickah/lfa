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

class Token {
    char *string;
public:
    Token(int nrChars = 0) { string = new char[nrChars]; }
    ~Token() { delete[] string; }
};

class Regex {
    char *string;
public:
    Regex(int nrChars = 0) { string = new char[nrChars]; }
    ~Regex() { delete[] string; }
};
#endif