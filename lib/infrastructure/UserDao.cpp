#ifndef USERDAO_H
#define USERDAO_H

#include "UserDao.h"
#include <iostream>
#include <string>
#include "sqlite3.h"
#include "User.h"

UserDao::UserDao(const char* dbPath) : db(nullptr) {
    if (sqlite3_open(dbPath, &db)) {
        std::cerr << "Can't open database\n";
    } else {
        InitDatabase();
    }
}

UserDao::~UserDao() {
    if (db) sqlite3_close(db);
}

void UserDao::InitDatabase() {
    const char* sql =
        "CREATE TABLE IF NOT EXISTS users ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "name TEXT, "
        "rfid TEXT UNIQUE);";

    char* errMsg = nullptr;
    if (sqlite3_exec(db, sql, nullptr, nullptr, &errMsg) != SQLITE_OK) {
        std::cerr << errMsg << std::endl;
        sqlite3_free(errMsg);
    }

    sqlite3_exec(db,
        "INSERT OR IGNORE INTO users (id, name, rfid) VALUES (1, 'Nacir', '123');",
        nullptr, nullptr, nullptr);

    sqlite3_exec(db,
        "INSERT OR IGNORE INTO users (id, name, rfid) VALUES (2, 'Bakir', '456');",
        nullptr, nullptr, nullptr);
}

User* UserDao::GetUserByRfid(const std::string& rfid) {
    sqlite3_stmt* stmt;
    std::string query = "SELECT id, name, rfid FROM users WHERE rfid = ?";

    if (sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        return nullptr;
    }

    sqlite3_bind_text(stmt, 1, rfid.c_str(), -1, SQLITE_TRANSIENT);

    User* user = nullptr;

    if (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        std::string name = (const char*)sqlite3_column_text(stmt, 1);
        std::string rfid_db = (const char*)sqlite3_column_text(stmt, 2);

        user = new User(id, name, rfid_db);
    }

    sqlite3_finalize(stmt);
    return user;
}

#endif