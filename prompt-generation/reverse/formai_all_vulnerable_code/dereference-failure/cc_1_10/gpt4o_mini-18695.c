//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define HOST "localhost"
#define USER "root"
#define PASSWORD "your_password"
#define DATABASE "your_database"

void display_results(MYSQL_RES *result) {
    MYSQL_ROW row;
    unsigned int num_fields = mysql_num_fields(result);
    MYSQL_FIELD *fields = mysql_fetch_fields(result);

    // Print the column names
    for(unsigned int i = 0; i < num_fields; i++) {
        printf("%s\t", fields[i].name);
    }
    printf("\n");

    // Print the rows
    while ((row = mysql_fetch_row(result))) {
        for(unsigned int i = 0; i < num_fields; i++) {
            printf("%s\t", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }
}

void execute_query(MYSQL *conn, const char *query) {
    if (mysql_query(conn, query)) {
        fprintf(stderr, "Query failed: %s\n", mysql_error(conn));
        return;
    }
    MYSQL_RES *result = mysql_store_result(conn);
    if (result) {
        display_results(result);
        mysql_free_result(result);
    } else {
        if (mysql_field_count(conn) == 0) {
            printf("%lu rows affected\n", (unsigned long) mysql_affected_rows(conn));
        } else {
            fprintf(stderr, "Error retrieving results: %s\n", mysql_error(conn));
        }
    }
}

int main() {
    MYSQL *conn = mysql_init(NULL);
    if (!conn) {
        fprintf(stderr, "mysql_init() failed\n");
        return EXIT_FAILURE;
    }

    if (mysql_real_connect(conn, HOST, USER, PASSWORD, DATABASE, 0, NULL, 0) == NULL) {
        fprintf(stderr, "mysql_real_connect() failed: %s\n", mysql_error(conn));
        mysql_close(conn);
        return EXIT_FAILURE;
    }
    
    const char *create_table_query = 
        "CREATE TABLE IF NOT EXISTS employees ("
        "id INT AUTO_INCREMENT PRIMARY KEY, "
        "first_name VARCHAR(100), "
        "last_name VARCHAR(100), "
        "email VARCHAR(100), "
        "department VARCHAR(100));";

    execute_query(conn, create_table_query);

    const char *insert_query = 
        "INSERT INTO employees (first_name, last_name, email, department) VALUES "
        "('Alice', 'Johnson', 'alice.johnson@example.com', 'Engineering'), "
        "('Bob', 'Smith', 'bob.smith@example.com', 'Marketing'), "
        "('Charlie', 'Brown', 'charlie.brown@example.com', 'HR');";

    execute_query(conn, insert_query);

    const char *select_query = "SELECT * FROM employees;";
    execute_query(conn, select_query);

    const char *update_query = 
        "UPDATE employees SET department = 'Sales' WHERE first_name = 'Alice';";
    execute_query(conn, update_query);

    select_query = "SELECT * FROM employees;";
    execute_query(conn, select_query);

    const char *delete_query = "DELETE FROM employees WHERE first_name = 'Charlie';";
    execute_query(conn, delete_query);

    select_query = "SELECT * FROM employees;";
    execute_query(conn, select_query);

    mysql_close(conn);
    return EXIT_SUCCESS;
}