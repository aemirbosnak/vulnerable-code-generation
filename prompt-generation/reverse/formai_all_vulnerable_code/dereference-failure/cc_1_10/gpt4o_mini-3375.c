//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

void finish_with_error(MYSQL *conn) {
    fprintf(stderr, "Error: %s\n", mysql_error(conn));
    mysql_close(conn);
    exit(1);
}

void execute_query(MYSQL *conn, const char *query) {
    if (mysql_query(conn, query)) {
        finish_with_error(conn);
    }

    MYSQL_RES *res = mysql_store_result(conn);
    if (res == NULL) {
        finish_with_error(conn);
    }

    int num_fields = mysql_num_fields(res);
    MYSQL_ROW row;

    while ((row = mysql_fetch_row(res))) {
        for (int i = 0; i < num_fields; i++) {
            printf("%s ", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }

    mysql_free_result(res);
}

void select_all_employees(MYSQL *conn) {
    printf("Fetching all employees:\n");
    execute_query(conn, "SELECT * FROM employees");
}

void select_employee_by_id(MYSQL *conn, int id) {
    char query[256];
    snprintf(query, sizeof(query), "SELECT * FROM employees WHERE id = %d", id);
    printf("Fetching employee with ID: %d\n", id);
    execute_query(conn, query);
}

void insert_new_employee(MYSQL *conn, const char *name, const char *position) {
    char query[512];
    snprintf(query, sizeof(query), "INSERT INTO employees (name, position) VALUES ('%s', '%s')", name, position);
    printf("Inserting new employee: %s, %s\n", name, position);
    execute_query(conn, query);
}

void delete_employee_by_id(MYSQL *conn, int id) {
    char query[256];
    snprintf(query, sizeof(query), "DELETE FROM employees WHERE id = %d", id);
    printf("Deleting employee with ID: %d\n", id);
    execute_query(conn, query);
}

void show_menu() {
    printf("\n--- Employee Database Menu ---\n");
    printf("1. Show all employees\n");
    printf("2. Find employee by ID\n");
    printf("3. Add new employee\n");
    printf("4. Delete employee by ID\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    MYSQL *conn = mysql_init(NULL);

    if (conn == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        return EXIT_FAILURE;
    }

    if (mysql_real_connect(conn, "localhost", "user", "password", "database", 0, NULL, 0) == NULL) {
        finish_with_error(conn);
    }

    int choice, id;
    char name[100], position[50];

    while (1) {
        show_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                select_all_employees(conn);
                break;
            case 2:
                printf("Enter employee ID: ");
                scanf("%d", &id);
                select_employee_by_id(conn, id);
                break;
            case 3:
                printf("Enter employee name: ");
                scanf("%s", name);
                printf("Enter employee position: ");
                scanf("%s", position);
                insert_new_employee(conn, name, position);
                break;
            case 4:
                printf("Enter employee ID to delete: ");
                scanf("%d", &id);
                delete_employee_by_id(conn, id);
                break;
            case 5:
                mysql_close(conn);
                printf("Exiting...\n");
                return EXIT_SUCCESS;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    mysql_close(conn);
    return EXIT_SUCCESS;
}