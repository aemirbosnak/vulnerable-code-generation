//FormAI DATASET v1.0 Category: Database querying ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

int main() {
    MYSQL *connection = mysql_init(NULL);

    if (connection == NULL) {
        fprintf(stderr, "Failed to initialize database connection. Error: %s\n", mysql_error(connection));
        exit(1);
    }

    const char* hostname = "localhost";
    const char* username = "root";
    const char* password = "mypassword";
    const char* database_name = "mydatabase";

    if (mysql_real_connect(connection, hostname, username, password, database_name, 0, NULL, 0) == NULL) {
        fprintf(stderr, "Failed to connect to database. Error: %s\n", mysql_error(connection));
        mysql_close(connection);
        exit(1);
    }

    const char* query = "SELECT name, age FROM users WHERE age > 18";

    if (mysql_query(connection, query) != 0) {
        fprintf(stderr, "Failed to execute query. Error: %s\n", mysql_error(connection));
        mysql_close(connection);
        exit(1);
    }

    MYSQL_RES* result = mysql_use_result(connection);

    if (result == NULL) {
        fprintf(stderr, "Failed to retrieve result. Error: %s\n", mysql_error(connection));
        mysql_close(connection);
        exit(1);
    }

    MYSQL_ROW row;
    int num_fields = mysql_num_fields(result);

    while ((row = mysql_fetch_row(result)) != NULL) {
        for (int i = 0; i < num_fields; i++) {
            printf("%s\t", row[i]);
        }
        printf("\n");
    }

    mysql_free_result(result);
    mysql_close(connection);

    return 0;
}