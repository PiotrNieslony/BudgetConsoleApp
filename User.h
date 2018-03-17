#include <iostream>

using namespace std;

#ifndef USER_H
#define USER_H

class User {
    int id;
    static int idLoggedUser;
    string name, surname, login, password;
public:
    User();
    User(int id, string name, string surname, string login, string password);
    void setAll (int id, string name, string surname, string login, string password);
    void setIdLoggedUser(int id);
    int getId();
    int getIdLoggedUser();
    string getName();
    string getSurname();
    string getLogin();
    string getPassword();
    bool checkPassword(string passwordToCompare);
    void changePassword(string newPassword);
};

#endif
