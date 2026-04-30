#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    int id;
    std::string name;
    std::string rfid;

public:
    User(int id, const std::string& name, const std::string& rfid);
};

#endif