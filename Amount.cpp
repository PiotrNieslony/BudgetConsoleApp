#include "Amount.h"

double Amount::typeValue(){
    string amountString;
    int positionOfComa;
    cout << "Wpisz kwote: ";
    cin >> amountString;
    positionOfComa = amountString.find(',');
    if (positionOfComa!=string::npos) amountString.replace( positionOfComa, 1, ".");
    return conversion.stringToDouble(amountString);
}
