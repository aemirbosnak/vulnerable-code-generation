//FormAI DATASET v1.0 Category: Database querying ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

int main(void) {

    MYSQL *conn; // Create a pointer to the MySQL instance
    MYSQL_RES *res; // Create a pointer to store the result
    MYSQL_ROW row; // Create a pointer to store each row of the result
    char *server = "127.0.0.1"; // Replace with your server IP address
    char *user = "root"; // Replace with your MySQL username
    char *password = "password"; // Replace with your MySQL password
    char *database = "mydatabase"; // Replace with your MySQL database name

    conn = mysql_init(NULL); // Initialize the MySQL instance

    // Connect to the MySQL instance
    if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        return 1;
    }

    // Query the database
    if (mysql_query(conn, "SELECT * FROM mytable")) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        return 1;
    }

    // Store the result of the query in res and check for errors
    if (!(res = mysql_store_result(conn))) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        return 1;
    }

    // Get the number of rows returned
    int num_rows = mysql_num_rows(res);

    // Print the result
    printf("Result of the query:\n");
    printf("--------------------\n");
    printf("| %-10s | %-10s |\n", "Column 1", "Column 2");
    printf("--------------------\n");
    while ((row = mysql_fetch_row(res))) {
        printf("| %-10s | %-10s |\n", row[0], row[1]);
    }
    printf("--------------------\n");
    printf("Total rows returned: %d\n", num_rows);

    // Free the memory used by res
    mysql_free_result(res);

    // Close the MySQL connection
    mysql_close(conn);

    return 0;
}