#include "BudgetManager.h"

BudgetManager::BudgetManager()
    : incomes("Incomes.xml"), expenses("Expenses.xml") {
}

void BudgetManager::addIncome() {
    incomes.writeBudgetItem();
}

void BudgetManager::addExpense() {
    expenses.writeBudgetItem();
}

void BudgetManager::displayBudget(int dateFrom, int dateTo) {
    double incomesSum;
    double expensesSum;
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    cout << endl << "Przychody" << endl;
    incomesSum = incomes.displayPartOfBudget(dateFrom, dateTo);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
    cout << endl << "Koszty" << endl;
    expensesSum = expenses.displayPartOfBudget(dateFrom, dateTo);
    displaySummaryLine(incomesSum, expensesSum);
    cout << "Nacisnij klawisz 'q' aby wrocic do menu glownego." << endl;
    while(getch()!='q');
}

void BudgetManager::displayGeneralSummary() {
    double incomesSum;
    double expensesSum;
    double remainedAmount;
    incomesSum = incomes.sumBudgetPart();
    expensesSum = expenses.sumBudgetPart();
    remainedAmount = incomesSum - expensesSum;
    cout << fixed << setprecision(2);
    if(remainedAmount >= 0) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
        cout << "Oszczednosci : ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),32);
    } else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
        cout << "Dlug : ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),192);
    }
    cout << remainedAmount << endl;
    cout << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
}

void BudgetManager::displaySummaryLine(double incomesSum, double expensesSum) {
    double remainedAmount;
    remainedAmount = incomesSum - expensesSum;
    cout << fixed << setprecision(2) <<  endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    cout << "Przychody lacznie: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),32);
    cout << incomesSum ;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
    cout <<  "  Wydatki lacznie: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),192);
    cout << expensesSum ;
    if(remainedAmount >= 0) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
        cout << "  Oszczednosci : ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),32);
    } else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
        cout << "  Dlug : ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),192);
    }
    cout << remainedAmount << endl;
    cout << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
}

void BudgetManager::displayBudgetCurrentMonth() {
    Date date;
    int dateFrom = date.convertDateToInt(date.firstDayInCurrentMonth());
    int dateTo = date.convertDateToInt(date.lastDayInCurrentMonth());
    displayBudget(dateFrom, dateTo);
}

void BudgetManager::displayBudgetPreviousMonth() {
    Date date;
    int dateFrom = date.convertDateToInt(date.firstDayInPreviousMonth());
    int dateTo = date.convertDateToInt(date.lastDayInPreviousMonth());
    displayBudget(dateFrom, dateTo);
}

void BudgetManager::displayBudgetSpecificRange() {
    Date date;
    cout << "Data od. ";
    int dateFrom = date.convertDateToInt(date.writeDate());
    cout << "Data Do. ";
    int dateTo = date.convertDateToInt(date.writeDate());
    displayBudget(dateFrom, dateTo);
}

void BudgetManager::loadBudgetFromFiles() {
    incomes.loadBudgetPartFromXML();
    expenses.loadBudgetPartFromXML();
}

void BudgetManager::clearBudget() {
    incomes.clearVector();
    expenses.clearVector();
}
