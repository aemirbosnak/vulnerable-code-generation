//GEMINI-pro DATASET v1.0 Category: Database querying ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string.h>

// Define the maximum length of a query parameter
#define MAX_QUERY_PARAM_LENGTH 1024

// Define the maximum number of query parameters
#define MAX_QUERY_PARAMS 10

// Define the maximum length of a database field
#define MAX_DB_FIELD_LENGTH 1024

// Create a prepared statement
int prepare_statement(sqlite3 *db, const char *query, sqlite3_stmt **stmt) {
    int rc = sqlite3_prepare_v2(db, query, -1, stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        return -1;
    }
    return 0;
}

// Bind a query parameter to a prepared statement
int bind_parameter(sqlite3_stmt *stmt, int index, const char *value) {
    int rc = sqlite3_bind_text(stmt, index, value, -1, SQLITE_TRANSIENT);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to bind parameter: %s\n", sqlite3_errmsg(stmt));
        return -1;
    }
    return 0;
}

// Execute a prepared statement
int execute_statement(sqlite3_stmt *stmt) {
    int rc = sqlite3_step(stmt);
    if (rc != SQLITE_ROW && rc != SQLITE_DONE) {
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(stmt));
        return -1;
    }
    return 0;
}

// Get the value of a database field
int get_field_value(sqlite3_stmt *stmt, int index, char *buffer, int buffer_size) {
    const char *value = sqlite3_column_text(stmt, index);
    if (value == NULL) {
        fprintf(stderr, "Failed to get field value: %s\n", sqlite3_errmsg(stmt));
        return -1;
    }
    strncpy(buffer, value, buffer_size);
    buffer[buffer_size - 1] = '\0';
    return 0;
}

// Main function
int main() {
    // Open the database
    sqlite3 *db;
    int rc = sqlite3_open("test.db", &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to open database: %s\n", sqlite3_errmsg(db));
        return -1;
    }

    // Prepare a parameterized query
    const char *query = "SELECT name FROM users WHERE age = ?";
    sqlite3_stmt *stmt;
    rc = prepare_statement(db, query, &stmt);
    if (rc != 0) {
        sqlite3_close(db);
        return -1;
    }

    // Bind the query parameter
    const char *age = "21";
    rc = bind_parameter(stmt, 1, age);
    if (rc != 0) {
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return -1;
    }

    // Execute the query
    rc = execute_statement(stmt);
    if (rc != 0) {
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return -1;
    }

    // Get the result
    char name[MAX_DB_FIELD_LENGTH];
    rc = get_field_value(stmt, 0, name, MAX_DB_FIELD_LENGTH);
    if (rc != 0) {
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return -1;
    }

    // Print the result
    printf("Name: %s\n", name);

    // Finalize the statement
    sqlite3_finalize(stmt);

    // Close the database
    sqlite3_close(db);

    return 0;
}