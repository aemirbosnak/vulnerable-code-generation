//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

void finish_with_error(MYSQL *conn) {
    fprintf(stderr, "Error: %s\n", mysql_error(conn));
    mysql_close(conn);
    exit(EXIT_FAILURE);
}

void print_query_results(MYSQL_RES *result) {
    MYSQL_ROW row;
    unsigned int num_fields = mysql_num_fields(result);
    
    while ((row = mysql_fetch_row(result))) {
        for (unsigned int i = 0; i < num_fields; i++) {
            printf("%s ", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }
}

int main() {
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    // Initialize MySQL library
    if (mysql_library_init(0, NULL, NULL)) {
        fprintf(stderr, "Could not initialize MySQL library.\n");
        return EXIT_FAILURE;
    }

    // Establish connection to database
    conn = mysql_init(NULL);
    if (conn == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        return EXIT_FAILURE;
    }

    // Connect to the database
    if (mysql_real_connect(conn, "localhost", "username", "password", 
                           "database_name", 0, NULL, 0) == NULL) {
        finish_with_error(conn);
    }

    // Execute a SQL query
    if (mysql_query(conn, "SELECT * FROM your_table_name")) {
        finish_with_error(conn);
    }

    // Store result
    res = mysql_store_result(conn);
    if (res == NULL) {
        finish_with_error(conn);
    }

    // Print results
    printf("Query Results:\n");
    print_query_results(res);

    // Free result set
    mysql_free_result(res);

    // Close database connection
    mysql_close(conn);
    
    // Clean up MySQL library
    mysql_library_end();

    printf("All operations completed successfully!\n");
    return EXIT_SUCCESS;
}