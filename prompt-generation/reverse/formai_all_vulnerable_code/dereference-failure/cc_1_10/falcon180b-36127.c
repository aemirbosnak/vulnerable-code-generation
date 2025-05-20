//Falcon-180B DATASET v1.0 Category: Database querying ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define MAX_QUERY_LENGTH 1000
#define MAX_ROW_COUNT 100

typedef struct {
    char *query;
    int query_length;
    MYSQL_RES *result;
    MYSQL_ROW row;
    int row_count;
} QueryResult;

void die(MYSQL *conn) {
    fprintf(stderr, "Error: %s\n", mysql_error(conn));
    exit(1);
}

int main() {
    MYSQL *conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, "localhost", "username", "password", "database_name", 0, NULL, 0)) {
        die(conn);
    }

    QueryResult result;
    result.query = malloc(MAX_QUERY_LENGTH);
    result.query_length = 0;
    result.result = mysql_store_result(conn);
    result.row_count = 0;

    printf("Enter a SQL query:\n");
    fgets(result.query, MAX_QUERY_LENGTH, stdin);
    result.query_length = strlen(result.query);

    if (mysql_query(conn, result.query)) {
        die(conn);
    }

    result.row = mysql_fetch_row(result.result);
    while (result.row!= NULL) {
        for (int i = 0; i < mysql_num_fields(result.result); i++) {
            printf("%s ", result.row[i]? result.row[i] : "NULL");
        }
        printf("\n");
        result.row = mysql_fetch_row(result.result);
        result.row_count++;
        if (result.row_count >= MAX_ROW_COUNT) {
            break;
        }
    }

    mysql_free_result(result.result);
    mysql_close(conn);

    return 0;
}