#include "Database.hpp"

Database::Database(const std::string& filename) {
    sqlite3_open(filename.c_str(), &db);
}

Database::~Database() {
    sqlite3_close(db);
}

bool Database::execute(const std::string& sql) {
    char* err = nullptr;
    return sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &err) == SQLITE_OK;
}

void Database::bindOne(sqlite3_stmt* stmt, int index, int value) {
    sqlite3_bind_int(stmt, index, value);
}

void Database::bindOne(sqlite3_stmt* stmt, int index, float value) {
    sqlite3_bind_double(stmt, index, value);
}

void Database::bindOne(sqlite3_stmt* stmt, int index, double value) {
    sqlite3_bind_double(stmt, index, value);
}

void Database::bindOne(sqlite3_stmt* stmt, int index, const std::string& value) {
    sqlite3_bind_text(stmt, index, value.c_str(), -1, SQLITE_TRANSIENT);
}
