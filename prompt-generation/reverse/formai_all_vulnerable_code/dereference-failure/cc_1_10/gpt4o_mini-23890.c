//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define DATABASE_SIZE 100
#define NAME_LENGTH 50

typedef struct Record {
    int id;
    char name[NAME_LENGTH];
    struct Record* next;
} Record;

Record* database = NULL;
pthread_mutex_t db_mutex;

void insert_record(int id, const char* name) {
    pthread_mutex_lock(&db_mutex);

    Record* new_record = (Record*)malloc(sizeof(Record));
    new_record->id = id;
    strncpy(new_record->name, name, NAME_LENGTH);
    new_record->next = database;
    database = new_record;

    pthread_mutex_unlock(&db_mutex);
}

Record* find_record(int id) {
    pthread_mutex_lock(&db_mutex);
    
    Record* current = database;
    while (current != NULL) {
        if (current->id == id) {
            Record* found = (Record*)malloc(sizeof(Record));
            *found = *current; // Copy found record
            pthread_mutex_unlock(&db_mutex);
            return found;
        }
        current = current->next;
    }

    pthread_mutex_unlock(&db_mutex);
    return NULL;
}

void delete_record(int id) {
    pthread_mutex_lock(&db_mutex);
    
    Record* current = database;
    Record* previous = NULL;

    while (current != NULL) {
        if (current->id == id) {
            if (previous == NULL) {
                database = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            pthread_mutex_unlock(&db_mutex);
            return;
        }
        previous = current;
        current = current->next;
    }

    pthread_mutex_unlock(&db_mutex);
}

void* db_operations(void* arg) {
    int thread_id = *((int*)arg);
    for (int i = 0; i < 5; i++) {
        int id = thread_id * 10 + i;
        char name[NAME_LENGTH];
        snprintf(name, NAME_LENGTH, "Record_%d", id);

        insert_record(id, name);
        printf("Thread %d: Inserted %s\n", thread_id, name);

        sleep(1); // Simulate workload

        Record* found = find_record(id);
        if (found != NULL) {
            printf("Thread %d: Found Record ID: %d, Name: %s\n", thread_id, found->id, found->name);
            free(found); // Free the duplicated found record
        }

        if (i % 2 == 0) {
            delete_record(id);
            printf("Thread %d: Deleted Record ID: %d\n", thread_id, id);
        }
    }
    return NULL;
}

int main() {
    pthread_t threads[5];
    int thread_ids[5];

    pthread_mutex_init(&db_mutex, NULL);

    // Create multiple threads
    for (int i = 0; i < 5; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, db_operations, &thread_ids[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    // Cleanup
    while (database != NULL) {
        Record* temp = database;
        database = database->next;
        free(temp);
    }

    pthread_mutex_destroy(&db_mutex);
    
    printf("Database simulation completed.\n");
    return 0;
}