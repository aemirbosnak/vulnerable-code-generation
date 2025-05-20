//GEMINI-pro DATASET v1.0 Category: Database querying ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

// Define the maximum size of the SQL query string.
#define QUERY_SIZE 1024

// Define the maximum number of rows to be returned by the query.
#define MAX_ROWS 100

// Define the maximum number of columns to be returned by the query.
#define MAX_COLUMNS 10

// Define the data type of the query results.
typedef struct {
    int id;
    char *name;
    int age;
} Result;

// Define the function to print the query results.
void print_results(Result *results, int num_rows, int num_columns) {
    for (int i = 0; i < num_rows; i++) {
        printf("Row %d:\n", i + 1);
        for (int j = 0; j < num_columns; j++) {
            printf("    Column %d: %s\n", j + 1, results[i].name);
        }
    }
}

// Define the function to query the database.
int query_database(sqlite3 *db, char *query, Result *results, int *num_rows, int *num_columns) {
    // Prepare the SQL statement.
    sqlite3_stmt *stmt;
    int rc = sqlite3_prepare_v2(db, query, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare SQL statement: %s\n", sqlite3_errmsg(db));
        return rc;
    }

    // Execute the SQL statement.
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_ROW) {
        fprintf(stderr, "Failed to execute SQL statement: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        return rc;
    }

    // Get the number of rows and columns in the query results.
    *num_rows = sqlite3_column_count(stmt);
    *num_columns = sqlite3_column_count(stmt);

    // Allocate memory for the query results.
    results = (Result *)malloc(sizeof(Result) * *num_rows);

    // Get the data from the query results.
    for (int i = 0; i < *num_rows; i++) {
        results[i].id = sqlite3_column_int(stmt, 0);
        results[i].name = (char *)sqlite3_column_text(stmt, 1);
        results[i].age = sqlite3_column_int(stmt, 2);
    }

    // Finalize the SQL statement.
    sqlite3_finalize(stmt);

    return SQLITE_OK;
}

// Define the main function.
int main(int argc, char *argv[]) {
    // Open the database.
    sqlite3 *db;
    int rc = sqlite3_open("database.db", &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to open database: %s\n", sqlite3_errmsg(db));
        return rc;
    }

    // Create the SQL query string.
    char query[QUERY_SIZE];
    snprintf(query, QUERY_SIZE, "SELECT * FROM people WHERE age > 21");

    // Query the database.
    Result results[MAX_ROWS];
    int num_rows;
    int num_columns;
    rc = query_database(db, query, results, &num_rows, &num_columns);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to query database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return rc;
    }

    // Print the query results.
    print_results(results, num_rows, num_columns);

    // Free the memory allocated for the query results.
    free(results);

    // Close the database.
    sqlite3_close(db);

    return 0;
}