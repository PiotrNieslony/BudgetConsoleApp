#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <time.h>
#include "Conversion.h"

#ifndef DATE_H
#define DATE_H

using namespace std;

class Date{
    Conversion conversion;
    int dateInt;
    string dateString;
    bool hasCorrectRange(string dateString);

public:
    bool hasCorrectValue(string checkedDate);
    string todayDate();
    string writeDate();
    string firstDayInCurrentMonth();
    string lastDayInCurrentMonth();
    string firstDayInPreviousMonth();
    string lastDayInPreviousMonth();
    bool hasCorrectFormat(string dateString);
    bool istDateCorect(string dateString);
    int convertDateToInt(string dateString);
    string convertDateToString(int dataInt);
    int howManyDaysInMonth(int month, int year);
    bool isLeapYear(int year);
};

#endif // DATE_H
