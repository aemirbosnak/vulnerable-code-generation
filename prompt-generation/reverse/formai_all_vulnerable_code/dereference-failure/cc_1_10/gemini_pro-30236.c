//GEMINI-pro DATASET v1.0 Category: Database querying ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

// Custom data structure to store query results
typedef struct {
    char *name;
    int count;
} QueryResult;

// Function to compare QueryResults by count
int compareResults(const void *a, const void *b) {
    QueryResult *r1 = (QueryResult *)a;
    QueryResult *r2 = (QueryResult *)b;
    return r2->count - r1->count;
}

// Main function
int main() {
    // Open database
    sqlite3 *db;
    int rc = sqlite3_open("database.db", &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error opening database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Prepare query
    sqlite3_stmt *stmt;
    const char *query = "SELECT name, COUNT(*) AS count FROM table GROUP BY name ORDER BY count DESC";
    rc = sqlite3_prepare_v2(db, query, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error preparing query: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 1;
    }

    // Execute query
    QueryResult results[100];
    int i = 0;
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        results[i].name = strdup((const char *)sqlite3_column_text(stmt, 0));
        results[i].count = sqlite3_column_int(stmt, 1);
        i++;
    }
    if (rc != SQLITE_DONE) {
        fprintf(stderr, "Error executing query: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 1;
    }

    // Sort results
    qsort(results, i, sizeof(QueryResult), compareResults);

    // Print results
    printf("Top 10 most frequent names in the database:\n");
    for (int j = 0; j < i && j < 10; j++) {
        printf("%s: %d\n", results[j].name, results[j].count);
    }

    // Clean up
    for (int k = 0; k < i; k++) {
        free(results[k].name);
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return 0;
}