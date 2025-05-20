//FormAI DATASET v1.0 Category: Database querying ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

// Global variable to keep track of the database connection
sqlite3 *db;

// Function to callback for when executing SQL statements
int callback(void *data, int argc, char **argv, char **colName) {
    int i;
    for(i=0; i<argc; i++) {
        printf("%s: %s\n", colName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

// Function to connect to the database
void connect() {
    int rc;
    rc = sqlite3_open("example.db", &db);
    if(rc != SQLITE_OK) {
        fprintf(stderr, "Error connecting to database: %s\n", sqlite3_errmsg(db));
        exit(1);
    }
}

// Function to create a new table in the database
void createTable() {
    int rc;
    char createStmt[100];
    strcpy(createStmt, "CREATE TABLE IF NOT EXISTS users(id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT NOT NULL, age INTEGER NOT NULL);");
    rc = sqlite3_exec(db, createStmt, callback, 0, NULL);
    if(rc != SQLITE_OK) {
        fprintf(stderr, "Error creating table: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(1);
    }
}

// Function to insert a new user into the database
void insertUser(char *name, int age) {
    int rc;
    char insertStmt[100];
    sprintf(insertStmt, "INSERT INTO users(name, age) VALUES('%s', %d);", name, age);
    rc = sqlite3_exec(db, insertStmt, callback, 0, NULL);
    if(rc != SQLITE_OK) {
        fprintf(stderr, "Error inserting user: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(1);
    }
}

// Function to query for all users in the database
void queryUsers() {
    int rc;
    char queryStmt[50];
    strcpy(queryStmt, "SELECT * FROM users;");
    rc = sqlite3_exec(db, queryStmt, callback, 0, NULL);
    if(rc != SQLITE_OK) {
        fprintf(stderr, "Error querying users: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(1);
    }
}

int main() {
    connect();
    createTable();
    insertUser("John", 25);
    insertUser("Jane", 30);
    queryUsers();
    sqlite3_close(db);
    return 0;
}