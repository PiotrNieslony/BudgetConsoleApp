#include "IncomeXMLFile.h"

CMarkup IncomeXMLFile::xmlIncomes;

IncomeXMLFile::IncomeXMLFile()
    :File("Incomes.xml") {
}

IncomeXMLFile::IncomeXMLFile(string name)
    :File(name) {
    fileName = name;
}
/*
void IncomeXMLFile::addRecord(Income income) {

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
    xmlIncomes.AddElem( "userId",  income.getUserId());
    xmlIncomes.AddElem( "date",     income.getDate());
    xmlIncomes.AddElem( "source",  income.getSource());
    xmlIncomes.AddElem( "amount",    income.getAmount());
    xmlIncomes.OutOfElem();

    statusOfSave = xmlIncomes.Save(fileName.c_str());
    if(statusOfSave) cout << "Dodano dane do pliku XML" << endl;
    else cout << "Wystlpil problem podczas zapisu danch do plikku: " << fileName << endl;
}


void IncomeXMLFile::editRecord(Income income) {
    bool statusOfSave = false;
    int incomeId = income.getId();
    int incomeIdXml;

    xmlIncomes.ResetPos();
    xmlIncomes.FindElem();
    xmlIncomes.IntoElem();
    while ( xmlIncomes.FindElem("Income") ) {
        xmlIncomes.IntoElem();
        xmlIncomes.FindElem("incomeId");
        incomeIdXml = atoi( MCD_2PCSZ(xmlIncomes.GetData()) );
        if(incomeIdXml == incomeId) {
            xmlIncomes.FindElem("name");
            xmlIncomes.SetData(income.getName());
            xmlIncomes.FindElem("surname");
            xmlIncomes.SetData(income.getSurname());
            xmlIncomes.FindElem("login");
            xmlIncomes.SetData(income.getLogin());
            xmlIncomes.FindElem("password");
            xmlIncomes.SetData(income.getPassword());
            break;
        }
        xmlIncomes.OutOfElem();
    }

    statusOfSave = xmlIncomes.Save(fileName.c_str());
    if(statusOfSave) cout << "Dodano dane do pliku XML" << endl;
    else cout << "Wystlpil problem podczas zapisu danch do plikku" << endl;
}

void IncomeXMLFile::loadAllRecords(vector<Income>& listOfUser) {
    bool statusOfLoad = false;
    int id;
    string name, surname, login, password;
    Income singleUser;
    fstream usersFile;

    statusOfLoad = xmlIncomes.Load(fileName.c_str());
    if(!statusOfLoad) cout << "Wystlpil problem podczas odczytu danch do pliku: "  << fileName << endl;

    xmlIncomes.FindElem();
    xmlIncomes.IntoElem();
    while ( xmlIncomes.FindElem("Income") ) {
        xmlIncomes.IntoElem();
        xmlIncomes.FindElem("ulserId");
        id = atoi( MCD_2PCSZ(xmlIncomes.GetData()) );
        xmlIncomes.FindElem("name");
        name = xmlIncomes.GetData();
        xmlIncomes.FindElem("surname");
        surname = xmlIncomes.GetData();
        xmlIncomes.FindElem("login");
        login = xmlIncomes.GetData();
        xmlIncomes.FindElem("password");
        password = xmlIncomes.GetData();
        xmlIncomes.OutOfElem();
        singleUser.setAll(id, name, surname, login, password);
        listOfUser.push_back(singleUser);
    }
}
*/


