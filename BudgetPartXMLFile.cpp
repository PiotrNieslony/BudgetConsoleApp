#include "BudgetPartXMLFile.h"

BudgetPartXMLFile::BudgetPartXMLFile()
    :File("Incomes.xml") {
}

BudgetPartXMLFile::BudgetPartXMLFile(string name)
    :File(name) {
    fileName = name;
}

void BudgetPartXMLFile::addRecord(BudgetItem budgetItem) {

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
    xmlIncomes.AddElem("BudgetItem");
    xmlIncomes.IntoElem();
    xmlIncomes.AddElem( "incomeId",  budgetItem.getId());
    xmlIncomes.AddElem( "userId",  budgetItem.getOwnerId());
    xmlIncomes.AddElem( "date",     date.convertDateToString(budgetItem.getDate()));
    xmlIncomes.AddElem( "source",  budgetItem.getSource());
    xmlIncomes.AddElem( "amount",    budgetItem.getAmount());
    xmlIncomes.OutOfElem();

    statusOfSave = xmlIncomes.Save(fileName.c_str());
    if(!statusOfSave)
        consoleMessage.display("Wystlpil problem podczas zapisu danch do plikku: " + fileName, "critical");
}

int BudgetPartXMLFile::loadAllRecords(vector<BudgetItem>& incomes) {
    ConsoleMessage consoleMessage;
    User user;
    Date date;
    int idLoggedUser = user.getIdLoggedUser();
    int lastBudgetPartId = 0;
    bool statusOfLoad = false;
    int incomeId, idOwner,incomeDate, dateInt;
    double amount;
    string dateString, source;
    BudgetItem singleIncome;

    statusOfLoad = xmlIncomes.Load(fileName.c_str());
    if(!statusOfLoad) consoleMessage.display("Wystlpil problem podczas odczytu danch do pliku: "  + fileName, "critical");

    xmlIncomes.FindElem();
    xmlIncomes.IntoElem();
    while ( xmlIncomes.FindElem("BudgetItem") ) {
        xmlIncomes.IntoElem();
        xmlIncomes.FindElem("incomeId");
        incomeId = atoi( MCD_2PCSZ(xmlIncomes.GetData()) );
        if ( incomeId > lastBudgetPartId) lastBudgetPartId = incomeId;
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
    return lastBudgetPartId;
}



