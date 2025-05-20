//Falcon-180B DATASET v1.0 Category: Database querying ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <mysql/mysql.h>

#define MAX_QUERY_LENGTH 1024
#define MAX_ROW_COUNT 100

typedef struct {
    char *query;
    int row_count;
    MYSQL_RES *result;
    MYSQL_ROW row;
} QueryResult;

QueryResult *execute_query(MYSQL *conn, const char *query) {
    QueryResult *result = malloc(sizeof(QueryResult));
    result->query = strdup(query);
    result->row_count = 0;
    result->result = mysql_store_result(conn);
    result->row = mysql_fetch_row(result->result);
    return result;
}

void print_result_header(QueryResult *result) {
    int i, j;
    MYSQL_FIELD *field;

    printf("+");
    for (i = 0; i < mysql_num_fields(result->result); i++) {
        field = mysql_fetch_field(result->result);
        j = strlen(field->name);
        printf("-%*s", j, field->name);
    }
    printf("\n");
}

void print_result_row(QueryResult *result) {
    int i;
    MYSQL_ROW row = result->row;

    for (i = 0; i < mysql_num_fields(result->result); i++) {
        printf("%s", row[i]? row[i] : "NULL");
        if (i < mysql_num_fields(result->result) - 1) {
            printf("\t");
        }
    }
    printf("\n");

    result->row = mysql_fetch_row(result->result);
    result->row_count++;
}

int main() {
    MYSQL *conn;
    QueryResult *result;

    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, "localhost", "username", "password", "database_name", 0, NULL, 0)) {
        fprintf(stderr, "Error: Unable to connect to MySQL: %s\n", mysql_error(conn));
        return 1;
    }

    result = execute_query(conn, "SELECT * FROM users");
    print_result_header(result);
    while (result->row) {
        print_result_row(result);
    }
    mysql_free_result(result->result);
    mysql_close(conn);

    return 0;
}