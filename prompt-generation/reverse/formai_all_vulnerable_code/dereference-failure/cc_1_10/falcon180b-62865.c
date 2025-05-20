//Falcon-180B DATASET v1.0 Category: Database querying ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

// Function to connect to MySQL server
MYSQL *connect_to_server(char *host, char *user, char *pass, char *db) {
    MYSQL *conn = NULL;
    conn = mysql_init(NULL);

    if (!mysql_real_connect(conn, host, user, pass, db, 0, NULL, 0)) {
        fprintf(stderr, "Failed to connect to MySQL: %s\n", mysql_error(conn));
        exit(1);
    }

    return conn;
}

// Function to execute a query and return the result
MYSQL_RES *execute_query(MYSQL *conn, char *query) {
    MYSQL_RES *result = NULL;
    if (mysql_query(conn, query)) {
        fprintf(stderr, "Failed to execute query: %s\n", mysql_error(conn));
        exit(1);
    }

    result = mysql_store_result(conn);

    if (!result) {
        fprintf(stderr, "No result set returned.\n");
        exit(1);
    }

    return result;
}

// Function to display the query results
void display_results(MYSQL_RES *result) {
    MYSQL_ROW row;
    int num_fields = mysql_num_fields(result);

    while ((row = mysql_fetch_row(result))) {
        for (int i = 0; i < num_fields; i++) {
            printf("%s ", row[i]? row[i] : "NULL");
        }
        printf("\n");
    }
}

// Function to close the MySQL connection
void close_connection(MYSQL *conn) {
    mysql_close(conn);
}

int main() {
    char *host = "localhost";
    char *user = "root";
    char *pass = "password";
    char *db = "test";

    MYSQL *conn = connect_to_server(host, user, pass, db);

    char *query = "SELECT * FROM employees";
    MYSQL_RES *result = execute_query(conn, query);

    display_results(result);

    close_connection(conn);

    return 0;
}