//Falcon-180B DATASET v1.0 Category: Database querying ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <mysql/mysql.h>

// Function to connect to the database
MYSQL *connect_to_database() {
    MYSQL *conn = NULL;
    char *server = "localhost";
    char *user = "root";
    char *password = "password";
    char *database = "romantic_queries";

    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
        fprintf(stderr, "Error connecting to database: %s\n", mysql_error(conn));
        exit(1);
    }

    return conn;
}

// Function to execute a query and return the result set
MYSQL_RES *execute_query(MYSQL *conn, char *query) {
    MYSQL_RES *result = NULL;
    if (mysql_query(conn, query)) {
        fprintf(stderr, "Error executing query: %s\n", mysql_error(conn));
        exit(1);
    }
    result = mysql_store_result(conn);
    return result;
}

// Function to print the results of a query
void print_results(MYSQL_RES *result) {
    MYSQL_ROW row;
    int num_fields = mysql_num_fields(result);
    int num_rows = mysql_num_rows(result);

    printf("Results:\n");
    while ((row = mysql_fetch_row(result))) {
        for (int i = 0; i < num_fields; i++) {
            printf("%s ", row[i]? row[i] : "NULL");
        }
        printf("\n");
    }
    printf("Number of rows: %d\n", num_rows);
}

// Function to close the database connection
void close_database(MYSQL *conn) {
    mysql_close(conn);
}

int main() {
    MYSQL *conn = connect_to_database();

    // Example queries
    char *query1 = "SELECT * FROM love_poems";
    char *query2 = "SELECT * FROM romantic_dates WHERE location = 'beach'";
    char *query3 = "SELECT * FROM love_letters WHERE author = 'Shakespeare'";

    MYSQL_RES *result1 = execute_query(conn, query1);
    print_results(result1);

    MYSQL_RES *result2 = execute_query(conn, query2);
    print_results(result2);

    MYSQL_RES *result3 = execute_query(conn, query3);
    print_results(result3);

    close_database(conn);
    return 0;
}