#pragma once
#include <sqlite3.h>
#include <string>

class Database {
private:
    sqlite3* db;

public:
    Database(const std::string& filename);
    ~Database();

    bool execute(const std::string& sql);

    template<typename... Args>
    bool execute(const std::string& sql, Args... args) {
        sqlite3_stmt* stmt;
        if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK)
            return false;

        bindAll(stmt, 1, args...);

        bool ok = (sqlite3_step(stmt) == SQLITE_DONE);
        sqlite3_finalize(stmt);
        return ok;
    }

private:
    void bindOne(sqlite3_stmt* stmt, int index, int value);
    void bindOne(sqlite3_stmt* stmt, int index, float value);
    void bindOne(sqlite3_stmt* stmt, int index, double value);
    void bindOne(sqlite3_stmt* stmt, int index, const std::string& value);

    template<typename T, typename... Rest>
    void bindAll(sqlite3_stmt* stmt, int index, T value, Rest... rest) {
        bindOne(stmt, index, value);
        bindAll(stmt, index + 1, rest...);
    }

    void bindAll(sqlite3_stmt* stmt, int index) {}
};
