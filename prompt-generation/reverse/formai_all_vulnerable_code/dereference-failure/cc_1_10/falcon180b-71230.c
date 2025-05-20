//Falcon-180B DATASET v1.0 Category: Database querying ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define MAX_QUERY_LENGTH 1024
#define MAX_ROW_COUNT 1000

typedef struct {
    char *query;
    int query_length;
    MYSQL_RES *result;
    MYSQL_ROW row;
    int row_count;
} QueryResult;

int main() {
    MYSQL *conn = NULL;
    QueryResult result;

    conn = mysql_init(NULL);
    if (!conn) {
        fprintf(stderr, "Failed to initialize MySQL connection\n");
        exit(1);
    }

    if (!mysql_real_connect(conn, "localhost", "username", "password", "database_name", 0, NULL, 0)) {
        fprintf(stderr, "Failed to connect to MySQL: %s\n", mysql_error(conn));
        exit(1);
    }

    char query[MAX_QUERY_LENGTH];
    sprintf(query, "SELECT * FROM my_table LIMIT %d", MAX_ROW_COUNT);
    result.query = query;
    result.query_length = strlen(query);

    if (mysql_query(conn, query)) {
        fprintf(stderr, "Failed to execute query: %s\n", mysql_error(conn));
        exit(1);
    }

    result.result = mysql_store_result(conn);
    result.row_count = 0;

    while ((result.row = mysql_fetch_row(result.result))) {
        result.row_count++;

        for (int i = 0; i < mysql_num_fields(result.result); i++) {
            printf("%s = %s\n", mysql_fetch_field(result.result)->name, result.row[i]? result.row[i] : "NULL");
        }
        printf("\n");
    }

    mysql_free_result(result.result);
    mysql_close(conn);

    return 0;
}