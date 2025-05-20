//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string.h>
#include <pthread.h>

#define DB_NAME "test.db"
#define QUERY_SIZE 256
#define MAX_THREADS 5

typedef struct {
    char query[QUERY_SIZE];
    int thread_id;
} QueryData;

void *execute_query(void *data) {
    QueryData *query_data = (QueryData *)data;
    sqlite3 *db;
    char *errMsg = 0;
    int rc;

    // Open database
    rc = sqlite3_open(DB_NAME, &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return NULL;
    } else {
        fprintf(stderr, "Opened database successfully.\n");
    }

    // Execute query
    sqlite3_stmt *stmt;
    rc = sqlite3_prepare_v2(db, query_data->query, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to execute query: %s\n", sqlite3_errmsg(db));
    } else {
        fprintf(stderr, "Thread %d executing query: %s\n", query_data->thread_id, query_data->query);
        
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            const char *name = (const char *)sqlite3_column_text(stmt, 0);
            printf("Thread %d found user: %s\n", query_data->thread_id, name);
        }
    }

    // Cleanup
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    free(data);
    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    char query[QUERY_SIZE];

    // Prepare queries
    for (int i = 0; i < MAX_THREADS; i++) {
        QueryData *query_data = malloc(sizeof(QueryData));
        snprintf(query_data->query, QUERY_SIZE, "SELECT name FROM users WHERE id=%d;", i + 1);
        query_data->thread_id = i + 1;

        // Create and run thread
        if (pthread_create(&threads[i], NULL, execute_query, (void *)query_data) != 0) {
            perror("Failed to create thread");
            free(query_data);
            return 1;
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All queries executed successfully!\n");
    return 0;
}