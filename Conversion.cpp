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
    cout << "conversion " << atof(textNumber.c_str()) << endl;
    return atof(textNumber.c_str());
}
