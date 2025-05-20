//GEMINI-pro DATASET v1.0 Category: Database querying ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

#define CONFIG_FILE "config.txt"
#define MAX_QUERY_SIZE 1024

// Read a line from a file
char *readLine(FILE *file) {
    char *line = NULL;
    size_t len = 0;
    getline(&line, &len, file);
    return line;
}

// Parse a query from a string
char *parseQuery(char *str) {
    char *query = NULL;
    int len = strlen(str);
    if (len > 0 && str[len - 1] == ';') {
        str[len - 1] = '\0';
        query = strdup(str);
    }
    return query;
}

// Execute a query on a database
int executeQuery(sqlite3 *db, char *query) {
    int rc = sqlite3_exec(db, query, 0, 0, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error executing query: %s\n", sqlite3_errmsg(db));
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

// Print the results of a query
int printResults(sqlite3 *db, char *query) {
    sqlite3_stmt *stmt = NULL;
    int rc = sqlite3_prepare(db, query, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error preparing statement: %s\n", sqlite3_errmsg(db));
        return EXIT_FAILURE;
    }
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        int colCount = sqlite3_column_count(stmt);
        for (int i = 0; i < colCount; i++) {
            printf("%s\t", sqlite3_column_text(stmt, i));
        }
        printf("\n");
    }
    if (rc != SQLITE_DONE) {
        fprintf(stderr, "Error executing statement: %s\n", sqlite3_errmsg(db));
        return EXIT_FAILURE;
    }
    sqlite3_finalize(stmt);
    return EXIT_SUCCESS;
}

// Main function
int main(void) {
    // Open the configuration file
    FILE *config = fopen(CONFIG_FILE, "r");
    if (config == NULL) {
        fprintf(stderr, "Error opening configuration file: %s\n", CONFIG_FILE);
        return EXIT_FAILURE;
    }

    // Read the database filename from the configuration file
    char *dbFilename = readLine(config);
    if (dbFilename == NULL) {
        fprintf(stderr, "Error reading database filename from configuration file: %s\n", CONFIG_FILE);
        return EXIT_FAILURE;
    }

    // Open the database
    sqlite3 *db = NULL;
    int rc = sqlite3_open(dbFilename, &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error opening database: %s\n", sqlite3_errmsg(db));
        return EXIT_FAILURE;
    }

    // Read the queries from the configuration file
    char *query;
    while ((query = readLine(config)) != NULL) {
        // Parse the query
        query = parseQuery(query);
        if (query == NULL) {
            fprintf(stderr, "Error parsing query: %s\n", query);
            continue;
        }

        // Execute the query
        rc = executeQuery(db, query);
        if (rc != EXIT_SUCCESS) {
            return rc;
        }
    }

    // Close the database
    sqlite3_close(db);
    return EXIT_SUCCESS;
}