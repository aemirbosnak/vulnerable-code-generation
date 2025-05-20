//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define HOST "localhost"
#define USER "root"
#define PASSWORD "password"
#define DATABASE "mydatabase"

void finish_with_error(MYSQL *conn) {
    fprintf(stderr, "%s\n", mysql_error(conn));
    mysql_close(conn);
    exit(1);
}

void display_employees(MYSQL *conn) {
    if (mysql_query(conn, "SELECT id, name, position FROM employees")) {
        finish_with_error(conn);
    }

    MYSQL_RES *result = mysql_store_result(conn);
    if (result == NULL) {
        finish_with_error(conn);
    }

    int num_fields = mysql_num_fields(result);
    MYSQL_ROW row;

    printf("\n--- Employee List ---\n");
    while ((row = mysql_fetch_row(result))) {
        for (int i = 0; i < num_fields; i++) {
            printf("%s\t", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }

    mysql_free_result(result);
}

void insert_employee(MYSQL *conn, const char *name, const char *position) {
    char query[256];
    snprintf(query, sizeof(query), "INSERT INTO employees (name, position) VALUES ('%s', '%s')", name, position);

    if (mysql_query(conn, query)) {
        finish_with_error(conn);
    }

    printf("Inserted %s (%s) into employees.\n", name, position);
}

void delete_employee(MYSQL *conn, int id) {
    char query[256];
    snprintf(query, sizeof(query), "DELETE FROM employees WHERE id = %d", id);

    if (mysql_query(conn, query)) {
        finish_with_error(conn);
    }

    printf("Deleted employee with ID: %d.\n", id);
}

void search_employee(MYSQL *conn, const char *name) {
    char query[256];
    snprintf(query, sizeof(query), "SELECT id, name, position FROM employees WHERE name LIKE '%%%s%%'", name);

    if (mysql_query(conn, query)) {
        finish_with_error(conn);
    }

    MYSQL_RES *result = mysql_store_result(conn);
    if (result == NULL) {
        finish_with_error(conn);
    }

    printf("\n--- Search Results for '%s' ---\n", name);
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(result))) {
        printf("ID: %s, Name: %s, Position: %s\n", row[0], row[1], row[2]);
    }

    mysql_free_result(result);
}

void display_menu() {
    printf("\n--- Employee Management System ---\n");
    printf("1. Display Employees\n");
    printf("2. Insert Employee\n");
    printf("3. Delete Employee\n");
    printf("4. Search Employee\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
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

    int choice;
    char name[100];
    char position[100];
    int id;

    while (1) {
        display_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                display_employees(conn);
                break;
            case 2:
                printf("Enter employee name: ");
                scanf("%s", name);
                printf("Enter employee position: ");
                scanf("%s", position);
                insert_employee(conn, name, position);
                break;
            case 3:
                printf("Enter employee ID to delete: ");
                scanf("%d", &id);
                delete_employee(conn, id);
                break;
            case 4:
                printf("Enter name to search: ");
                scanf("%s", name);
                search_employee(conn, name);
                break;
            case 5:
                mysql_close(conn);
                printf("Exiting... Goodbye!\n");
                return EXIT_SUCCESS;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    mysql_close(conn);
    return EXIT_SUCCESS;
}