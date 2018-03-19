#include "Users.h"

Users::Users(){
    UsersXMLFile usersFile;
    usersFile.loadAllRecords(listOfUser);
}

void Users::addUser(User user) {
    listOfUser.push_back(user);
}

void Users::displayUsers() {
    system("cls");
    vector<User>::iterator vectorEnd = listOfUser.end();
    for(vector<User>::iterator itr = listOfUser.begin(); itr != vectorEnd; ++itr) {
        cout << " ~ " << (*itr).getId() << " | "
        << (*itr).getName() << " | "
        << (*itr).getSurname() << " | "
        << (*itr).getLogin() << " | " << endl;
    }
    system("pause");
}

int Users::numberOfRegisteredUsers(){
    return listOfUser.size();
}

int Users::idOfLastUser() {
    if (listOfUser.size() == 0) return 0;
    vector<User>::iterator lastUser = listOfUser.end();
    --lastUser;
    return (*lastUser).getId();

}

void Users::singUp() {
    UsersXMLFile file;
    string name, surname, login, password;
    cout << "Podaj imie uzytkownika: ";
    cin >> name;
    cout << "Podaj nazwisko: ";
    cin >> surname;
    cout << "Podaj login: ";
    cin >> login;
    vector<User>::iterator vectorEnd = listOfUser.end();
    for(vector<User>::iterator itr = listOfUser.begin(); itr != vectorEnd; ++itr) {
        if((*itr).getName() == login) {
            cout << "Ta nazwa jest juz zajeta. Wpisz inny login: ";
            cin >> login;
            itr = listOfUser.begin();
        }
    }
    cout << "Podaj haslo: ";
    cin >> password;

    User singleUser(idOfLastUser() + 1, name, surname, login, password);
    addUser(singleUser);

    UsersXMLFile usersFile();
    file.addRecord(singleUser);
}

int Users::logIn() {
    ConsoleMessage message;
    int id;
    string login, password;
    cout << "Podaj nazwe:  ";
    cin >> login;
    vector<User>::iterator vectorEnd = listOfUser.end();
    for(vector<User>::iterator itr = listOfUser.begin(); itr != vectorEnd; ++itr) {
        if((*itr).getLogin() == login) {
            for(int j=3; j>0; j--) {
                cout << "Podaj haslo. pozostalo prob " << j << ": ";
                cin >> password;
                if ((*itr).checkPassword(password)) {
                    cout << "Zalogowales sie" << endl;
                    id = (*itr).getId();
                    (*itr).setIdLoggedUser(id);
                    Sleep(1000);
                    return id;
                }
            }
            message.display("Podales 3 razy bledne haslo, odczekaj 3s", "warning", 3000);
            return 0;
        }
    }
    message.display("Nie ma uzytkownika: " + login, "warning");
    return 0;
}

void Users::changePassword() {
    User user;
    int idLoggedUser = user.getIdLoggedUser();
    string password;
    UsersXMLFile file;
    vector<User>::iterator vectorEnd = listOfUser.end();
    for(vector<User>::iterator itr = listOfUser.begin(); itr != vectorEnd; ++itr) {
        if((*itr).getId() == idLoggedUser) {
            cout << "Wprawadz nowe haslo: ";
            cin >> password;
            (*itr).changePassword(password);
            file.editRecord(*itr);
        }
    }
}
