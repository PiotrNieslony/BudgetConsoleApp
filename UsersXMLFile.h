#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>
#include "User.h"
#include "File.h"
#include "Conversion.h"

#ifndef USERS_FILE_H
#define USERS_FILE_H

using namespace std;

class UsersXMLFile :public File {
    static CMarkup xmlUsers;
public:
    UsersXMLFile();
    UsersXMLFile(string name);
    void editRecord(User user);
    void addRecord(User user);
    void loadAllRecords(vector<User> & listOfUser);
};

#endif
