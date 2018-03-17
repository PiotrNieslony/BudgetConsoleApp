#include <iostream>
//#include <iomanip>
#include "User.h"
#include "Users.h"
#include "Date.h"
#include "IncomeBudget.h"
#include "Income.h"


using namespace std;

int main() {
    User user;
    Users users;
    IncomeBudget incomes;
    Income income(20180303, "Wyplata1", 125.30);
    Income income2(20180404, "Wyplata2", 1000);
    Income income3(20180305, "Wyplata3", 150);
    Income income4(20160305, "Wyplata3", 150);
    Income income5(20160305, "Wyplata2", 150);
    incomes.addIncome(income);
    incomes.addIncome(income2);
    incomes.addIncome(income3);
    incomes.addIncome(income4);
    incomes.addIncome(income5);
    incomes.displayIncomes();
    char choice;
    while(true) {
        if (user.getIdLoggedUser() == 0) {
            //system("cls");
            cout << "Id zalogowanego uzytkownidka: " <<  user.getIdLoggedUser() << endl;
            cout << "Ilosc zarejestrowanycjh uzytkownikow: " << users.numberOfRegisteredUsers() << endl;
            cout << "Menu logowania" << endl;
            cout <<"----------------" << endl;
            cout << "1. Zalogu sie" << endl;
            cout << "2. Zarejestruj sie" << endl;
            cout << "3. Wyswietl uzytkownikow" << endl;
            cout << "9. Zamknij program" << endl;
            cout << endl << "wybierz: ";
            cin >> choice;
            cin.sync();
            if(choice == '1') {
                users.logIn();
            } else if (choice == '2') {
                system("cls");
                users.singUp();
            } else if (choice == '3') {
                users.displayUsers();
            } else if (choice == '9') {
                exit(0);
            }
        } else {
            system("cls");
            cout << "Id zalogowanego uzytkownidka: " <<  user.getIdLoggedUser() << endl;
            cout << "Menu glowne" << endl;
            cout <<"----------------" << endl;
            cout << "1. Dodaj przychod" << endl;
            cout << "2. ~~Dodaj wydatek" << endl;
            cout << "3. ~~Bilans z biezacego miesiaca" << endl;
            cout << "4. ~~Bilans z poprzedniego miesiaca" << endl;
            cout << "5. ~~Bilans z wybranego okresu" << endl;
            cout << "7. Zmien haslo" << endl;
            cout << "8. Wyloguj sie" << endl;
            cout << "9. Zamknij program" << endl;
            cin >> choice;
            cin.sync();
            if(choice == '1') {
                incomes.writeIncome();
            } else if (choice == '2') {

            } else if (choice == '3') {
                incomes.displayIncomes();
            } else if (choice == '4') {

            } else if (choice == '5') {

            } else if (choice == '7') {
                users.changePassword();
            } else if (choice == '8') {
                user.setIdLoggedUser(0);
            } else if (choice == '9') {
                exit(0);
            }
        }


    }
    return 0;
}