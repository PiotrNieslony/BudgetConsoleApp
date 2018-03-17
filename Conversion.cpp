#include "Conversion.h"

string Conversion::intToString(int number) {
    ostringstream ss;
    ss << number;
    return ss.str();
}

int Conversion::stringToInt(string textNumber) {
    return atoi(textNumber.c_str());
}

double Conversion::stringToDouble(string textNumber) {
    return atof(textNumber.c_str());
}
