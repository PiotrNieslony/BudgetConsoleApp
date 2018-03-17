#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>
#include "Income.h"
#include "File.h"
#include "Conversion.h"
#include "ConsoleMessage.h"

#ifndef INCOME_XML_FILE_H
#define INCOME_XML_FILE_H

using namespace std;

class IncomeXMLFile :public File {
    static CMarkup xmlIncomes;
public:
    IncomeXMLFile();
    IncomeXMLFile(string name);
    void editRecord(Income income);
    void addRecord(Income income);
    void loadAllRecords(vector<Income>& incomes);
};

#endif // INCOME_XML_FILE_H
using namespace std;

