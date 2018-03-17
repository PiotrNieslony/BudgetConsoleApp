#include "User.h"

int User::idLoggedUser = 0;

User::User(){};

User::User(int sId, string sName, string sSurname, string sLogin, string sPassword) {
    setAll (sId, sName, sSurname, sLogin, sPassword);
}

void User::setAll (int sId, string sName, string sSurname, string sLogin, string sPassword) {
    id = sId;
    name = sName;
    surname = sSurname;
    login = sLogin;
    password = sPassword;
}

void User::setIdLoggedUser(int id) {
    idLoggedUser = id;
}

int User::getIdLoggedUser() {
    return idLoggedUser;
}

int User::getId () {
    return id;
}

string User::getName () {
    return name;
}
string User::getSurname() {
    return surname;
}
string User::getLogin () {
    return login;
}

string User::getPassword () {
    return password;
}

bool User::checkPassword (string passwordToCompare) {
    if(password == passwordToCompare) return true;
    else return false;
}

void User::changePassword(string newPassword){
    password = newPassword;
}

