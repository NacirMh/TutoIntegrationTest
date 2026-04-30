#pragma once
#include "IUserDao.h"

class AuthenticationService{
private:
    IUserDao* userDao;

public:
    AuthenticationService(IUserDao* userDao);
    bool VerifyUser(const std::string& rfid);
};

