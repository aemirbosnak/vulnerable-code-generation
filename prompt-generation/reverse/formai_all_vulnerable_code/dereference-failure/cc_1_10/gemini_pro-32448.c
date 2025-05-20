//GEMINI-pro DATASET v1.0 Category: Database querying ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

int main() {
    // Declare the database connection variables
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    // Initialize the database connection
    conn = mysql_init(NULL);
    if (conn == NULL) {
        fprintf(stderr, "Failed to initialize the database connection!\n");
        return EXIT_FAILURE;
    }

    // Set the database connection parameters
    if (mysql_real_connect(conn, "localhost", "root", "password", "database", 0, NULL, 0) == NULL) {
        fprintf(stderr, "Failed to connect to the database!\n");
        mysql_close(conn);
        return EXIT_FAILURE;
    }

    // Prepare the SQL query
    char *query = "SELECT * FROM table_name";

    // Execute the SQL query
    if (mysql_query(conn, query) != 0) {
        fprintf(stderr, "Failed to execute the SQL query!\n");
        mysql_close(conn);
        return EXIT_FAILURE;
    }

    // Get the result of the query
    res = mysql_store_result(conn);
    if (res == NULL) {
        fprintf(stderr, "Failed to get the result of the query!\n");
        mysql_close(conn);
        return EXIT_FAILURE;
    }

    // Print the result of the query
    printf("The result of the query is:\n");
    while ((row = mysql_fetch_row(res)) != NULL) {
        for (int i = 0; i < mysql_num_fields(res); i++) {
            printf("%s ", row[i]);
        }
        printf("\n");
    }

    // Clean up the database connection
    mysql_free_result(res);
    mysql_close(conn);

    return EXIT_SUCCESS;
}