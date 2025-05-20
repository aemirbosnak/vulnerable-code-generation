//FormAI DATASET v1.0 Category: Database querying ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define DB_HOST "localhost"
#define DB_USER "root"
#define DB_PASS "password"
#define DB_NAME "employees"

int main(int argc, char **argv) {
    MYSQL *conn;
    MYSQL_RES *result;
    MYSQL_ROW row;
    char query[200];
    char first_name[50];
    char last_name[50];
    int id;

    // Connect to database
    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 0, NULL, 0)) {
        fprintf(stderr, "Error: %s\n", mysql_error(conn));
        exit(1);
    }

    // Prompt user for input
    printf("Enter employee id: ");
    scanf("%d", &id);

    // Generate SQL query
    sprintf(query, "SELECT first_name, last_name FROM employees WHERE emp_no = %d", id);

    // Execute query
    if (mysql_query(conn, query)) {
        fprintf(stderr, "Error: %s\n", mysql_error(conn));
        exit(1);
    }

    // Fetch results
    result = mysql_use_result(conn);
    if (result == NULL) {
        fprintf(stderr, "Error: %s\n", mysql_error(conn));
        exit(1);
    }

    // Display results
    if ((row = mysql_fetch_row(result)) != NULL) {
        strncpy(first_name, row[0], sizeof(first_name));
        strncpy(last_name, row[1], sizeof(last_name));
        printf("Name: %s %s\n", first_name, last_name);
    } else {
        printf("Employee not found.\n");
    }

    // Cleanup
    mysql_free_result(result);
    mysql_close(conn);

    return 0;
}