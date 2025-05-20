//Falcon-180B DATASET v1.0 Category: Database querying ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

// Function to establish database connection
MYSQL *connect_db() {
    MYSQL *conn = NULL;
    conn = mysql_init(NULL);

    if (!mysql_real_connect(conn, "localhost", "username", "password", "database_name", 0, NULL, 0)) {
        fprintf(stderr, "Error connecting to database: %s\n", mysql_error(conn));
        exit(1);
    }

    return conn;
}

// Function to execute SQL query and return result set
MYSQL_RES *execute_query(MYSQL *conn, const char *query) {
    MYSQL_RES *result = NULL;
    if (mysql_query(conn, query)) {
        fprintf(stderr, "Error executing query: %s\n", mysql_error(conn));
        exit(1);
    }

    result = mysql_store_result(conn);

    if (!result) {
        fprintf(stderr, "No result set returned\n");
        exit(1);
    }

    return result;
}

// Function to print result set
void print_result_set(MYSQL_RES *result) {
    MYSQL_ROW row;
    int num_fields = mysql_num_fields(result);
    int i;

    while ((row = mysql_fetch_row(result))) {
        for (i = 0; i < num_fields; i++) {
            printf("%s ", row[i]? row[i] : "NULL");
        }
        printf("\n");
    }
}

int main() {
    MYSQL *conn = connect_db();
    MYSQL_RES *result = execute_query(conn, "SELECT * FROM employees");
    print_result_set(result);

    mysql_close(conn);
    return 0;
}