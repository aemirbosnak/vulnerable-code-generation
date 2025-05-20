//FormAI DATASET v1.0 Category: Database querying ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

int main(int argc, char **argv)
{
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    char *server = "localhost";
    char *user = "root";
    char *password = "password"; // change to your database password
    char *database = "dbname";
    char query[255];

    conn = mysql_init(NULL);

    // Connect to the database
    if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
    {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    // Initialize the query string
    memset(query, 0, sizeof(query));

    // Build the query string
    snprintf(query, sizeof(query), "SELECT * FROM users WHERE username = '%s' AND password = '%s'", argv[1], argv[2]);

    // Execute the query
    if (mysql_query(conn, query))
    {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    // Get the result set
    res = mysql_store_result(conn);

    // Iterate through the rows
    while ((row = mysql_fetch_row(res)))
    {
        // Print the values
        printf("%s %s %s\n", row[0], row[1], row[2]);
    }

    // Free the result set
    mysql_free_result(res);

    // Close the connection
    mysql_close(conn);

    return 0;
}