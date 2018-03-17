#include <iostream>
#include <iomanip>
#include <string>
#include "Conversion.h"

#ifndef AMOUNT_H
#define AMOUNT_H

using namespace std;

class Amount{
    Conversion conversion;
public:
    double typeValue();
};

#endif // AMOUNT_H
