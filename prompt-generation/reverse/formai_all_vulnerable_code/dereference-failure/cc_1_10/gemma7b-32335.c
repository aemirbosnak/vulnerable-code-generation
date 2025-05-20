//Gemma-7B DATASET v1.0 Category: Database querying ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define HOST "localhost"
#define USER "root"
#define PASS "password"
#define DB "my_database"

int main()
{
    // Database connection parameters
    MYSQL *conn;
    char query[255];
    int result;
    MYSQL_RES *res;
    MYSQL_ROW *row;

    // Connecting to the database
    conn = mysql_init(NULL);
    if (!conn)
    {
        printf("Error: %s\n", mysql_error(conn));
        exit(1);
    }

    // Selecting the database
    if (!mysql_select_db(conn, DB))
    {
        printf("Error: %s\n", mysql_error(conn));
        exit(1);
    }

    // Building the query
    sprintf(query, "SELECT * FROM employees WHERE name LIKE '%John%'");

    // Executing the query
    res = mysql_query(conn, query);

    // Checking for errors
    if (!res)
    {
        printf("Error: %s\n", mysql_error(conn));
        exit(1);
    }

    // Iterating over the results
    row = mysql_fetch_row(res);
    while (row)
    {
        // Printing the results
        printf("ID: %d, Name: %s, Email: %s\n", row[0], row[1], row[2]);

        // Getting the next row
        row = mysql_fetch_row(res);
    }

    // Closing the connection
    mysql_close(conn);

    return 0;
}