#include "Income.h"

int Income::lastId = 0;

void Income::setLastId(int id){
    lastId = id;
}

Income::Income(){
    incomeId = lastId + 1;
    lastId++;
}

Income::Income(int sIncomDate, string sIncomSource, double sIncomeAmount){
    incomeId = lastId + 1;
    lastId++;
    setAll(sIncomDate, sIncomSource, sIncomeAmount);

}

void Income::writeIncome(){
    User user;
    ownerId = user.getIdLoggedUser();
    incomDate = date.convertDateToInt(date.addDate());
    cout << "Wprowdz zrodlo dochodu: ";
    cin.sync();
    getline(cin, incomSource);
    incomeAmount = amount.typeValue();
    cout << "incomeAmount: " << incomeAmount << endl;
}

void Income::setAll(int sIncomDate, string sIncomSource, double sIncomeAmount, int id, int userId){
    incomeId = id;
    ownerId = userId;
    incomDate = sIncomDate;
    incomDate = sIncomDate;
    incomSource = sIncomSource;
    incomeAmount = sIncomeAmount;
}

void Income::setAll(int sIncomDate, string sIncomSource, double sIncomeAmount){
    User user;
    ownerId = user.getIdLoggedUser();
    incomDate = sIncomDate;
    incomDate = sIncomDate;
    incomSource = sIncomSource;
    incomeAmount = sIncomeAmount;
}

int Income::getId(){
    return incomeId;
}

int Income::getOwnerId(){
    return ownerId;
}

int Income::getDate(){
    return incomDate;
}

string Income::getSource() {
    return incomSource;
}

double Income::getAmount(){
    return incomeAmount;
}
