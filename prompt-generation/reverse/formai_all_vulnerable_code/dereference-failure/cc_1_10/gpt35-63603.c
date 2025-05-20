//FormAI DATASET v1.0 Category: Database querying ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

int main() {
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    char *server = "localhost";
    char *user = "root";
    char *password = "password";
    char *database = "mydb";

    conn = mysql_init(NULL);

    if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
        printf("Failed to connect to database: %s\n", mysql_error(conn));
        return 1;
    }

    printf("Connection to database successful!\n");

    char query[1000];

    printf("Please enter a name to search for: ");
    scanf("%s", query);

    sprintf(query, "SELECT * FROM users WHERE name='%s';", query);

    if (mysql_query(conn, query)) {
        printf("Failed to execute query: %s\n", mysql_error(conn));
        return 1;
    }

    res = mysql_use_result(conn);

    printf("Results:\n");
    printf("============================================\n\n");

    int row_count = 0;

    while ((row = mysql_fetch_row(res))) {
        printf("ID: %s\n", row[0]);
        printf("Name: %s\n", row[1]);
        printf("Age: %s\n", row[2]);
        printf("Email: %s\n\n", row[3]);

        row_count++;
    }

    mysql_free_result(res);
    mysql_close(conn);

    printf("Found %d result(s)!\n", row_count);

    return 0;
}