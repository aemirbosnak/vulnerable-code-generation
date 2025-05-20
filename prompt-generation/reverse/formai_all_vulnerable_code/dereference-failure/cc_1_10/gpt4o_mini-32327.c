//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define HOST "localhost"
#define USER "root"
#define PASS "your_password"
#define DB "test_db"

void finish_with_error(MYSQL *con) {
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    exit(EXIT_FAILURE);
}

void print_results(MYSQL_RES *result) {
    MYSQL_ROW row;
    unsigned int num_fields = mysql_num_fields(result);
    MYSQL_FIELD *fields = mysql_fetch_fields(result);

    // Print header
    for (unsigned int i = 0; i < num_fields; i++) {
        printf("%s ", fields[i].name);
    }
    printf("\n");

    // Print rows
    while ((row = mysql_fetch_row(result))) {
        for (unsigned int i = 0; i < num_fields; i++) {
            printf("%s ", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }
}

void query_database(MYSQL *con) {
    if (mysql_query(con, "SELECT * FROM employees")) {
        finish_with_error(con);
    }

    MYSQL_RES *result = mysql_store_result(con);
    if (result == NULL) {
        finish_with_error(con);
    }

    print_results(result);

    mysql_free_result(result);
}

void insert_employee(MYSQL *con, const char *name, const char *role, int salary) {
    char query[256];
    snprintf(query, sizeof(query), "INSERT INTO employees(name, role, salary) VALUES('%s', '%s', %d)", 
             name, role, salary);

    if (mysql_query(con, query)) {
        finish_with_error(con);
    }
}

void delete_employee(MYSQL *con, int id) {
    char query[256];
    snprintf(query, sizeof(query), "DELETE FROM employees WHERE id=%d", id);

    if (mysql_query(con, query)) {
        finish_with_error(con);
    }
}

void update_employee_salary(MYSQL *con, int id, int new_salary) {
    char query[256];
    snprintf(query, sizeof(query), "UPDATE employees SET salary=%d WHERE id=%d", new_salary, id);

    if (mysql_query(con, query)) {
        finish_with_error(con);
    }
}

int main() {
    MYSQL *con = mysql_init(NULL);
    if (con == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        exit(EXIT_FAILURE);
    }

    if (mysql_real_connect(con, HOST, USER, PASS, DB, 0, NULL, 0) == NULL) {
        finish_with_error(con);
    }

    // Inserting sample employees
    insert_employee(con, "Alice", "Developer", 65000);
    insert_employee(con, "Bob", "Designer", 55000);
    insert_employee(con, "Charlie", "Manager", 75000);

    // Querying the database
    printf("Initial Employee List:\n");
    query_database(con);

    // Updating an employee's salary
    printf("\nUpdating Bob's salary:\n");
    update_employee_salary(con, 2, 60000);
    query_database(con);

    // Deleting an employee
    printf("\nDeleting Charlie:\n");
    delete_employee(con, 3);
    query_database(con);

    mysql_close(con);
    return EXIT_SUCCESS;
}