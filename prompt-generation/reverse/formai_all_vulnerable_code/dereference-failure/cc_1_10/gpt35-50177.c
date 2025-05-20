//FormAI DATASET v1.0 Category: Database querying ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define DB_HOST "localhost"
#define DB_USER "root"
#define DB_PASS "password"
#define DB_NAME "cars"

int main(void) {
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
    char query[1000];

    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 0, NULL, 0)) {
        fprintf(stderr, "Could not connect to database: %s\n", mysql_error(conn));
        exit(1);
    }

    printf("Welcome to Cars Database Querying System!\n\n");

    while (1) {
        printf("Enter command: ");
        fgets(query, sizeof(query), stdin);
        query[strcspn(query, "\n")] = '\0';

        if (strcmp(query, "quit") == 0)
            break;

        if (mysql_query(conn, query)) {
            fprintf(stderr, "Query failed: %s\n", mysql_error(conn));
            continue;
        }

        res = mysql_use_result(conn);
        while ((row = mysql_fetch_row(res)) != NULL) {
            for (int i = 0; i < mysql_num_fields(res); i++) {
                printf("%s\t", row[i] ? row[i] : "NULL");
            }
            printf("\n");
        }
        printf("\n");

        mysql_free_result(res);
    }

    mysql_close(conn);
    return 0;
}