#include <iostream>
#include <string>
#include "Amount.h"
#include "Conversion.h"
#include "Date.h"
#include "User.h"

#ifndef INCOME_H
#define INCOME_H

using namespace std;

class BudgetItem {
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

    BudgetItem();
    BudgetItem(int incomDate, string incomSource, double incomeAmount);
    void setId(int id);
    void setAll(int incomDate, string incomSource, double incomeAmount);
    void setAll(int sIncomDate, string sIncomSource, double sIncomeAmount, int id, int userId);
    void setLastId(int id);
    void writeBudgetItem();
    int getId();
    int getOwnerId();
    int getDate();
    string getSource();
    double getAmount();

    BudgetItem(int k, const std::string& s) : incomDate(k), incomSource(s) {}

    bool operator < (const BudgetItem& str) const
    {
        return (incomDate < str.incomDate);
    }
};

#endif // INCOME_H

