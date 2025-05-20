//Falcon-180B DATASET v1.0 Category: Database querying ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <mysql/mysql.h>

#define MAX_QUERY_LENGTH 1024

typedef struct {
    char *query;
    char *result;
} QueryResult;

void execute_query(MYSQL *conn, const char *query, QueryResult *result) {
    if (mysql_query(conn, query)) {
        fprintf(stderr, "Error executing query: %s\n", mysql_error(conn));
        exit(1);
    }

    MYSQL_RES *res = mysql_store_result(conn);
    MYSQL_ROW row;

    if ((row = mysql_fetch_row(res))) {
        result->result = strdup(row[0]);
    } else {
        result->result = strdup("");
    }

    mysql_free_result(res);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        fprintf(stderr, "Usage: %s host user password\n", argv[0]);
        return 1;
    }

    char *host = argv[1];
    char *user = argv[2];
    char *password = argv[3];

    MYSQL *conn = mysql_init(NULL);

    if (!mysql_real_connect(conn, host, user, password, NULL, 0, NULL, 0)) {
        fprintf(stderr, "Error connecting to database: %s\n", mysql_error(conn));
        return 1;
    }

    QueryResult result;

    char query[MAX_QUERY_LENGTH] = "SELECT name FROM users WHERE id = 1";
    execute_query(conn, query, &result);

    printf("The name of the user with ID 1 is: %s\n", result.result);

    mysql_close(conn);

    return 0;
}