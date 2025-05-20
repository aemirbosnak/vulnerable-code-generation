//FormAI DATASET v1.0 Category: Database querying ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define USERNAME "username"
#define PASSWORD "password"
#define DATABASE "database_name"

int main() {

    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
    const char *server = "localhost";
    const char *user = USERNAME;
    const char *password = PASSWORD;
    const char *database = DATABASE;
    char query[100];

    conn = mysql_init(NULL);

    if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
        printf("%s\n", mysql_error(conn));
        exit(1);
    }

    printf("Welcome to our database system.\n");

    while (1) {

        printf("Enter your query (type q to quit): ");
        scanf("%99[^\n]", query);
        getchar();

        if (!strcmp(query, "q")) {
            break;
        }

        if (mysql_query(conn, query)) {
            printf("%s\n", mysql_error(conn));
            continue;
        }

        res = mysql_use_result(conn);

        while ((row = mysql_fetch_row(res)) != NULL) {
            for (unsigned int i = 0; i < mysql_num_fields(res); i++) {
                printf("%s", row[i] ? row[i] : "NULL");
                if (i < mysql_num_fields(res) - 1) {
                    printf(", ");
                }
            }
            printf("\n");
        }

        mysql_free_result(res);
    }

    mysql_close(conn);

    return 0;
}