//FormAI DATASET v1.0 Category: Database querying ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

// Callback function to handle results of query
static int callback(void *data, int argc, char **argv, char **col_names) {
    for (int i = 0; i < argc; i++) {
        printf("%s: %s\n", col_names[i], argv[i] ? argv[i] : "NULL");
    }
    return 0; // Returning 0 indicates success
}

int main(void) {
    sqlite3 *db;
    char *err_msg = NULL;
    int rc = sqlite3_open("example.db", &db); // Open database

    // Handle errors
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Run query
    char *query = "SELECT * FROM users WHERE age > ? AND email LIKE ?";
    sqlite3_stmt *stmt;
    rc = sqlite3_prepare_v2(db, query, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot prepare statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Bind parameters and execute query
    int age = 25;
    char *email = "%@gmail.com";
    sqlite3_bind_int(stmt, 1, age);
    sqlite3_bind_text(stmt, 2, email, strlen(email), SQLITE_STATIC);
    rc = sqlite3_step(stmt);

    // Handle results
    if (rc != SQLITE_ROW && rc != SQLITE_DONE) {
        fprintf(stderr, "Cannot execute query: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 1;
    }

    // Print results
    while (rc == SQLITE_ROW) {
        callback(NULL, sqlite3_column_count(stmt), sqlite3_column_value(stmt, 0), sqlite3_column_name(stmt, 0));
        rc = sqlite3_step(stmt);
    }

    // Clean up
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return 0;
}