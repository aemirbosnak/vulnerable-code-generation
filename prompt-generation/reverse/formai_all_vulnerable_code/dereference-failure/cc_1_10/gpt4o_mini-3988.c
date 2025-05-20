//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define HOST "localhost"
#define USER "root"
#define PASSWORD "your_password"
#define DATABASE "test_db"

void finish_with_error(MYSQL *conn) {
    fprintf(stderr, "mysql error: %s\n", mysql_error(conn));
    mysql_close(conn);
    exit(1);
}

void list_students(MYSQL *conn) {
    if (mysql_query(conn, "SELECT * FROM students")) {
        finish_with_error(conn);
    }

    MYSQL_RES *result = mysql_store_result(conn);
    if (result == NULL) {
        finish_with_error(conn);
    }

    int num_fields = mysql_num_fields(result);
    MYSQL_ROW row;

    printf("List of Students:\n");
    printf("%-10s %-20s %-15s\n", "ID", "Name", "Age");
    printf("-----------------------------------\n");

    while ((row = mysql_fetch_row(result))) {
        for (int i = 0; i < num_fields; i++) {
            printf("%-10s ", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }

    mysql_free_result(result);
}

void add_student(MYSQL *conn, const char *name, int age) {
    char query[256];
    sprintf(query, "INSERT INTO students (name, age) VALUES ('%s', %d)", name, age);

    if (mysql_query(conn, query)) {
        finish_with_error(conn);
    }
    printf("Student added: %s, Age: %d\n", name, age);
}

void delete_student(MYSQL *conn, int id) {
    char query[256];
    sprintf(query, "DELETE FROM students WHERE id = %d", id);

    if (mysql_query(conn, query)) {
        finish_with_error(conn);
    }
    printf("Deleted student with ID: %d\n", id);
}

void update_student(MYSQL *conn, int id, const char *name, int age) {
    char query[256];
    sprintf(query, "UPDATE students SET name = '%s', age = %d WHERE id = %d", name, age, id);

    if (mysql_query(conn, query)) {
        finish_with_error(conn);
    }
    printf("Updated student with ID: %d\n", id);
}

int main(void) {
    MYSQL *conn = mysql_init(NULL);

    if (conn == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        return EXIT_FAILURE;
    }

    if (mysql_real_connect(conn, HOST, USER, PASSWORD, DATABASE, 0, NULL, 0) == NULL) {
        finish_with_error(conn);
    }

    int choice;
    do {
        printf("\n--- Student Database Menu ---\n");
        printf("1. List Students\n");
        printf("2. Add Student\n");
        printf("3. Update Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to consume newline after choice

        switch (choice) {
            case 1:
                list_students(conn);
                break;
            case 2: {
                char name[50];
                int age;
                printf("Enter student name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0; // remove newline
                printf("Enter student age: ");
                scanf("%d", &age);
                add_student(conn, name, age);
                break;
            }
            case 3: {
                int id, age;
                char name[50];
                printf("Enter student ID to update: ");
                scanf("%d", &id);
                getchar(); // to consume newline
                printf("Enter new name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0; // remove newline
                printf("Enter new age: ");
                scanf("%d", &age);
                update_student(conn, id, name, age);
                break;
            }
            case 4: {
                int id;
                printf("Enter student ID to delete: ");
                scanf("%d", &id);
                delete_student(conn, id);
                break;
            }
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);

    mysql_close(conn);
    return EXIT_SUCCESS;
}