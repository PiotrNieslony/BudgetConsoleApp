#include <iostream>
#include <vector>
#include <windows.h>
#include <cstdio>
#include "User.h"
#include "ConsoleMessage.h"
#include "UsersXMLFile.h"

using namespace std;

class Users {
    vector<User> listOfUser;
    int idLoggedUser;
    void addUser(User user);
    int idOfLastUser();
public:
    Users();
    void displayUsers();
    int numberOfRegisteredUsers();
    int logIn();
    int logOut();
    void singUp();
    void changePassword();
};
