//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

void finish_with_error(MYSQL *conn) {
    fprintf(stderr, "%s\n", mysql_error(conn));
    mysql_close(conn);
    exit(EXIT_FAILURE);
}

void print_query_result(MYSQL_RES *result) {
    MYSQL_ROW row;
    unsigned int num_fields = mysql_num_fields(result);
    
    // Print column names
    MYSQL_FIELD *fields = mysql_fetch_fields(result);
    for (unsigned int i = 0; i < num_fields; i++) {
        printf("%-20s", fields[i].name);
    }
    printf("\n");

    // Print rows
    while ((row = mysql_fetch_row(result))) {
        for (unsigned int i = 0; i < num_fields; i++) {
            printf("%-20s", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }
}

void query_database(MYSQL *conn, const char *query) {
    if (mysql_query(conn, query)) {
        finish_with_error(conn);
    }

    MYSQL_RES *result = mysql_store_result(conn);
    if (result == NULL) {
        finish_with_error(conn);
    }

    print_query_result(result);
    mysql_free_result(result);
}

void insert_employee(MYSQL *conn, const char *name, const char *position, double salary) {
    char query[256];
    snprintf(query, sizeof(query), 
             "INSERT INTO employees (name, position, salary) VALUES ('%s', '%s', %.2f)", 
             name, position, salary);
    query_database(conn, query);
}

void display_all_employees(MYSQL *conn) {
    query_database(conn, "SELECT * FROM employees");
}

void filter_employees_by_salary(MYSQL *conn, double min_salary) {
    char query[256];
    snprintf(query, sizeof(query), 
             "SELECT * FROM employees WHERE salary >= %.2f", min_salary);
    query_database(conn, query);
}

void update_employee_position(MYSQL *conn, int employee_id, const char *new_position) {
    char query[256];
    snprintf(query, sizeof(query), 
             "UPDATE employees SET position='%s' WHERE id=%d", new_position, employee_id);
    query_database(conn, query);
}

void delete_employee(MYSQL *conn, int employee_id) {
    char query[256];
    snprintf(query, sizeof(query), "DELETE FROM employees WHERE id=%d", employee_id);
    query_database(conn, query);
}

int main() {
    MYSQL *conn = mysql_init(NULL);
    
    if (conn == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        return EXIT_FAILURE;
    }

    if (mysql_real_connect(conn, "localhost", "root", "password",
                           "test_db", 0, NULL, 0) == NULL) {
        finish_with_error(conn);
    }

    // Create employees table if it does not exist
    const char *create_table_query = "CREATE TABLE IF NOT EXISTS employees ("
                                      "id INT AUTO_INCREMENT PRIMARY KEY, "
                                      "name VARCHAR(255), "
                                      "position VARCHAR(100), "
                                      "salary DOUBLE)";
    query_database(conn, create_table_query);

    // Insert sample employees
    insert_employee(conn, "Alice", "Developer", 75000);
    insert_employee(conn, "Bob", "Manager", 85000);
    insert_employee(conn, "Charlie", "Intern", 30000);

    // Display all employees
    printf("All Employees:\n");
    display_all_employees(conn);
    
    // Filter employees by salary
    printf("\nEmployees with salary greater or equal to 50000:\n");
    filter_employees_by_salary(conn, 50000);
    
    // Update employee position
    printf("\nUpdating Charlie's position to Junior Developer...\n");
    update_employee_position(conn, 3, "Junior Developer");
    
    // Display employees after update
    printf("\nAll Employees after update:\n");
    display_all_employees(conn);
    
    // Delete an employee
    printf("\nDeleting Alice...\n");
    delete_employee(conn, 1);
    
    // Display all employees after deletion
    printf("\nAll Employees after deletion:\n");
    display_all_employees(conn);

    // Cleanup
    mysql_close(conn);
    return EXIT_SUCCESS;
}