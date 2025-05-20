//Falcon-180B DATASET v1.0 Category: Database querying ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <mysql/mysql.h>

#define MAX_QUERY_LENGTH 1000

// Function to connect to the MySQL database
MYSQL *connect_to_database(char *host, char *user, char *password, char *database) {
    MYSQL *conn = NULL;
    conn = mysql_init(NULL);

    if (!mysql_real_connect(conn, host, user, password, database, 0, NULL, 0)) {
        fprintf(stderr, "Failed to connect to the database: %s\n", mysql_error(conn));
        exit(1);
    }

    return conn;
}

// Function to execute a query and print the results
void execute_query(MYSQL *conn, char *query) {
    if (mysql_query(conn, query)) {
        fprintf(stderr, "Error executing query: %s\n", mysql_error(conn));
        exit(1);
    }

    MYSQL_RES *result = mysql_store_result(conn);
    MYSQL_ROW row;

    printf("Query results:\n");
    while ((row = mysql_fetch_row(result))) {
        for (int i = 0; i < mysql_num_fields(result); i++) {
            printf("%s ", row[i]? row[i] : "NULL");
        }
        printf("\n");
    }

    mysql_free_result(result);
}

// Function to prompt the user for a query
char *prompt_query(int max_length) {
    char *query = malloc(max_length * sizeof(char));

    printf("Enter your query (maximum length %d characters): ", max_length);
    fgets(query, max_length, stdin);

    // Remove newline character from the end of the input
    query[strcspn(query, "\n")] = '\0';

    return query;
}

int main() {
    char host[50] = "localhost";
    char user[50] = "root";
    char password[50] = "password";
    char database[50] = "medieval_kingdom";

    MYSQL *conn = connect_to_database(host, user, password, database);

    while (1) {
        printf("Welcome to the Medieval Kingdom Database!\n");
        printf("1. Execute a query\n2. Exit\n");

        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            char *query = prompt_query(MAX_QUERY_LENGTH);
            execute_query(conn, query);
        } else if (choice == 2) {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    mysql_close(conn);

    return 0;
}