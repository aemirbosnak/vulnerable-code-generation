//Falcon-180B DATASET v1.0 Category: Database querying ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

// Function to connect to the MySQL database
MYSQL *connect_database() {
    MYSQL *conn = NULL;
    if ((conn = mysql_init(NULL)) == NULL) {
        fprintf(stderr, "Error initializing MySQL connection\n");
        exit(1);
    }
    if (!mysql_real_connect(conn, "localhost", "username", "password", "database_name", 0, NULL, 0)) {
        fprintf(stderr, "Error connecting to MySQL database: %s\n", mysql_error(conn));
        exit(1);
    }
    return conn;
}

// Function to execute a query and return the result set
MYSQL_RES *execute_query(MYSQL *conn, const char *query) {
    MYSQL_RES *result = NULL;
    if (mysql_query(conn, query)) {
        fprintf(stderr, "Error executing query: %s\n", mysql_error(conn));
        exit(1);
    }
    result = mysql_store_result(conn);
    return result;
}

// Function to print a result set
void print_result_set(MYSQL_RES *result) {
    MYSQL_ROW row;
    int num_fields = mysql_num_fields(result);
    while ((row = mysql_fetch_row(result))!= NULL) {
        for (int i = 0; i < num_fields; i++) {
            printf("%s ", row[i]? row[i] : "NULL");
        }
        printf("\n");
    }
}

// Function to close the database connection
void close_database(MYSQL *conn) {
    if (conn!= NULL) {
        mysql_close(conn);
    }
}

int main() {
    MYSQL *conn = connect_database();
    if (conn == NULL) {
        return 1;
    }

    // Example query to select all records from a table
    const char *query = "SELECT * FROM my_table";
    MYSQL_RES *result = execute_query(conn, query);
    if (result!= NULL) {
        print_result_set(result);
        mysql_free_result(result);
    }

    close_database(conn);
    return 0;
}