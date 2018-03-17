#include "IncomeBudget.h"

void IncomeBudget::setLastIncomeId(int id) {
    lastIncomeId = id;
    Income income;
    income.setLastId(id);
}

void IncomeBudget::addIncome(Income income) {
    incomes.push_back(income);
    sort(incomes.begin(), incomes.end());
}

void IncomeBudget::writeIncome() {
    Income income;
    income.writeIncome();
    incomes.push_back(income);
    sort(incomes.begin(), incomes.end());
}

void IncomeBudget::displaySeparatingLine() {
    const int QUANTITY_OF_DISPLAYED_CHARACTERS = 70;
    for(int i = 0; i < QUANTITY_OF_DISPLAYED_CHARACTERS ; i++) cout << "_";
    cout << endl;
}

string IncomeBudget::generateDashes(int quantity) {
    string dashes = "";
    for(int i = 0; i < quantity ; i++) dashes += "_";
    return dashes;
}

void IncomeBudget::displayHeaderTable() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    printf ("|%4s|%11s|%40s|%10s|\n",
            "id", "data", "nazwa", "kwota");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    displaySeparatingLine();
}

void IncomeBudget::displayTableRow(Income income) {
    string source = income.getSource();
    source = generateDashes(40-source.length()) + source;
    printf ("|%4i|%11s|%40s|%10.2f|\n",
            income.getId(),
            date.convertDateToString(income.getDate()).c_str(),
            source.c_str(),
            income.getAmount());
}

void IncomeBudget::displayIncomes() {
    ("cls");
    displaySeparatingLine();
    displayHeaderTable();
    vector<Income>::iterator vectorEnd = incomes.end();
    for(vector<Income>::iterator itr = incomes.begin(); itr != vectorEnd; ++itr) {
        displayTableRow(*itr);
    }
    displaySeparatingLine();
    sumIncomes();
    system("pause");
}

double IncomeBudget::sumIncomes() {
    double incomesSum = 0;
    vector<Income>::iterator vectorEnd = incomes.end();
    for(vector<Income>::iterator itr = incomes.begin(); itr != vectorEnd; ++itr) {
        incomesSum += (*itr).getAmount();
    }
    cout << "Suma przychodow: "<< fixed << setprecision(2) << incomesSum << endl;
    return incomesSum;
}
