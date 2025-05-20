//FormAI DATASET v1.0 Category: Database querying ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

int main(int argc, char **argv){
    printf("Let's query the employee database!\n");

    // Initialize connection
    MYSQL *conn = mysql_init(NULL);

    // Connect to database
    if (!mysql_real_connect(conn, "localhost", "username", "password", "employees", 0, NULL, 0)) {
        printf("Failed to connect to database!\nError: %s", mysql_error(conn));
        return 1;
    }

    // Query employees with salary greater than 50000
    printf("Employees with salary greater than 50000:\n");
    if (mysql_query(conn, "SELECT first_name, last_name, salary FROM employees WHERE salary > 50000")) {
        printf("Failed to query the database!\nError: %s", mysql_error(conn));
        return 1;
    }

    // Store query result
    MYSQL_RES *result = mysql_store_result(conn);

    // Get number of fields in the result
    int num_fields = mysql_num_fields(result);

    // Get field names
    MYSQL_FIELD *fields = mysql_fetch_fields(result);

    // Print field names
    for (int i=0; i<num_fields; i++) {
        printf("%s\t", fields[i].name);
    }
    printf("\n");

    // Print query result
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(result))) {
        for (int i=0; i<num_fields; i++) {
            printf("%s\t", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }

    // Free memory
    mysql_free_result(result);
    mysql_close(conn);

    printf("Query complete!\n");
    return 0;
}