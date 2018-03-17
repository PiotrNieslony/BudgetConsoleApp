#include <stdlib.h>
#include <sstream>
#include <string>
#include <iostream>

#ifndef CONVERSION_H
#define CONVERSION_H

using namespace std;

class Conversion {
public:
    string intToString(int number);
    int stringToInt(string textNumber);
    double stringToDouble(string textNumber);
};

#endif
