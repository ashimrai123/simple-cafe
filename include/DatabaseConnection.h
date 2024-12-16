#ifndef DATABASE_CONNECTION_H
#define DATABASE_CONNECTION_H

#include <string>
#include <libpq-fe.h>

class DatabaseConnection
{
public:
    DatabaseConnection(const std::string &connInfo);
    ~DatabaseConnection();
    PGresult *executeQuery(const std::string &query);
    bool insertData(const std::string &table, const std::string &columns, const std::string &values); // Method to insert data
private:
    PGconn *conn;
};

#endif
