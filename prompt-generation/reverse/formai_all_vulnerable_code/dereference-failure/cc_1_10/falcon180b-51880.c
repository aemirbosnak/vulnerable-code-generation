//Falcon-180B DATASET v1.0 Category: Database querying ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

// Function to connect to the database
MYSQL *connect_to_database(char *host, char *user, char *password, char *database) {
    MYSQL *conn = NULL;
    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, host, user, password, database, 0, NULL, 0)) {
        printf("Error connecting to database: %s\n", mysql_error(conn));
        exit(1);
    }
    return conn;
}

// Function to execute a query and return the result
MYSQL_RES *execute_query(MYSQL *conn, char *query) {
    MYSQL_RES *result = NULL;
    if (mysql_query(conn, query)) {
        printf("Error executing query: %s\n", mysql_error(conn));
        exit(1);
    }
    result = mysql_store_result(conn);
    return result;
}

// Function to print the result of a query
void print_result(MYSQL_RES *result) {
    MYSQL_ROW row;
    int num_fields = mysql_num_fields(result);
    while ((row = mysql_fetch_row(result))!= NULL) {
        for (int i = 0; i < num_fields; i++) {
            printf("%s ", row[i]? row[i] : "NULL");
        }
        printf("\n");
    }
}

int main() {
    MYSQL *conn = connect_to_database("localhost", "username", "password", "database");
    char query[1000];

    // Example 1: Select all records from a table
    sprintf(query, "SELECT * FROM table_name");
    MYSQL_RES *result = execute_query(conn, query);
    print_result(result);
    mysql_free_result(result);

    // Example 2: Select records based on a condition
    sprintf(query, "SELECT * FROM table_name WHERE field_name = 'value'");
    result = execute_query(conn, query);
    print_result(result);
    mysql_free_result(result);

    // Example 3: Update a record
    sprintf(query, "UPDATE table_name SET field_name = 'new_value' WHERE id = 1");
    if (mysql_query(conn, query)) {
        printf("Error updating record: %s\n", mysql_error(conn));
        exit(1);
    }

    // Example 4: Delete a record
    sprintf(query, "DELETE FROM table_name WHERE id = 1");
    if (mysql_query(conn, query)) {
        printf("Error deleting record: %s\n", mysql_error(conn));
        exit(1);
    }

    mysql_close(conn);
    return 0;
}