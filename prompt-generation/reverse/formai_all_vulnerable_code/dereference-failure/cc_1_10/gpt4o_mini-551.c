//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define HOST "localhost"
#define USER "root"
#define PASSWORD "your_password"
#define DATABASE "test_db"

void finish_with_error(MYSQL *con) {
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    exit(1);
}

void execute_query(MYSQL *con, const char *query) {
    if (mysql_query(con, query)) {
        finish_with_error(con);
    }
}

void display_results(MYSQL_RES *result) {
    MYSQL_ROW row;
    unsigned long *lengths;
    
    while ((row = mysql_fetch_row(result))) {
        lengths = mysql_fetch_lengths(result);
        for (unsigned int i = 0; i < mysql_num_fields(result); i++) {
            if (lengths[i] > 0) {
                printf("%s ", row[i]);
            } else {
                printf("NULL ");
            }
        }
        printf("\n");
    }
}

void insert_employee(MYSQL *con, const char *name, int age) {
    char query[256];
    snprintf(query, sizeof(query), "INSERT INTO employees(name, age) VALUES('%s', %d)", name, age);
    execute_query(con, query);
    printf("Employee %s added to database.\n", name);
}

void fetch_all_employees(MYSQL *con) {
    execute_query(con, "SELECT * FROM employees");
    
    MYSQL_RES *result = mysql_store_result(con);
    if (result == NULL) {
        finish_with_error(con);
    }

    printf("Employee List:\n");
    display_results(result);
    mysql_free_result(result);
}

void delete_employee(MYSQL *con, int employee_id) {
    char query[256];
    snprintf(query, sizeof(query), "DELETE FROM employees WHERE id=%d", employee_id);
    execute_query(con, query);
    printf("Employee with ID %d deleted from database.\n", employee_id);
}

void create_employee_table(MYSQL *con) {
    const char *query = 
        "CREATE TABLE IF NOT EXISTS employees ("
        "id INT AUTO_INCREMENT PRIMARY KEY, "
        "name VARCHAR(100), "
        "age INT)";

    execute_query(con, query);
    printf("Employees table created successfully.\n");
}

int main() {
    MYSQL *con = mysql_init(NULL);
    if (con == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        return EXIT_FAILURE;
    }

    if (mysql_real_connect(con, HOST, USER, PASSWORD, DATABASE, 0, NULL, 0) == NULL) {
        finish_with_error(con);
    }

    create_employee_table(con);

    insert_employee(con, "John Doe", 30);
    insert_employee(con, "Jane Smith", 25);
    insert_employee(con, "Emily Johnson", 45);

    fetch_all_employees(con);

    delete_employee(con, 2); // delete employee with ID 2

    fetch_all_employees(con);

    mysql_close(con);
    return EXIT_SUCCESS;
}