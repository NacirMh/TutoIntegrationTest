#include "AuthenticationService.h"
#include <string>

AuthenticationService::AuthenticationService(IUserDao* userDao)
    : userDao(userDao) {}

bool AuthenticationService::VerifyUser(const std::string& rfid) {
    return userDao->GetUserByRfid(rfid) != nullptr;
}