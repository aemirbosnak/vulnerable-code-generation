//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_RECORDS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int count;
    pthread_mutex_t lock;
} Database;

Database db;

void* index_record(void* arg) {
    Record* record = (Record*)arg;

    pthread_mutex_lock(&db.lock);
    if (db.count < MAX_RECORDS) {
        db.records[db.count++] = *record;
        printf("Indexed Record: ID = %d, Name = %s\n", record->id, record->name);
    } else {
        printf("Database is full! Cannot index record with ID = %d\n", record->id);
    }
    pthread_mutex_unlock(&db.lock);

    return NULL;
}

void* query_records(void* arg) {
    char* query_name = (char*)arg;
    
    pthread_mutex_lock(&db.lock);
    int found = 0;
    for (int i = 0; i < db.count; i++) {
        if (strcmp(db.records[i].name, query_name) == 0) {
            printf("Found Record: ID = %d, Name = %s\n", db.records[i].id, db.records[i].name);
            found = 1;
        }
    }
    if (!found) {
        printf("No records found for Name = %s\n", query_name);
    }
    pthread_mutex_unlock(&db.lock);

    return NULL;
}

int main() {
    pthread_t threads[10];
    db.count = 0;
    pthread_mutex_init(&db.lock, NULL);

    // Indexing some records asynchronously
    for (int i = 0; i < 5; i++) {
        Record* record = malloc(sizeof(Record));
        record->id = i;
        snprintf(record->name, MAX_NAME_LENGTH, "Name%d", i);
        
        if (pthread_create(&threads[i], NULL, index_record, record) != 0) {
            perror("Failed to create thread");
        }
    }

    // Waiting for indexing to complete
    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    // Query records asynchronously
    for (int i = 0; i < 5; i++) {
        char* name_query = malloc(MAX_NAME_LENGTH);
        snprintf(name_query, MAX_NAME_LENGTH, "Name%d", i);
        
        if (pthread_create(&threads[i], NULL, query_records, name_query) != 0) {
            perror("Failed to create thread for querying");
        }
    }

    // Waiting for queries to complete
    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    // Clean up
    pthread_mutex_destroy(&db.lock);
    return 0;
}