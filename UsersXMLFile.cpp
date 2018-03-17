#include "UsersXMLFile.h"

CMarkup UsersXMLFile::xmlUsers;

UsersXMLFile::UsersXMLFile()
    :File("Users.xml") {
}

UsersXMLFile::UsersXMLFile(string name)
    :File(name) {
    fileName = name;
}

void UsersXMLFile::addRecord(User user) {

    bool statusOfSave = false;
    if(isFileEmpty()) {
        xmlUsers.AddElem( "Users" );
        xmlUsers.IntoElem();
    } else {
        xmlUsers.ResetPos();
        xmlUsers.FindElem();
        xmlUsers.IntoElem();
    }

    xmlUsers.AddElem("User");
    xmlUsers.IntoElem();
    xmlUsers.AddElem( "ulserId",  user.getId());
    xmlUsers.AddElem( "name",     user.getName());
    xmlUsers.AddElem( "surname",  user.getSurname());
    xmlUsers.AddElem( "login",    user.getLogin());
    xmlUsers.AddElem( "password", user.getPassword());
    xmlUsers.OutOfElem();

    statusOfSave = xmlUsers.Save(fileName.c_str());
    if(statusOfSave) cout << "Dodano dane do pliku XML" << endl;
    else cout << "Wyst¹pil problem podczas zapisu danch do plikku" << endl;
}

void UsersXMLFile::editRecord(User user) {
    bool statusOfSave = false;
    int userId = user.getId();
    int userIdXml;

    xmlUsers.ResetPos();
    xmlUsers.FindElem();
    xmlUsers.IntoElem();
    while ( xmlUsers.FindElem("User") ) {
        xmlUsers.IntoElem();
        xmlUsers.FindElem("ulserId");
        userIdXml = atoi( MCD_2PCSZ(xmlUsers.GetData()) );
        if(userIdXml == userId) {
            xmlUsers.FindElem("name");
            xmlUsers.SetData(user.getName());
            xmlUsers.FindElem("surname");
            xmlUsers.SetData(user.getSurname());
            xmlUsers.FindElem("login");
            xmlUsers.SetData(user.getLogin());
            xmlUsers.FindElem("password");
            xmlUsers.SetData(user.getPassword());
            break;
        }
        xmlUsers.OutOfElem();
    }

    statusOfSave = xmlUsers.Save(fileName.c_str());
    if(statusOfSave) cout << "Dodano dane do pliku XML" << endl;
    else cout << "Wystlpil problem podczas zapisu danch do plikku" << endl;
}

void UsersXMLFile::loadAllRecords(vector<User>& listOfUser) {
    bool statusOfLoad = false;
    int id;
    string name, surname, login, password;
    User singleUser;
    fstream usersFile;

    statusOfLoad = xmlUsers.Load(fileName.c_str());
    if(!statusOfLoad) cout << "Wystlpil problem podczas odczytu danch do pliku: "  << fileName << endl;

    xmlUsers.FindElem();
    xmlUsers.IntoElem();
    while ( xmlUsers.FindElem("User") ) {
        xmlUsers.IntoElem();
        xmlUsers.FindElem("ulserId");
        id = atoi( MCD_2PCSZ(xmlUsers.GetData()) );
        xmlUsers.FindElem("name");
        name = xmlUsers.GetData();
        xmlUsers.FindElem("surname");
        surname = xmlUsers.GetData();
        xmlUsers.FindElem("login");
        login = xmlUsers.GetData();
        xmlUsers.FindElem("password");
        password = xmlUsers.GetData();
        xmlUsers.OutOfElem();
        singleUser.setAll(id, name, surname, login, password);
        listOfUser.push_back(singleUser);
    }
}


