//FormAI DATASET v1.0 Category: Database querying ; Style: bold
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

MYSQL *conn;

#define SERVER "localhost"
#define USER "root"
#define PASSWORD "mypassword"
#define DATABASE "mydatabase"

int main(int argc, char *argv[]) {

    conn = mysql_init(NULL);

    if (!mysql_real_connect(conn, SERVER, USER, PASSWORD, DATABASE, 0, NULL, 0)) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    char query[200];

    printf("Enter query: ");
    fgets(query, 200, stdin);

    if (mysql_query(conn, query)) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    MYSQL_RES *result = mysql_store_result(conn);
    int num_fields = mysql_num_fields(result);

    MYSQL_ROW row;
    MYSQL_FIELD *field;

    while ((row = mysql_fetch_row(result))) {
        for (int i = 0; i < num_fields; i++) {
            if (i == 0) {
                while (field = mysql_fetch_field(result)) {
                    printf("%s ", field->name);
                }
                printf("\n");
            }
            printf("%s ", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }

    mysql_free_result(result);
    mysql_close(conn);

    return 0;
}