//Falcon-180B DATASET v1.0 Category: Database querying ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

// Function prototypes
int callback(void *data, int argc, char **argv, char **azColName);
void usage();

// Global variables
static int count = 0;
static char *zErrMsg = 0;

// Function definitions
int callback(void *data, int argc, char **argv, char **azColName) {
    for (int i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i]? argv[i] : "NULL");
    }
    printf("\n");
    count++;
    return 0;
}

void usage() {
    printf("Usage:./program database_file sql_query\n");
    exit(1);
}

// Main function
int main(int argc, char *argv[]) {
    sqlite3 *db;
    char *zSql;
    char *zErrMsg = 0;
    int rc;

    // Check if correct number of arguments are provided
    if (argc!= 3) {
        usage();
    }

    // Open the SQLite database
    rc = sqlite3_open(argv[1], &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Create SQL query string
    zSql = malloc(strlen(argv[2]) + 1);
    strcpy(zSql, argv[2]);

    // Execute the SQL query and print results
    rc = sqlite3_exec(db, zSql, callback, 0, &zErrMsg);
    if (rc!= SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        printf("Total rows returned: %d\n", count);
    }

    // Close the SQLite database
    sqlite3_close(db);
    return 0;
}