//GEMINI-pro DATASET v1.0 Category: Database querying ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

#define DB_FILE "my.db"
#define TABLE_NAME "my_table"

int main(void) {
    sqlite3 *db;
    sqlite3_stmt *stmt;
    char *sql;
    int rc;
    int i;
    char *data;
    int len;

    // Open the database
    rc = sqlite3_open(DB_FILE, &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    // Prepare the SQL statement
    sql = "SELECT * FROM " TABLE_NAME " WHERE name LIKE '%?%';";
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot prepare statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Bind the parameter
    sqlite3_bind_text(stmt, 1, "John", -1, SQLITE_STATIC);

    // Execute the statement
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_ROW) {
        fprintf(stderr, "No results found\n");
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 1;
    }

    // Get the data
    data = (char *)sqlite3_column_text(stmt, 0);
    len = sqlite3_column_bytes(stmt, 0);

    // Print the data
    for (i = 0; i < len; i++) {
        printf("%c", data[i]);
    }
    printf("\n");

    // Finalize the statement
    sqlite3_finalize(stmt);

    // Close the database
    sqlite3_close(db);

    return 0;
}