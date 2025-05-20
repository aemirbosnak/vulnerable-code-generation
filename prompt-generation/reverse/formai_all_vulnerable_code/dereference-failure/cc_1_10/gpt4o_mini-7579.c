//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

void finish_with_error(MYSQL *con) {
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    exit(1);        
}

void show_results(MYSQL *con) {
    MYSQL_RES *result;
    MYSQL_ROW row;
    
    // Store results from the query.
    result = mysql_store_result(con);
    if (result == NULL) {
        finish_with_error(con);
    }
    
    // Prepare header for output.
    int num_fields = mysql_num_fields(result);
    MYSQL_FIELD *fields = mysql_fetch_fields(result);
    for (int i = 0; i < num_fields; i++) {
        printf("%s\t", fields[i].name);
    }
    printf("\n");

    // Fetch and display each row of results.
    while ((row = mysql_fetch_row(result))) {
        for (int i = 0; i < num_fields; i++) {
            if (row[i] == NULL) {
                printf("NULL\t");
            } else {
                printf("%s\t", row[i]);
            }
        }
        printf("\n");
    }
    mysql_free_result(result);
}

void list_users(MYSQL *con) {
    if (mysql_query(con, "SELECT id, username, email FROM users")) {
        finish_with_error(con);
    }
    printf("Listing users:\n");
    show_results(con);
}

void add_user(MYSQL *con, const char *username, const char *email) {
    char query[256];
    snprintf(query, sizeof(query), "INSERT INTO users (username, email) VALUES ('%s', '%s')", username, email);
    
    if (mysql_query(con, query)) {
        finish_with_error(con);
    }
    printf("User '%s' with email '%s' added successfully!\n", username, email);
}

void delete_user(MYSQL *con, int user_id) {
    char query[256];
    snprintf(query, sizeof(query), "DELETE FROM users WHERE id=%d", user_id);
    
    if (mysql_query(con, query)) {
        finish_with_error(con);
    }
    printf("User with ID %d deleted successfully!\n", user_id);
}

int main(int argc, char **argv) {
    MYSQL *con = mysql_init(NULL);
    if (con == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        return EXIT_FAILURE;
    }

    // Connect to the database
    if (mysql_real_connect(con, "localhost", "user", "password", "database", 0, NULL, 0) == NULL) {
        finish_with_error(con);
    }

    // Exploring capabilities of querying and manipulating database.
    int choice;
    char username[100], email[100];
    int user_id;

    do {
        printf("\n--- User Management Menu ---\n");
        printf("1. List Users\n");
        printf("2. Add User\n");
        printf("3. Delete User\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                list_users(con);
                break;
            case 2:
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter email: ");
                scanf("%s", email);
                add_user(con, username, email);
                break;
            case 3:
                printf("Enter user ID to delete: ");
                scanf("%d", &user_id);
                delete_user(con, user_id);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 4);

    // Clean up and close MySQL connection
    mysql_close(con);
    return EXIT_SUCCESS;
}