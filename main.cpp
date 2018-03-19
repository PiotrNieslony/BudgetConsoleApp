#include <iostream>
//#include <iomanip>
#include "User.h"
#include "Users.h"
#include "Date.h"
#include "PartOfBudget.h"
#include "BudgetItem.h"
#include "BudgetManager.h"


using namespace std;

void displayHeaderOfAplication(){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
    cout << "Budzet v 0.1" << endl << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
}

int main()
{
    User user;
    Users users;
    BudgetManager budget;
    char choice;
    while(true)
    {
        if (user.getIdLoggedUser() == 0)
        {
            system("cls");
            displayHeaderOfAplication();
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
            cout << "Ilosc zarejestrowanycjh uzytkownikow: " << users.numberOfRegisteredUsers() << endl << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
            cout << "Menu logowania" << endl;
            cout <<"----------------" << endl;
            cout << "1. Zalogu sie" << endl;
            cout << "2. Zarejestruj sie" << endl;
            cout << "3. Wyswietl uzytkownikow" << endl;
            cout << "9. Zamknij program" << endl;
            cout << endl << "wybierz: ";
            cin >> choice;
            cin.sync();
            if(choice == '1')
            {
                if(users.logIn()) budget.loadBudgetFromFiles();
            }
            else if (choice == '2')
            {
                system("cls");
                users.singUp();
            }
            else if (choice == '3')
            {
                users.displayUsers();
            }
            else if (choice == '9')
            {
                exit(0);
            }
        }
        else
        {
            system("cls");
            displayHeaderOfAplication();
            budget.displayGeneralSummary();
            cout << "Menu glowne" << endl;
            cout <<"----------------" << endl;
            cout << "1. Dodaj przychod" << endl;
            cout << "2. Dodaj wydatek" << endl;
            cout << "3. Bilans z biezacego miesiaca" << endl;
            cout << "4. Bilans z poprzedniego miesiaca" << endl;
            cout << "5. Bilans z wybranego okresu" << endl;
            cout << "7. Zmien haslo" << endl;
            cout << "8. Wyloguj sie" << endl;
            cout << "9. Zamknij program" << endl;
            cout << endl << "wybierz: ";
            cin >> choice;
            cin.sync();
            if(choice == '1')
            {
                budget.addIncome();
            }
            else if (choice == '2')
            {
                budget.addExpense();
            }
            else if (choice == '3')
            {
                budget.displayBudgetCurrentMonth();
            }
            else if (choice == '4')
            {
                budget.displayBudgetPreviousMonth();
            }
            else if (choice == '5')
            {
                budget.displayBudgetSpecificRange();
            }
            else if (choice == '7')
            {
                users.changePassword();
            }
            else if (choice == '8')
            {
                budget.clearBudget();
                user.setIdLoggedUser(0);
            }
            else if (choice == '9')
            {
                exit(0);
            }
        }


    }
    return 0;
}
