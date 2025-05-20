//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define HOST "localhost"
#define USER "root"
#define PASSWORD "your_password" // enter your MySQL root password
#define DATABASE "sherlock_holmes"

void check_query(MYSQL *conn, const char *query) {
    if (mysql_query(conn, query)) {
        fprintf(stderr, "Error in query: %s\n", mysql_error(conn));
        exit(EXIT_FAILURE);
    }
}

void investigate_case(MYSQL *conn, const char *case_name) {
    char query[512];
    snprintf(query, sizeof(query), "SELECT * FROM cases WHERE case_name='%s';", case_name);
    check_query(conn, query);

    MYSQL_RES *result = mysql_store_result(conn);
    if (result == NULL) {
        fprintf(stderr, "Could not fetch results: %s\n", mysql_error(conn));
        return;
    }

    int num_fields = mysql_num_fields(result);
    MYSQL_ROW row;
    
    printf("Investigation Report for Case: %s\n", case_name);
    while ((row = mysql_fetch_row(result))) {
        for (int i = 0; i < num_fields; i++) {
            printf("%s ", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }
    mysql_free_result(result);
}

void display_cases(MYSQL *conn) {
    const char *query = "SELECT case_name FROM cases;";
    check_query(conn, query);

    MYSQL_RES *result = mysql_store_result(conn);
    if (result == NULL) {
        fprintf(stderr, "Could not fetch results: %s\n", mysql_error(conn));
        return;
    }

    MYSQL_ROW row;
    printf("Available Cases:\n");
    while ((row = mysql_fetch_row(result))) {
        printf("%s\n", row[0]);
    }
    mysql_free_result(result);
}

void add_case(MYSQL *conn, const char *case_name, const char *description) {
    char query[512];
    snprintf(query, sizeof(query), "INSERT INTO cases (case_name, description) VALUES ('%s', '%s');", case_name, description);
    check_query(conn, query);
    printf("New case '%s' has been added successfully.\n", case_name);
}

int main() {
    MYSQL *conn;
    conn = mysql_init(NULL);
    if (conn == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        return EXIT_FAILURE;
    }

    if (mysql_real_connect(conn, HOST, USER, PASSWORD, DATABASE, 0, NULL, 0) == NULL) {
        fprintf(stderr, "mysql_real_connect() failed\n");
        mysql_close(conn);
        return EXIT_FAILURE;
    }

    char choice;
    while (1) {
        printf("Welcome to the Sherlock Holmes Case Management System.\n");
        printf("Choose an option:\n");
        printf("1. Display available cases\n");
        printf("2. Investigate a case\n");
        printf("3. Add a new case\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        choice = getchar();
        while(getchar() != '\n'); // Clear input buffer

        switch (choice) {
            case '1':
                display_cases(conn);
                break;
            case '2': {
                char case_name[100];
                printf("Enter the case name to investigate: ");
                fgets(case_name, sizeof(case_name), stdin);
                case_name[strcspn(case_name, "\n")] = 0; // Remove newline character
                investigate_case(conn, case_name);
                break;
            }
            case '3': {
                char case_name[100], description[256];
                printf("Enter the case name: ");
                fgets(case_name, sizeof(case_name), stdin);
                case_name[strcspn(case_name, "\n")] = 0; // Remove newline character
                printf("Enter case description: ");
                fgets(description, sizeof(description), stdin);
                description[strcspn(description, "\n")] = 0; // Remove newline character
                add_case(conn, case_name, description);
                break;
            }
            case '4':
                mysql_close(conn);
                return EXIT_SUCCESS;
            default:
                printf("Invalid option, try again.\n");
        }
    }
}