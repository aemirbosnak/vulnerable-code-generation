//Falcon-180B DATASET v1.0 Category: Database querying ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

// Function to connect to the database
MYSQL *connect_to_db() {
    MYSQL *conn = NULL;
    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, "localhost", "username", "password", "database_name", 0, NULL, 0)) {
        printf("Error connecting to database: %s\n", mysql_error(conn));
        exit(1);
    }
    return conn;
}

// Function to execute a query and print the results
void execute_query(MYSQL *conn, char *query) {
    if (mysql_query(conn, query)) {
        printf("Error executing query: %s\n", mysql_error(conn));
        exit(1);
    }
    MYSQL_RES *res = mysql_store_result(conn);
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(res))!= NULL) {
        for (int i = 0; i < mysql_num_fields(res); i++) {
            printf("%s ", row[i]? row[i] : "NULL");
        }
        printf("\n");
    }
    mysql_free_result(res);
}

// Function to close the database connection
void close_connection(MYSQL *conn) {
    mysql_close(conn);
}

int main() {
    MYSQL *conn = connect_to_db();

    // Example queries
    char *query1 = "SELECT * FROM users WHERE age > 18";
    execute_query(conn, query1);

    char *query2 = "INSERT INTO users (name, age) VALUES ('John', 25)";
    if (mysql_query(conn, query2)) {
        printf("Error inserting data: %s\n", mysql_error(conn));
        exit(1);
    }

    char *query3 = "UPDATE users SET age = 26 WHERE name = 'John'";
    if (mysql_query(conn, query3)) {
        printf("Error updating data: %s\n", mysql_error(conn));
        exit(1);
    }

    char *query4 = "DELETE FROM users WHERE name = 'John'";
    if (mysql_query(conn, query4)) {
        printf("Error deleting data: %s\n", mysql_error(conn));
        exit(1);
    }

    close_connection(conn);
    return 0;
}