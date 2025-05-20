//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define HOST "localhost"
#define USER "root"
#define PASSWORD "password"  // Replace with your MySQL root password
#define DATABASE "testdb"    // Replace with your database name

void finish_with_error(MYSQL *conn) {
    fprintf(stderr, "ERROR: %s\n", mysql_error(conn));
    mysql_close(conn);
    exit(1);
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

void create_table(MYSQL *conn) {
    if (mysql_query(conn, "CREATE TABLE IF NOT EXISTS employees(id INT PRIMARY KEY AUTO_INCREMENT, name VARCHAR(100), age INT, department VARCHAR(100))")) {
        finish_with_error(conn);
    }
    printf("Table created successfully.\n");
}

void insert_employee(MYSQL *conn, const char *name, int age, const char *department) {
    char query[256];
    snprintf(query, sizeof(query), "INSERT INTO employees(name, age, department) VALUES('%s', %d, '%s')", name, age, department);
    if (mysql_query(conn, query)) {
        finish_with_error(conn);
    }
    printf("Employee %s inserted successfully.\n", name);
}

void fetch_all_employees(MYSQL *conn) {
    if (mysql_query(conn, "SELECT * FROM employees")) {
        finish_with_error(conn);
    }

    MYSQL_RES *result = mysql_store_result(conn);
    if (result == NULL) {
        finish_with_error(conn);
    }

    printf("Employees:\n");
    print_query_results(result);
    mysql_free_result(result);
}

void fetch_employee_by_id(MYSQL *conn, int id) {
    char query[256];
    snprintf(query, sizeof(query), "SELECT * FROM employees WHERE id = %d", id);
    
    if (mysql_query(conn, query)) {
        finish_with_error(conn);
    }

    MYSQL_RES *result = mysql_store_result(conn);
    if (result == NULL) {
        finish_with_error(conn);
    }

    printf("Employee with ID %d:\n", id);
    print_query_results(result);
    mysql_free_result(result);
}

void update_employee_age(MYSQL *conn, int id, int new_age) {
    char query[256];
    snprintf(query, sizeof(query), "UPDATE employees SET age = %d WHERE id = %d", new_age, id);
    if (mysql_query(conn, query)) {
        finish_with_error(conn);
    }
    printf("Employee ID %d updated to age %d.\n", id, new_age);
}

void delete_employee(MYSQL *conn, int id) {
    char query[256];
    snprintf(query, sizeof(query), "DELETE FROM employees WHERE id = %d", id);
    if (mysql_query(conn, query)) {
        finish_with_error(conn);
    }
    printf("Employee ID %d deleted successfully.\n", id);
}

int main() {
    MYSQL *conn = mysql_init(NULL);
    if (conn == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        return EXIT_FAILURE;
    }

    if (mysql_real_connect(conn, HOST, USER, PASSWORD, DATABASE, 0, NULL, 0) == NULL) {
        finish_with_error(conn);
    }

    create_table(conn);
    insert_employee(conn, "Alice Johnson", 30, "Marketing");
    insert_employee(conn, "Bob Smith", 45, "Sales");
    insert_employee(conn, "Charlie Brown", 25, "Development");

    fetch_all_employees(conn);
    fetch_employee_by_id(conn, 1); // Fetch employee by ID 1

    update_employee_age(conn, 2, 50); // Update age for ID 2
    delete_employee(conn, 3); // Delete employee with ID 3

    fetch_all_employees(conn); // Fetch again to see changes

    mysql_close(conn);
    return EXIT_SUCCESS;
}