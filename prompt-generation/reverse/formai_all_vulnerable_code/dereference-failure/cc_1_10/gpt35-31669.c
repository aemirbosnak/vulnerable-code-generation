//FormAI DATASET v1.0 Category: Database querying ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

#define MAX_QUERY_LENGTH 1000
#define MAX_RESPONSE_LENGTH 1000

static int callback(void *response, int argc, char **argv, char **col_name) {
    int i;
    char* row;
    
    for(i = 0; i < argc; i++) {
        if(i == 0) {
            row = argv[i];
        } else {
            row = strcat(row, ",");
            row = strcat(row, argv[i]);
        }
    }
    
    strcat(row,"\n");
    strcat((char*) response, row);
    
    return 0;
}

int main() {
    sqlite3 *db;
    char *query;
    char *response;
    char *error;
    int status;
    
    // Open the database file
    status = sqlite3_open("example.db", &db);
    if(status != SQLITE_OK) {
        fprintf(stderr, "Error opening database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }
    
    // Allocate memory for the query and response strings
    query = (char*) malloc(MAX_QUERY_LENGTH * sizeof(char));
    response = (char*) malloc(MAX_RESPONSE_LENGTH * sizeof(char));
    
    // Execute a simple query to retrieve all rows from the 'users' table
    strcpy(query, "SELECT * FROM users;");
    
    // Execute the query and handle any errors
    status = sqlite3_exec(db, query, callback, (void*) response, &error);
    if(status != SQLITE_OK) {
        fprintf(stderr, "Error executing query: %s\n", error);
        sqlite3_free(error);
        sqlite3_close(db);
        return 1;
    }
    
    printf("%s", response);
    
    // Free allocated memory and close the database connection
    sqlite3_free(query);
    sqlite3_free(response);
    sqlite3_close(db);
    
    return 0;
}