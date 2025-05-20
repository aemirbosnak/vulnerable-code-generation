//FormAI DATASET v1.0 Category: Database querying ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>
#include <pthread.h>

#define DB_FILE "example.db"

// Callback function for SELECT statement
static int callback(void *data, int argc, char **argv, char **azColName) {
    for (int i = 0; i < argc; ++i) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

// Asynchronous task struct
typedef struct async_task {
    int id;
    char *query;
    sqlite3 *db;
    pthread_t thread;
} async_task;

// Asynchronous task function
void *async_query(void *arg) {
    async_task *task = (async_task*)arg;
    char *errMsg = NULL;
    int rc = sqlite3_exec(task->db, task->query, callback, NULL, &errMsg);
    if (rc != SQLITE_OK) {
        printf("ERROR: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
    sqlite3_close(task->db);
    free(task->query);
    free(task);
    return NULL;
}

int main() {
    sqlite3 *db;
    int rc = sqlite3_open(DB_FILE, &db);
    if (rc != SQLITE_OK) {
        printf("ERROR: Unable to open database\n");
        return 1;
    }

    // Create table if it doesn't exist
    char *query = "CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, name TEXT, age INTEGER);";
    char *errMsg = NULL;
    rc = sqlite3_exec(db, query, NULL, NULL, &errMsg);
    if (rc != SQLITE_OK) {
        printf("ERROR: %s\n", errMsg);
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return 1;
    }

    // Insert data
    query = "INSERT INTO users (name, age) VALUES ('John Doe', 30);";
    rc = sqlite3_exec(db, query, NULL, NULL, &errMsg);
    if (rc != SQLITE_OK) {
        printf("ERROR: %s\n", errMsg);
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return 1;
    }

    // Asynchronous SELECT statement
    async_task *task = (async_task*)malloc(sizeof(async_task));
    task->id = 1;
    task->db = db;
    task->query = strdup("SELECT * FROM users;");
    pthread_create(&task->thread, NULL, async_query, task);

    // Wait for task to finish
    pthread_join(task->thread, NULL);

    return 0;
}