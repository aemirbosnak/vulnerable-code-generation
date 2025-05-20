//Falcon-180B DATASET v1.0 Category: Database querying ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define DATABASE "testdb"
#define USER "testuser"
#define PASSWORD "testpassword"
#define HOST "localhost"
#define PORT 3306

int main() {
    MYSQL *conn;
    MYSQL_RES *result;
    MYSQL_ROW row;
    char query[100];
    char *servername = HOST;
    char *user = USER;
    char *password = PASSWORD;
    char *database = DATABASE;

    conn = mysql_init(NULL);

    if (!mysql_real_connect(conn, servername, user, password, database, PORT, NULL, 0)) {
        printf("Error: Unable to connect to MySQL: %s\n", mysql_error(conn));
        exit(1);
    }

    printf("Connected to MySQL\n");

    // Query 1: Select all records from a table
    sprintf(query, "SELECT * FROM employees");
    if (mysql_query(conn, query)) {
        printf("Error: Query failed: %s\n", mysql_error(conn));
        exit(1);
    }

    result = mysql_store_result(conn);
    printf("Query 1 result:\n");
    while ((row = mysql_fetch_row(result))!= NULL) {
        printf("%s\t%s\t%s\t%s\n", row[0], row[1], row[2], row[3]);
    }
    mysql_free_result(result);

    // Query 2: Update a record in a table
    sprintf(query, "UPDATE employees SET salary = 5000 WHERE id = 1");
    if (mysql_query(conn, query)) {
        printf("Error: Query failed: %s\n", mysql_error(conn));
        exit(1);
    }

    printf("Query 2 executed successfully\n");

    // Query 3: Delete a record from a table
    sprintf(query, "DELETE FROM employees WHERE id = 2");
    if (mysql_query(conn, query)) {
        printf("Error: Query failed: %s\n", mysql_error(conn));
        exit(1);
    }

    printf("Query 3 executed successfully\n");

    mysql_close(conn);

    return 0;
}