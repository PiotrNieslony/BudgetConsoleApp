#include "Date.h"


string Date::todayDate() {
    time_t rowtime;
    struct tm * timeinfo;
    char buffer [80];
    string todayDate;
    time(&rowtime);
    timeinfo = localtime(&rowtime);
    strftime (buffer,80,"%Y-%m-%d",timeinfo);
    return todayDate = buffer;
}

string Date::addDate() {
    string date;
    while(true) {
        cout << "Wpisz date (w formacie rrrr-mm-dd) lub wpisz 0 jesli ma byc uzyta dzisiejsza data: ";
        cin >> date;
        if(date == "0"){
            dateString = todayDate();
            return dateString;
        }
        if(!(hasCorrectFormat(date))){
                cout << "Niepoprawny format" << endl;
                continue;
        }
        if(!(hasCorrectValue(date))) {
                cout << "Niepoprawna wartosc" << endl;
                continue;
        }
        if(hasCorrectRange(date)){
            dateString = date;
            return date;
        }
        else {
                cout << "Data powinna byc z przedzialu od 2001-01-01 do " + lastDayInCurrentMonth() << endl;
                continue;
        }
    }
}

string Date::lastDayInCurrentMonth() {
    time_t rowtime;
    struct tm * timeinfo;
    char buffer [80];
    string date;
    time(&rowtime);
    timeinfo = localtime(&rowtime);
    int month = timeinfo->tm_mon + 1;
    int year = timeinfo->tm_year + 1900;
    timeinfo->tm_mday = howManyDaysInMonth(month, year);
    strftime (buffer,80,"%Y-%m-%d",timeinfo);
    return date = buffer;
}

bool Date::hasCorrectFormat(string checkedDate) {
    int dateLength = checkedDate.length();
    if (dateLength != 10) return false;
    for (int i = 0; i < dateLength; i++) {
        if(i == 4 || i == 7) {
            if (checkedDate[i] != '-') return false;
        } else {
            if(checkedDate[i] < '0' || checkedDate[i] > '9') return false;
        }
    }
    return true;
}

bool Date::hasCorrectValue(string checkedDate) {
    int year = conversion.stringToInt(checkedDate.substr(0,4));
    int month = conversion.stringToInt(checkedDate.substr(5,2));
    int day = conversion.stringToInt(checkedDate.substr(8,2));
    if((month < 1) || (month > 12)) return false;
    if((day < 1) || (day > howManyDaysInMonth(month, year))) return false;
    return true;
}

bool Date::hasCorrectRange(string checkedDate) {
    const int RANGE_DATE_FROM = convertDateToInt("2000-01-01");
    int rangeDateTo = convertDateToInt(lastDayInCurrentMonth());
    int dateInt = convertDateToInt(checkedDate);
    if((dateInt >= RANGE_DATE_FROM) && (dateInt  <= rangeDateTo))
        return true;
    return false;
}

bool Date::istDateCorect(string checkedDate) {
    if(hasCorrectFormat(checkedDate) && hasCorrectRange(checkedDate))
        return true;
    return false;
}


//convert string date like: 2018-03-15 to int 20180315
int Date::convertDateToInt(string dateString) {
    dateString.erase(dateString.find('-'),1);
    dateString.erase(dateString.find('-'),1);
    return conversion.stringToInt(dateString);
}

string Date::convertDateToString(int dateInt) {
    ostringstream ss;
    ss << dateInt;
    string dateString = ss.str();
    dateString.insert(4,"-");
    dateString.insert(7,"-");
    return dateString;
}

bool Date::isLeapYear(int year) {
    if((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0))) return true;
    else return false;
}

int Date::howManyDaysInMonth(int month, int year) {
    switch(month) {
    case 1:
        return 31;
    case 2:
        if(isLeapYear(year)) return 29;
        else return 28;
    case 3:
        return 31;
    case 4:
        return 30;
    case 5:
        return 31;
    case 6:
        return 30;
    case 7:
        return 31;
    case 8:
        return 31;
    case 9:
        return 30;
    case 10:
        return 31;
    case 11:
        return 30;
    case 12:
        return 31;
    }
}
