//GEMINI-pro DATASET v1.0 Category: Database querying ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

#define LAUGH_OUT_LOUD "LOL"
#define ROFLMAO "ROTFLMAO"
#define LMAO "LMAO"

int main() {
    // Open the database
    sqlite3 *db;
    int rc = sqlite3_open("jokes.db", &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error opening the database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Prepare the statement
    sqlite3_stmt *stmt;
    rc = sqlite3_prepare_v2(db, "SELECT joke FROM jokes ORDER BY RANDOM() LIMIT 1", -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error preparing the statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Step through the results
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        // Get the joke
        const char *joke = (const char *) sqlite3_column_text(stmt, 0);

        // Print the joke
        printf("%s\n", joke);

        // Add a funny comment
        if (strlen(joke) < 10) {
            printf(LAUGH_OUT_LOUD "\n");
        } else if (strlen(joke) < 20) {
            printf(ROFLMAO "\n");
        } else {
            printf(LMAO "\n");
        }
    }

    // Finalize the statement
    sqlite3_finalize(stmt);

    // Close the database
    sqlite3_close(db);

    return 0;
}