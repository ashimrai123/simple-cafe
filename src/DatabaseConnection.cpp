#include "../include/DatabaseConnection.h"
#include <iostream>

DatabaseConnection::DatabaseConnection(const std::string &connInfo)
{
    // Connect to the database using the connection info
    conn = PQconnectdb(connInfo.c_str());

    // Check the connection status
    if (PQstatus(conn) != CONNECTION_OK)
    {
        std::cerr << "Connection to database failed: " << PQerrorMessage(conn) << std::endl;
        PQfinish(conn); // Close the connection if failed
        exit(1);        // Exit the program with an error code
    }
    else
    {
        std::cout << "Database connection successful!" << std::endl;
    }
}

DatabaseConnection::~DatabaseConnection()
{
    // Close the database connection
    if (conn)
    {
        PQfinish(conn);
    }
}

PGresult *DatabaseConnection::executeQuery(const std::string &query)
{
    // Execute the query and return the result
    PGresult *res = PQexec(conn, query.c_str());

    // Check for errors in the query execution
    if (PQresultStatus(res) != PGRES_COMMAND_OK && PQresultStatus(res) != PGRES_TUPLES_OK)
    {
        std::cerr << "Query execution failed: " << PQerrorMessage(conn) << std::endl;
        PQclear(res); // Clear the result to avoid memory leak
        return nullptr;
    }

    return res;
}

bool DatabaseConnection::insertData(const std::string &table, const std::string &columns, const std::string &values)
{
    // Construct the SQL INSERT query
    std::string query = "INSERT INTO " + table + " (" + columns + ") VALUES (" + values + ")";

    // Execute the query
    PGresult *res = executeQuery(query);

    // If the query execution was successful, return true, otherwise false
    if (res)
    {
        PQclear(res); // Clear the result to avoid memory leak
        return true;
    }
    return false;
}
