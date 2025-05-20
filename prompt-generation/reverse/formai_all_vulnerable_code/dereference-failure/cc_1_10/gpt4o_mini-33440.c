//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define SERVER "localhost"
#define USER "your_username"
#define PASSWORD "your_password"
#define DATABASE "test_db"

void finish_with_error(MYSQL *con) {
    fprintf(stderr, "Error: %s\n", mysql_error(con));
    mysql_close(con);
    exit(1);
}

void execute_query(MYSQL *con, const char *query) {
    if (mysql_query(con, query)) {
        finish_with_error(con);
    }
}

void print_results(MYSQL *con) {
    MYSQL_RES *result = mysql_store_result(con);
    if (result == NULL) {
        finish_with_error(con);
    }
  
    int num_fields = mysql_num_fields(result);
    MYSQL_ROW row;

    while ((row = mysql_fetch_row(result))) {
        for (int i = 0; i < num_fields; i++) {
            printf("%s ", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }
  
    mysql_free_result(result);
}

void insert_employee(MYSQL *con, const char *name, const char *position, int salary) {
    char query[256];
    snprintf(query, sizeof(query), "INSERT INTO Employees(Name, Position, Salary) VALUES('%s', '%s', %d)", name, position, salary);
    execute_query(con, query);
    printf("Inserted Employee: %s, %s, %d\n", name, position, salary);
}

void display_employees(MYSQL *con) {
    execute_query(con, "SELECT * FROM Employees");
    printf("Employees:\n");
    print_results(con);
}

void update_employee_salary(MYSQL *con, int id, int new_salary) {
    char query[256];
    snprintf(query, sizeof(query), "UPDATE Employees SET Salary = %d WHERE ID = %d", new_salary, id);
    execute_query(con, query);
    printf("Updated Employee ID %d to new Salary: %d\n", id, new_salary);
}

void delete_employee(MYSQL *con, int id) {
    char query[256];
    snprintf(query, sizeof(query), "DELETE FROM Employees WHERE ID = %d", id);
    execute_query(con, query);
    printf("Deleted Employee ID: %d\n", id);
}

int main() {
    MYSQL *con = mysql_init(NULL);
    if (con == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        return EXIT_FAILURE;
    }

    if (mysql_real_connect(con, SERVER, USER, PASSWORD, DATABASE, 0, NULL, 0) == NULL) {
        finish_with_error(con);
    }

    // Creating the Employees table if not exists
    execute_query(con, "CREATE TABLE IF NOT EXISTS Employees(ID INT AUTO_INCREMENT PRIMARY KEY, Name VARCHAR(100), Position VARCHAR(100), Salary INT)");

    // Insert sample employees
    insert_employee(con, "Alice Smith", "Software Engineer", 60000);
    insert_employee(con, "Bob Johnson", "Project Manager", 70000);
    insert_employee(con, "Charlie Brown", "Designer", 55000);

    // Display all employees
    display_employees(con);

    // Update an employee's salary
    update_employee_salary(con, 1, 65000); // Updating employee with ID 1

    // Display all employees again
    display_employees(con);

    // Delete an employee
    delete_employee(con, 2); // Deleting employee with ID 2

    // Final display of employees
    display_employees(con);

    mysql_close(con);
    return EXIT_SUCCESS;
}