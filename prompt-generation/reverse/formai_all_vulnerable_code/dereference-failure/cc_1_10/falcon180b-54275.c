//Falcon-180B DATASET v1.0 Category: Database querying ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define MAX_QUERY_LENGTH 1024
#define MAX_ROW_LENGTH 4096

typedef struct {
    char query[MAX_QUERY_LENGTH];
    MYSQL_RES *result;
    MYSQL_ROW row;
    int num_rows;
    int num_cols;
} QueryResult;

QueryResult *query_database(MYSQL *conn, const char *query) {
    QueryResult *result = malloc(sizeof(QueryResult));
    result->num_rows = 0;
    result->num_cols = 0;

    if (mysql_query(conn, query)) {
        fprintf(stderr, "Error querying database: %s\n", mysql_error(conn));
        exit(1);
    }

    result->result = mysql_store_result(conn);
    if (!result->result) {
        fprintf(stderr, "Error storing result: %s\n", mysql_error(conn));
        exit(1);
    }

    result->num_rows = mysql_num_rows(result->result);
    result->num_cols = mysql_num_fields(result->result);

    return result;
}

void print_query_result(QueryResult *result) {
    int i, j;

    printf("Query result:\n");
    for (i = 0; i < result->num_rows; i++) {
        printf("Row %d:\n", i + 1);
        for (j = 0; j < result->num_cols; j++) {
            printf("%s = %s\n", mysql_fetch_field(result->result)->name, mysql_fetch_row(result->result)? mysql_fetch_row(result->result)[j] : "NULL");
        }
        printf("\n");
    }
}

void free_query_result(QueryResult *result) {
    mysql_free_result(result->result);
    free(result);
}

int main() {
    MYSQL *conn;
    QueryResult *result;

    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, "localhost", "username", "password", "database_name", 0, NULL, 0)) {
        fprintf(stderr, "Error connecting to database: %s\n", mysql_error(conn));
        return 1;
    }

    result = query_database(conn, "SELECT * FROM my_table");
    print_query_result(result);

    free_query_result(result);
    mysql_close(conn);

    return 0;
}