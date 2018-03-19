#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>
#include "BudgetItem.h"
#include "File.h"
#include "Conversion.h"
#include "ConsoleMessage.h"

#ifndef INCOME_XML_FILE_H
#define INCOME_XML_FILE_H

using namespace std;

class BudgetPartXMLFile :public File {
    CMarkup xmlIncomes;

public:
    BudgetPartXMLFile();
    BudgetPartXMLFile(string name);
    void addRecord(BudgetItem budgetItem);
    int loadAllRecords(vector<BudgetItem>& incomes);
};

#endif // INCOME_XML_FILE_H


