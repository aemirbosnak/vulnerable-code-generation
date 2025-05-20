//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_RECORDS 10
#define NUM_THREADS 5

// Record structure
typedef struct {
    int id;
    char name[20];
    int age;
} Record;

// Database structure
typedef struct {
    Record records[NUM_RECORDS];
    sem_t mutex;
} Database;

// Initialize database with sample data
void init_database(Database* db) {
    for (int i = 0; i < NUM_RECORDS; i++) {
        sprintf(db->records[i].name, "User %d", i + 1);
        db->records[i].age = i + 1;
    }
}

// Print record
void print_record(Record* rec) {
    printf("ID: %d, Name: %s, Age: %d\n", rec->id, rec->name, rec->age);
}

// Thread function to access database
void* thread_func(void* arg) {
    int thread_id = *(int*)arg;
    Database* db = (Database*)malloc(sizeof(Database));
    init_database(db);

    for (int i = 0; i < 10; i++) {
        sem_wait(&(db->mutex));
        print_record(&(db->records[thread_id]));
        sem_post(&(db->mutex));
        usleep(100000);
    }

    free(db);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int ids[NUM_THREADS];

    // Create mutex
    sem_init(&((Database*)malloc(sizeof(Database)))->mutex, 0, 1);

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        ids[i] = i + 1;
        pthread_create(&threads[i], NULL, thread_func, &ids[i]);
    }

    // Join threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}