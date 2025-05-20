//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define SERVER "localhost"
#define USER "root"
#define PASSWORD "password"  // Replace with your MySQL password
#define DATABASE "testdb"

void finish_with_error(MYSQL *conn) {
    fprintf(stderr, "MySQL error: %s\n", mysql_error(conn));
    mysql_close(conn);
    exit(1);
}

void execute_query(MYSQL *conn, const char *query) {
    if (mysql_query(conn, query)) {
        finish_with_error(conn);
    }
}

void display_results(MYSQL *conn) {
    MYSQL_RES *res;
    MYSQL_ROW row;

    res = mysql_store_result(conn);
    if (res == NULL) {
        finish_with_error(conn);
    }

    int num_fields = mysql_num_fields(res);
    
    while ((row = mysql_fetch_row(res))) {
        for (int i = 0; i < num_fields; i++) {
            printf("%s ", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }
    mysql_free_result(res);
}

void insert_data(MYSQL *conn) {
    char query[256];
    char name[100];
    int age;

    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter age: ");
    scanf("%d", &age);

    snprintf(query, sizeof(query), "INSERT INTO users (name, age) VALUES ('%s', %d)", name, age);
    execute_query(conn, query);
    printf("Data inserted successfully!\n");
}

void query_data(MYSQL *conn) {
    const char *query = "SELECT * FROM users";
    execute_query(conn, query);
    display_results(conn);
}

void update_data(MYSQL *conn) {
    char query[256];
    int user_id;
    char new_name[100];
    int new_age;

    printf("Enter user ID to update: ");
    scanf("%d", &user_id);
    printf("Enter new name: ");
    scanf("%s", new_name);
    printf("Enter new age: ");
    scanf("%d", &new_age);

    snprintf(query, sizeof(query), "UPDATE users SET name='%s', age=%d WHERE id=%d", new_name, new_age, user_id);
    execute_query(conn, query);
    printf("Data updated successfully!\n");
}

void delete_data(MYSQL *conn) {
    char query[256];
    int user_id;

    printf("Enter user ID to delete: ");
    scanf("%d", &user_id);

    snprintf(query, sizeof(query), "DELETE FROM users WHERE id=%d", user_id);
    execute_query(conn, query);
    printf("Data deleted successfully!\n");
}

void show_menu() {
    printf("\n=== MySQL CRUD Operation Menu ===\n");
    printf("1. Insert Data\n");
    printf("2. Query Data\n");
    printf("3. Update Data\n");
    printf("4. Delete Data\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    MYSQL *conn = mysql_init(NULL);
    if (conn == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        exit(EXIT_FAILURE);
    }

    if (mysql_real_connect(conn, SERVER, USER, PASSWORD, DATABASE, 0, NULL, 0) == NULL) {
        finish_with_error(conn);
    }

    int choice;
    do {
        show_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insert_data(conn);
                break;
            case 2:
                query_data(conn);
                break;
            case 3:
                update_data(conn);
                break;
            case 4:
                delete_data(conn);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);

    mysql_close(conn);
    return 0;
}