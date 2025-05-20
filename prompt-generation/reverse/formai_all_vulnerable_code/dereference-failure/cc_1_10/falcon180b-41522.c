//Falcon-180B DATASET v1.0 Category: Database querying ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <mysql/mysql.h>

#define MAX_QUERY_LENGTH 1024

typedef struct {
    char *query;
    int query_length;
    MYSQL_RES *result;
    MYSQL_ROW row;
} QueryResult;

QueryResult *query_database(MYSQL *conn, const char *query_string) {
    QueryResult *result = malloc(sizeof(QueryResult));
    result->query = strdup(query_string);
    result->query_length = strlen(result->query);

    if (mysql_query(conn, result->query)) {
        fprintf(stderr, "Error executing query: %s\n", mysql_error(conn));
        exit(1);
    }

    result->result = mysql_store_result(conn);
    if (!result->result) {
        fprintf(stderr, "Error storing result\n");
        exit(1);
    }

    return result;
}

void print_query_result(QueryResult *result) {
    int num_fields = mysql_num_fields(result->result);
    MYSQL_FIELD *fields = mysql_fetch_fields(result->result);

    printf("+----+------------------------------+\n");
    for (int i = 0; i < num_fields; i++) {
        printf("| %s |", fields[i].name);
    }
    printf("|\n");
    printf("+----+------------------------------+\n");

    while ((result->row = mysql_fetch_row(result->result))) {
        for (int i = 0; i < num_fields; i++) {
            printf("| %s |", result->row[i]? result->row[i] : "NULL");
        }
        printf("|\n");
    }
    printf("+----+------------------------------+\n");
}

int main() {
    MYSQL *conn = mysql_init(NULL);

    if (!mysql_real_connect(conn, "localhost", "username", "password", "database_name", 0, NULL, 0)) {
        fprintf(stderr, "Error connecting to database: %s\n", mysql_error(conn));
        exit(1);
    }

    QueryResult *result = query_database(conn, "SELECT * FROM my_table");
    print_query_result(result);

    mysql_free_result(result->result);
    mysql_close(conn);

    return 0;
}