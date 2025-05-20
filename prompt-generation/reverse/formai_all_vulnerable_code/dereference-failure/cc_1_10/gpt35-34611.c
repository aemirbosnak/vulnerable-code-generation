//FormAI DATASET v1.0 Category: Database querying ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

// Defining the database server credentials
#define DB_HOST "localhost"
#define DB_USER "root"
#define DB_PASS "password"
#define DB_NAME "mydatabase"

// Function declaration for database querying
void query_database(MYSQL *conn);

// Main function
int main()
{
    MYSQL *conn = mysql_init(NULL);

    if (conn == NULL)
    {
        fprintf(stderr, "Error: %s\n", mysql_error(conn));
        exit(1);
    }

    // Connecting to the database server
    if (mysql_real_connect(conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 0, NULL, 0) == NULL)
    {
        fprintf(stderr, "Error: %s\n", mysql_error(conn));
        exit(1);
    }

    // Querying the database
    query_database(conn);

    // Closing the database connection
    mysql_close(conn);
    return 0;
}

void query_database(MYSQL *conn)
{
    // Executing a SELECT statement to fetch all the records from a table
    if (mysql_query(conn, "SELECT * FROM mytable"))
    {
        fprintf(stderr, "Error: %s\n", mysql_error(conn));
    }
    else
    {
        MYSQL_RES *result = mysql_store_result(conn);

        if (result == NULL)
        {
            fprintf(stderr, "Error: %s\n", mysql_error(conn));
        }
        else
        {
            // Printing all the fetched records
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(result)))
            {
                printf("%s %s %s\n", row[0], row[1], row[2]);
            }

            mysql_free_result(result);
        }
    }
}