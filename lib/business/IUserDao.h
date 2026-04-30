#ifndef IUSERDAO_H
#define IUSERDAO_H

#include <string>
#include "User.h"

class IUserDao {
public:
    virtual ~IUserDao() = default;
    virtual User* GetUserByRfid(const std::string& rfid) = 0;
};

#endif