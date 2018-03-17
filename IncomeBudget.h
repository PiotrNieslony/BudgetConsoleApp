#include <vector>
#include <windows.h>
#include <stdio.h>
#include <algorithm>
#include "Income.h"
#include "Date.h"
#include "IncomeXMLFile.h"

using namespace std;

#ifndef INCOME_BUDGET_H
#define INCOME_BUDGET_H

class IncomeBudget {
    vector<Income> incomes;
    int lastIncomeId;
    Date date;
    void displayHeaderTable();
    void displaySeparatingLine();
    void displayTableRow(Income income);
    string generateDashes(int quantity);
public:
    void loadIncomesFromXML();
    void setLastIncomeId(int id);
    void addIncome(Income income);
    void writeIncome();
    void displaySpecificRange();
    void displayPreviousMonth();
    void displayCurrentMonth();
    void displayIncomes(int dateFrom, int dateTo);
    double sumIncomes();
    void clearVector();

};
#endif // INCOME_BUDGET_H
