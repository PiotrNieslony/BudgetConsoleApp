#include "BudgetItem.h"

int BudgetItem::lastId = 0;

void BudgetItem::setLastId(int id){
    lastId = id;
}

BudgetItem::BudgetItem(){
}

BudgetItem::BudgetItem(int sIncomDate, string sIncomSource, double sIncomeAmount){
    incomeId = lastId + 1;
    lastId++;
    setAll(sIncomDate, sIncomSource, sIncomeAmount);
}

void BudgetItem::writeBudgetItem(){
    incomeId = lastId + 1;
    lastId++;
    User user;
    ownerId = user.getIdLoggedUser();
    incomDate = date.convertDateToInt(date.writeDate());
    while(true){
        cout << "Nazwa: ";
        cin.sync();
        getline(cin, itemSource);
        if(itemSource.empty() == false) break;
        else cout << "Nazwa nie moze byc pusta. ";
    }
    incomeAmount = amount.typeValue();
}

void BudgetItem::setAll(int sIncomDate, string sIncomSource, double sIncomeAmount, int id, int userId){
    incomeId = id;
    ownerId = userId;
    incomDate = sIncomDate;
    incomDate = sIncomDate;
    itemSource = sIncomSource;
    incomeAmount = sIncomeAmount;
}

void BudgetItem::setAll(int sIncomDate, string sIncomSource, double sIncomeAmount){
    User user;
    ownerId = user.getIdLoggedUser();
    incomDate = sIncomDate;
    incomDate = sIncomDate;
    itemSource = sIncomSource;
    incomeAmount = sIncomeAmount;
}

int BudgetItem::getId(){
    return incomeId;
}

int BudgetItem::getOwnerId(){
    return ownerId;
}

int BudgetItem::getDate(){
    return incomDate;
}

string BudgetItem::getSource() {
    return itemSource;
}

double BudgetItem::getAmount(){
    return incomeAmount;
}
