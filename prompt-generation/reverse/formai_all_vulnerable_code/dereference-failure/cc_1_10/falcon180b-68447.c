//Falcon-180B DATASET v1.0 Category: Database querying ; Style: excited
// This is an excited C program that demonstrates how to query a database
// We will be using the MySQL database and the MySQL Connector/C library to connect to it

#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

// Function to handle errors from the MySQL library
void handle_error(MYSQL *conn) {
    fprintf(stderr, "Error: %s\n", mysql_error(conn));
    exit(1);
}

// Function to execute a query and print the results
void execute_query(MYSQL *conn, const char *query) {
    if (mysql_query(conn, query)) {
        handle_error(conn);
    }

    MYSQL_RES *result = mysql_store_result(conn);
    MYSQL_ROW row;

    printf("Query results:\n");
    while ((row = mysql_fetch_row(result))) {
        for (int i = 0; i < mysql_num_fields(result); i++) {
            printf("%s ", row[i]? row[i] : "NULL");
        }
        printf("\n");
    }

    mysql_free_result(result);
}

int main() {
    // Connect to the MySQL database
    MYSQL *conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, "localhost", "username", "password", "database_name", 0, NULL, 0)) {
        handle_error(conn);
    }

    // Execute a query to retrieve all records from a table
    const char *query = "SELECT * FROM my_table";
    execute_query(conn, query);

    // Execute a query to update a record in a table
    const char *update_query = "UPDATE my_table SET my_column = 'new_value' WHERE id = 1";
    if (mysql_query(conn, update_query)) {
        handle_error(conn);
    }

    printf("Update successful!\n");

    // Execute a query to insert a new record into a table
    const char *insert_query = "INSERT INTO my_table (my_column) VALUES ('new_value')";
    if (mysql_query(conn, insert_query)) {
        handle_error(conn);
    }

    printf("Insert successful!\n");

    // Execute a query to delete a record from a table
    const char *delete_query = "DELETE FROM my_table WHERE id = 1";
    if (mysql_query(conn, delete_query)) {
        handle_error(conn);
    }

    printf("Delete successful!\n");

    // Close the database connection
    mysql_close(conn);

    return 0;
}