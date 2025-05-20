//FormAI DATASET v1.0 Category: Database querying ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define SUCCESS 0
#define FAILURE 1

/* Database credentials */
#define DB_HOST "localhost"
#define DB_USER "root"
#define DB_PASS "password"
#define DB_NAME "example_db"

/* Global database connection */
MYSQL *connection = NULL;

/* Function to connect to the database */
int connect_to_db() {
    /* Initialize connection handler */
    connection = mysql_init(NULL);

    /* Connect to the database */
    if(!mysql_real_connect(connection, DB_HOST, DB_USER, DB_PASS, DB_NAME, 0, NULL, 0)) {
        fprintf(stderr, "Error connecting to database: %s\n", mysql_error(connection));
        return FAILURE;
    }

    return SUCCESS;
}

/* Function to close the database connection */
void close_db_connection() {
    /* Close database connection */
    mysql_close(connection);
}

/* Function to execute a database query */
int execute_query(char *query) {
    /* Execute database query */
    if(mysql_query(connection, query)) {
        fprintf(stderr, "Error executing query: %s\n", mysql_error(connection));
        return FAILURE;
    }
    return SUCCESS;
}

/* Function to fetch query results */
void fetch_results(MYSQL_RES *result_set) {
    MYSQL_ROW row;

    /* Fetch results and print in tabular format */
    while((row = mysql_fetch_row(result_set))) {
        printf("%-5s%-20s%-20s%-20s\n", row[0], row[1], row[2], row[3]);
    }
}

/* Program entry point */
int main() {
    int status;
    MYSQL_RES *result_set;

    /* Connect to the database */
    status = connect_to_db();
    if(status == FAILURE) {
        fprintf(stderr, "Failed to connect to the database\n");
        exit(EXIT_FAILURE);
    }

    /* Execute the sample query */
    status = execute_query("SELECT id, name, email, phone FROM users WHERE id BETWEEN 1 AND 5");
    if(status == FAILURE) {
        fprintf(stderr, "Failed to execute the query\n");
        close_db_connection();
        exit(EXIT_FAILURE);
    } else {
        /* Get the result set */
        result_set = mysql_store_result(connection);

        /* Check for any errors */
        if(result_set == NULL) {
            fprintf(stderr, "Error fetching results: %s\n", mysql_error(connection));
            close_db_connection();
            exit(EXIT_FAILURE);
        }

        /* Print the results */
        printf("%-5s%-20s%-20s%-20s\n", "ID", "Name", "Email", "Phone");
        fetch_results(result_set);

        /* Free the result set */
        mysql_free_result(result_set);
    }

    /* Close the database connection */
    close_db_connection();

    return EXIT_SUCCESS;
}