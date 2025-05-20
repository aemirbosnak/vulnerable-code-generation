//Falcon-180B DATASET v1.0 Category: Database querying ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

// Function to connect to the database
MYSQL *connect_to_database(char *host, char *user, char *password, char *database) {
    MYSQL *conn = NULL;
    conn = mysql_init(NULL);
    if (!conn) {
        printf("Error: Unable to allocate MySQL object\n");
        return NULL;
    }
    if (!mysql_real_connect(conn, host, user, password, database, 0, NULL, 0)) {
        printf("Error: Unable to connect to MySQL: %s\n", mysql_error(conn));
        mysql_close(conn);
        return NULL;
    }
    return conn;
}

// Function to execute a query and return the result set
MYSQL_RES *execute_query(MYSQL *conn, char *query) {
    MYSQL_RES *result = NULL;
    if (mysql_query(conn, query)) {
        printf("Error: Unable to execute query: %s\n", mysql_error(conn));
        return NULL;
    }
    result = mysql_store_result(conn);
    return result;
}

// Function to print the result set
void print_result_set(MYSQL_RES *result) {
    MYSQL_ROW row;
    int num_fields = mysql_num_fields(result);
    while ((row = mysql_fetch_row(result))) {
        for (int i = 0; i < num_fields; i++) {
            printf("%s ", row[i]? row[i] : "NULL");
        }
        printf("\n");
    }
}

// Function to close the connection
void close_connection(MYSQL *conn) {
    mysql_close(conn);
}

int main() {
    // Connect to the database
    MYSQL *conn = connect_to_database("localhost", "username", "password", "database_name");
    if (!conn) {
        return 1;
    }

    // Execute a query and print the result set
    char query[1000] = "SELECT * FROM table_name";
    MYSQL_RES *result = execute_query(conn, query);
    if (result) {
        print_result_set(result);
        mysql_free_result(result);
    }

    // Close the connection
    close_connection(conn);
    return 0;
}