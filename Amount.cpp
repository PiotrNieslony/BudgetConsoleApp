#include "Amount.h"

double Amount::typeValue() {
    string amountString;
    int positionOfComa;
    int numberOfDots;
    while(true) {
        numberOfDots = 0;
        cout << "Wpisz kwote: ";
        cin.sync();
        getline(cin,amountString);
        int charsQuantity = amountString.length();
        if(charsQuantity == 0) goto nextIteration;
        for(int i = 0; i < charsQuantity; i++) {
            if (isspace(amountString[i])) {
                amountString.erase(i, 1);
                charsQuantity--;
                continue;
            }
            if (amountString[i] == '.' || amountString[i] == ',') {
                numberOfDots++;
                if (numberOfDots > 1) {
                    cout << "Mozesz wprowadzic tylko jedna kropke lub przecinek. ";
                    goto nextIteration;
                }
            }
            if((amountString[i] < '0' || amountString[i] > '9') && !(amountString[i] == '.' || amountString[i] == ',')) {
                cout << "Wprowadzono niedozwolone znaki: \"" + amountString.substr(i,1) + "\" ";
                goto nextIteration;
            }
        }
        break;
nextIteration:;
    }
    positionOfComa = amountString.find(',');
    if (positionOfComa!=string::npos) amountString.replace( positionOfComa, 1, ".");
    return conversion.stringToDouble(amountString);
}
