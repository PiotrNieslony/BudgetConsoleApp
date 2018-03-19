#include <windows.h>
#include "PartOfBudget.h"

using namespace std;

class BudgetManager {
    PartOfBudget incomes;
    PartOfBudget expenses;
    void displayBudget(int dateFrom, int dateTo);
    void displaySummaryLine(double incomesSum, double expensesSum);
public:
    BudgetManager();
    void addIncome();
    void addExpense();
    void displayGeneralSummary();
    void displayBudgetCurrentMonth();
    void displayBudgetPreviousMonth();
    void displayBudgetSpecificRange();
    void loadBudgetFromFiles();
    void clearBudget();
};
