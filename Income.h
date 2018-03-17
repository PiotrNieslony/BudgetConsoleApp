#include <iostream>
#include "Amount.h"
#include "Conversion.h"
#include "Date.h"
#include "User.h"

#ifndef INCOME_H
#define INCOME_H

class Income {
    int incomeId;
    int incomDate;
    int ownerId;
    string incomSource;
    double incomeAmount;
    static int lastId;
    Date date;
    Conversion conversion;
    Amount amount;
public:

    Income();
    Income(int incomDate, string incomSource, double incomeAmount);
    void setAll(int incomDate, string incomSource, double incomeAmount);
    void setLastId(int id);
    void writeIncome();
    int getId();
    int getOwnerId();
    int getDate();
    string getSource();
    double getAmount();

    Income(int k, const std::string& s) : incomDate(k), incomSource(s) {}

    bool operator < (const Income& str) const
    {
        return (incomDate < str.incomDate);
    }
};

#endif // INCOME_H

