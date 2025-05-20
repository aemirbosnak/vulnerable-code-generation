//Falcon-180B DATASET v1.0 Category: Database querying ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

// Function prototypes
int callback(void* not_used, int argc, char** argv, char** col_name);
char* errMsg = 0;

// Function to display usage
void usage() {
    printf("Usage:./program database_name table_name column_name value\n");
    exit(1);
}

// Main function
int main(int argc, char** argv) {
    // Check if correct number of arguments are provided
    if(argc!= 5) {
        usage();
    }

    // Open the database
    sqlite3* db;
    int rc = sqlite3_open(argv[1], &db);

    if(rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(1);
    }

    // Create SQL query string
    char* sql = malloc(100 * sizeof(char));
    sprintf(sql, "SELECT * FROM %s WHERE %s = '%s';", argv[2], argv[3], argv[4]);

    // Execute the query and display results
    char* errMsg = 0;
    rc = sqlite3_exec(db, sql, callback, 0, &errMsg);

    if(rc!= SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        printf("Results:\n");
    }

    // Close the database
    sqlite3_close(db);
    return 0;
}

// Callback function to display query results
int callback(void* not_used, int argc, char** argv, char** col_name) {
    for(int i=0; i<argc; i++) {
        printf("%s = %s\n", col_name[i], argv[i]? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}