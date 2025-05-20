//FormAI DATASET v1.0 Category: Database querying ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

// Define the MySQL connection variables
#define DB_HOST "localhost"
#define DB_USER "root"
#define DB_PASSWORD "password"
#define DB_DATABASE "test_database"

// Define the query string
#define QUERY "SELECT * FROM users WHERE age > 30"

int main()
{
    // Declare the MySQL connection object
    MYSQL *conn = mysql_init(NULL);

    // Check for connection errors
    if (conn == NULL)
    {
        fprintf(stderr, "Error: could not initialize MySQL connection object\n");
        exit(1);
    }

    // Connect to the database
    if (mysql_real_connect(conn, DB_HOST, DB_USER, DB_PASSWORD, DB_DATABASE, 0, NULL, 0) == NULL)
    {
        fprintf(stderr, "Error: could not connect to database: %s\n", mysql_error(conn));
        mysql_close(conn);
        exit(1);
    }

    // Execute the query
    if (mysql_query(conn, QUERY) != 0)
    {
        fprintf(stderr, "Error: could not execute query: %s\n", mysql_error(conn));
        mysql_close(conn);
        exit(1);
    }

    // Store the query result
    MYSQL_RES *result = mysql_use_result(conn);

    // Check for null result
    if (result == NULL)
    {
        fprintf(stderr, "Error: no rows returned\n");
        mysql_close(conn);
        exit(1);
    }

    // Loop through the rows and print the results
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(result)) != NULL)
    {
        printf("ID: %s\n", row[0]);
        printf("Name: %s\n", row[1]);
        printf("Age: %s\n", row[2]);
        printf("=====================\n");
    }

    // Free the result and close the connection
    mysql_free_result(result);
    mysql_close(conn);

    return 0;
}