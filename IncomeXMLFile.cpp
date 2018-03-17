#include "IncomeXMLFile.h"

CMarkup IncomeXMLFile::xmlIncomes;

IncomeXMLFile::IncomeXMLFile()
    :File("Incomes.xml") {
}

IncomeXMLFile::IncomeXMLFile(string name)
    :File(name) {
    fileName = name;
}

void IncomeXMLFile::addRecord(Income income) {
    ConsoleMessage consoleMessage;
    Date date;
    bool statusOfSave = false;
    if(isFileEmpty()) {
        xmlIncomes.AddElem( "Incomes" );
        xmlIncomes.IntoElem();
    } else {
        xmlIncomes.ResetPos();
        xmlIncomes.FindElem();
        xmlIncomes.IntoElem();
    }

    xmlIncomes.AddElem("Income");
    xmlIncomes.IntoElem();
    xmlIncomes.AddElem( "incomeId",  income.getId());
    xmlIncomes.AddElem( "userId",  income.getOwnerId());
    xmlIncomes.AddElem( "date",     date.convertDateToString(income.getDate()));
    xmlIncomes.AddElem( "source",  income.getSource());
    xmlIncomes.AddElem( "amount",    income.getAmount());
    xmlIncomes.OutOfElem();

    statusOfSave = xmlIncomes.Save(fileName.c_str());
    if(!statusOfSave)
        consoleMessage.display("Wystlpil problem podczas zapisu danch do plikku: " + fileName, "critical");
}

void IncomeXMLFile::loadAllRecords(vector<Income>& incomes) {
    ConsoleMessage consoleMessage;
    User user;
    Date date;
    int idLoggedUser = user.getIdLoggedUser();
    int lastIncomeId = 0;
    bool statusOfLoad = false;
    int incomeId, idOwner,incomeDate, dateInt;
    double amount;
    string dateString, source;
    Income singleIncome;

    statusOfLoad = xmlIncomes.Load(fileName.c_str());
    if(!statusOfLoad) consoleMessage.display("Wystlpil problem podczas odczytu danch do pliku: "  + fileName, "critical");

    xmlIncomes.FindElem();
    xmlIncomes.IntoElem();
    while ( xmlIncomes.FindElem("Income") ) {
        xmlIncomes.IntoElem();
        xmlIncomes.FindElem("incomeId");
        incomeId = atoi( MCD_2PCSZ(xmlIncomes.GetData()) );
        cout << "income id: " << incomeId << endl;
        if ( incomeId > lastIncomeId) lastIncomeId = incomeId;
        xmlIncomes.FindElem("userId");
        idOwner = atoi( MCD_2PCSZ(xmlIncomes.GetData()) );
        if (idOwner == idLoggedUser) {
            xmlIncomes.FindElem("date");
            dateString = xmlIncomes.GetData();
            xmlIncomes.FindElem("source");
            source = xmlIncomes.GetData();
            xmlIncomes.FindElem("amount");
            amount = atof(MCD_2PCSZ(xmlIncomes.GetData()));
            dateInt = date.convertDateToInt(dateString);
            singleIncome.setAll(dateInt, source, amount, incomeId, idOwner);
            incomes.push_back(singleIncome);
        }
        xmlIncomes.OutOfElem();
    }
    singleIncome.setLastId(lastIncomeId);
}



