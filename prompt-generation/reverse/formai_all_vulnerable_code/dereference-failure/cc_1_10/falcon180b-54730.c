//Falcon-180B DATASET v1.0 Category: Database querying ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <mysql/mysql.h>

#define MAX_QUERY_LENGTH 1024
#define MAX_FIELD_LENGTH 1024

struct query_result {
    MYSQL_RES *result;
    MYSQL_ROW row;
    int num_fields;
    int num_rows;
};

int main() {
    MYSQL *conn;
    struct query_result result;

    // Connect to the MySQL database
    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, "localhost", "username", "password", "database_name", 0, NULL, 0)) {
        fprintf(stderr, "Error: Unable to connect to MySQL: %s\n", mysql_error(conn));
        exit(1);
    }

    // Execute a query and retrieve the results
    char query[MAX_QUERY_LENGTH] = "SELECT * FROM table_name";
    if (mysql_query(conn, query)) {
        fprintf(stderr, "Error: Unable to execute query: %s\n", mysql_error(conn));
        exit(1);
    }

    result.result = mysql_store_result(conn);
    result.num_fields = mysql_num_fields(result.result);
    result.num_rows = mysql_num_rows(result.result);

    // Print the results
    for (int i = 0; i < result.num_fields; i++) {
        printf("Column %d: %s\n", i, mysql_fetch_field(result.result)->name);
    }

    while ((result.row = mysql_fetch_row(result.result))) {
        for (int i = 0; i < result.num_fields; i++) {
            printf("%s ", result.row[i]? result.row[i] : "NULL");
        }
        printf("\n");
    }

    // Close the connection and free the resources
    mysql_free_result(result.result);
    mysql_close(conn);

    return 0;
}