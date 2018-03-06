#ifndef LFA_TEMA1_STDAFX_H_
#define LFA_TEMA1_STDAFX_H_

#include <iostream>
#include <fstream>
//Working with strings
#include <stdlib.h>
#include <string.h>

#include "parser.hpp"

namespace myMainFunctions {
    ParserClasses::Parser* getAutomata(std::ifstream& in);
}

#endif // LFA_TEMA1_STDAFX_H_