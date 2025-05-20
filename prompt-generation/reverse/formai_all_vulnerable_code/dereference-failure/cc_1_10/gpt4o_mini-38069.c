//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string.h>

#define MAX_QUERY_SIZE 256

// Function to display results from the query
void displayResults(int rows, char **results, char **columns) {
    printf("\nResults:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 2; j++) { // Assuming there are only 2 columns for demonstration
            printf("%s: %s ", columns[j], results[i * 2 + j]);
        }
        printf("\n");
    }
}

// Function to execute a query
void executeQuery(sqlite3 *db, const char *query) {
    char *errMsg = 0;
    char **results = NULL;
    int rows, columns;

    // Execute the SQL statement
    if (sqlite3_get_table(db, query, &results, &rows, &columns, &errMsg) != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
        return;
    }

    // Display results
    displayResults(rows, results + columns, results);

    // Free the memory allocated for results
    sqlite3_free_table(results);
}

int main() {
    sqlite3 *db;
    char query[MAX_QUERY_SIZE];
    
    // Open the database
    if (sqlite3_open("example.db", &db)) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return EXIT_FAILURE;
    }
    
    // Create a sample table if it doesn't exist
    char *errMsg;
    const char *createTableQuery = "CREATE TABLE IF NOT EXISTS employees (id INTEGER PRIMARY KEY, name TEXT, age INTEGER);";
    if (sqlite3_exec(db, createTableQuery, 0, 0, &errMsg) != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }

    // Insert sample data
    const char *insertData = "INSERT INTO employees (name, age) VALUES ('Alice', 30);"
                             "INSERT INTO employees (name, age) VALUES ('Bob', 25);"
                             "INSERT INTO employees (name, age) VALUES ('Charlie', 35);";
    if (sqlite3_exec(db, insertData, 0, 0, &errMsg) != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }

    while (1) {
        printf("\nEnter a name to search for (or type 'exit' to quit): ");
        char name[100];
        scanf("%99s", name);

        // Exit condition
        if (strcmp(name, "exit") == 0) {
            break;
        }

        // Prepare the dynamic SQL query
        snprintf(query, MAX_QUERY_SIZE, "SELECT * FROM employees WHERE name='%s';", name);

        // Execute the query
        executeQuery(db, query);
    }

    // Close the database
    sqlite3_close(db);
    return EXIT_SUCCESS;
}