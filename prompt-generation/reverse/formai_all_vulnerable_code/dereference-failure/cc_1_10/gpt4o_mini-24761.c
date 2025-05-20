//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#define DATABASE_SIZE 100
#define NAME_LEN 50
#define INSERT_THREADS 5
#define RETRIEVE_THREADS 3

// Structure to represent a single record in the database
typedef struct {
    int id;
    char name[NAME_LEN];
} Record;

Record database[DATABASE_SIZE];
int current_records = 0;
pthread_mutex_t db_mutex;

// Function to insert a record into the database
void* insert_record(void* arg) {
    int id = *((int*)arg);
    free(arg); // Free the memory allocated for id

    pthread_mutex_lock(&db_mutex);
    if (current_records < DATABASE_SIZE) {
        database[current_records].id = id;
        snprintf(database[current_records].name, NAME_LEN, "Record_%d", id);
        current_records++;
        printf("Inserted: ID = %d, Name = %s\n", id, database[current_records - 1].name);
    } else {
        printf("Database full, cannot insert ID: %d\n", id);
    }
    pthread_mutex_unlock(&db_mutex);
    
    return NULL;
}

// Function to retrieve records from the database
void* retrieve_record(void* arg) {
    int id = *((int*)arg);
    free(arg); // Free the memory allocated for id

    pthread_mutex_lock(&db_mutex);
    for (int i = 0; i < current_records; i++) {
        if (database[i].id == id) {
            printf("Retrieved: ID = %d, Name = %s\n", id, database[i].name);
            pthread_mutex_unlock(&db_mutex);
            return NULL;
        }
    }
    printf("Record with ID = %d not found\n", id);
    pthread_mutex_unlock(&db_mutex);

    return NULL;
}

int main() {
    pthread_t insert_threads[INSERT_THREADS];
    pthread_t retrieve_threads[RETRIEVE_THREADS];
    pthread_mutex_init(&db_mutex, NULL);

    // Create insert threads
    for (int i = 0; i < INSERT_THREADS; i++) {
        int* id = malloc(sizeof(int));
        *id = i + 1; // Assign IDs starting from 1
        pthread_create(&insert_threads[i], NULL, insert_record, id);
    }

    // Wait for insert threads to complete
    for (int i = 0; i < INSERT_THREADS; i++) {
        pthread_join(insert_threads[i], NULL);
    }

    // Create retrieve threads
    for (int i = 0; i < RETRIEVE_THREADS; i++) {
        int* id = malloc(sizeof(int));
        *id = (i + 1) * 2; // Retrieve some records based on even IDs
        pthread_create(&retrieve_threads[i], NULL, retrieve_record, id);
    }

    // Wait for retrieve threads to complete
    for (int i = 0; i < RETRIEVE_THREADS; i++) {
        pthread_join(retrieve_threads[i], NULL);
    }

    pthread_mutex_destroy(&db_mutex);
    return 0;
}