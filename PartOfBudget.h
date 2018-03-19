#include <vector>
#include <windows.h>
#include <stdio.h>
#include <algorithm>
#include "BudgetItem.h"
#include "Date.h"
#include "BudgetPartXMLFile.h"

using namespace std;

#ifndef INCOME_BUDGET_H
#define INCOME_BUDGET_H

class PartOfBudget {
    vector<BudgetItem> incomes;
    int lastBudgetPartId;
    string fileName;
    BudgetPartXMLFile budgetPartXMLFile;
    Date date;
    void displayHeaderTable();
    void displaySeparatingLineTop();
    void displaySeparatingLineMiddle();
    void displaySeparatingLineBottom();
    void displaySeparatingLine();
    void displayTableRow(BudgetItem budgetItem);
    string generateDashes(int quantity);
public:
    PartOfBudget(string sFileName);
    void loadBudgetPartFromXML();
    void setLastBudgetPartItemId(int id);
    void addBudgetItem(BudgetItem budgetItem);
    void writeBudgetItem();
    double displayPartOfBudget(int dateFrom, int dateTo);
    double sumBudgetPart();
    void clearVector();

};
#endif // INCOME_BUDGET_H
