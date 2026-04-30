
#include "../business/IUserDao.h"

#include <sqlite3.h>

class UserDao : public IUserDao {
private:
    sqlite3* db;

    void InitDatabase();

public:
    UserDao(const char* dbPath);
    ~UserDao();

    User* GetUserByRfid(const std::string& rfid) override;
};
