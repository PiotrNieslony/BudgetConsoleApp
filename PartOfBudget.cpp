#include "PartOfBudget.h"

PartOfBudget::PartOfBudget(string sFileName)
    : budgetPartXMLFile(sFileName) {
    lastBudgetPartId = 0;
    fileName = sFileName;
}

void PartOfBudget::setLastBudgetPartItemId(int id) {
    lastBudgetPartId = id;
    BudgetItem budgetItem;
    budgetItem.setLastId(id);
}

void PartOfBudget::addBudgetItem(BudgetItem budgetItem) {
    budgetItem.setLastId(lastBudgetPartId);
    lastBudgetPartId++;
    incomes.push_back(budgetItem);
    budgetPartXMLFile.addRecord(budgetItem);

}

void PartOfBudget::writeBudgetItem() {
    BudgetItem budgetItem;
    budgetItem.setLastId(lastBudgetPartId);
    lastBudgetPartId++;
    budgetItem.writeBudgetItem();
    incomes.push_back(budgetItem);
    budgetPartXMLFile.addRecord(budgetItem);
}

void PartOfBudget::displaySeparatingLineTop() {
    const char LEFT_CORNER = 218;
    const char CROSS_LINE = 194;
    const char MIDDLE_LINE = 196;
    const char RIGHT_CORNER = 191;
    const int QUANTITY_OF_DISPLAYED_CHARACTERS = 70;
    for(int i = 0; i < QUANTITY_OF_DISPLAYED_CHARACTERS ; i++) {
        if (i == 0) cout << LEFT_CORNER;
        else if((i == 5)||(i == 17)||(i == 58)) cout << CROSS_LINE;
        else if(i == 69) cout << RIGHT_CORNER;
        else cout << MIDDLE_LINE;
    }
    cout << endl;
}

void PartOfBudget::displaySeparatingLineMiddle() {
    const char LEFT_EDGE = 195;
    const char CROSS_LINE = 179;
    const char MIDDLE_LINE = 196;
    const char RIGHT_EDGE = 180;
    const int QUANTITY_OF_DISPLAYED_CHARACTERS = 70;
    for(int i = 0; i < QUANTITY_OF_DISPLAYED_CHARACTERS ; i++) {
        if (i == 0) cout << LEFT_EDGE;
        else if((i == 5)||(i == 17)||(i == 58)) cout << CROSS_LINE;
        else if(i == 69) cout << RIGHT_EDGE;
        else cout << MIDDLE_LINE;
    }
    cout << endl;
}

void PartOfBudget::displaySeparatingLineBottom() {
    const char LEFT_CORNER = 192;
    const char CROSS_LINE = 193;
    const char MIDDLE_LINE = 196;
    const char RIGHT_CORNER = 217;
    const int QUANTITY_OF_DISPLAYED_CHARACTERS = 70;
    for(int i = 0; i < QUANTITY_OF_DISPLAYED_CHARACTERS ; i++) {
        if (i == 0) cout << LEFT_CORNER;
        else if((i == 5)||(i == 17)||(i == 58)) cout << CROSS_LINE;
        else if(i == 69) cout << RIGHT_CORNER;
        else cout << MIDDLE_LINE;
    }
    cout << endl;
}

void PartOfBudget::displaySeparatingLine() {
    const char CHARACTER = 205;
    const int QUANTITY_OF_DISPLAYED_CHARACTERS = 70;
    for(int i = 0; i < QUANTITY_OF_DISPLAYED_CHARACTERS ; i++) cout << CHARACTER;
    cout << endl;
}

string PartOfBudget::generateDashes(int quantity) {
    string dashes = "";
    for(int i = 0; i < quantity ; i++) dashes += "_";
    return dashes;
}

void PartOfBudget::displayHeaderTable() {
    printf ("|%4s|%11s|%40s|%10s|\n",
            "id", "data", "nazwa", "kwota");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    displaySeparatingLineMiddle();
}

void PartOfBudget::displayTableRow(BudgetItem budgetItem) {
    string source = budgetItem.getSource();
    source = generateDashes(40-source.length()) + source;
    printf ("|%4i|%11s|%40s|%10.2f|\n",
            budgetItem.getId(),
            date.convertDateToString(budgetItem.getDate()).c_str(),
            source.c_str(),
            budgetItem.getAmount());
}

double PartOfBudget::displayPartOfBudget(int dateFrom, int dateTo) {
    stringstream buffer;
    int date;
    double partOfBudgetSum = 0;
    sort(incomes.begin(), incomes.end());
    displaySeparatingLineTop();
    displayHeaderTable();
    vector<BudgetItem>::iterator vectorEnd = incomes.end();
    for(vector<BudgetItem>::iterator itr = incomes.begin(); itr != vectorEnd; ++itr) {
        date = (*itr).getDate();
        if((date >= dateFrom) && (date <= dateTo)) {
            displayTableRow(*itr);
            partOfBudgetSum += (*itr).getAmount();
        }
    }
    displaySeparatingLineBottom();
    return partOfBudgetSum;
}

double PartOfBudget::sumBudgetPart() {
    double incomesSum = 0;
    vector<BudgetItem>::iterator vectorEnd = incomes.end();
    for(vector<BudgetItem>::iterator itr = incomes.begin(); itr != vectorEnd; ++itr) {
        incomesSum += (*itr).getAmount();
    }
    return incomesSum;
}

void PartOfBudget::loadBudgetPartFromXML() {
    lastBudgetPartId = budgetPartXMLFile.loadAllRecords(incomes);
}

void PartOfBudget::clearVector() {
    incomes.clear();
}
