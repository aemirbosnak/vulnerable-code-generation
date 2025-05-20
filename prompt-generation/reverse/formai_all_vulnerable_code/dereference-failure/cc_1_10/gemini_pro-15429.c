//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

// Database simulation
typedef struct {
    int id;
    char *name;
    int age;
} person_t;

// Database
person_t *db;
int db_size;

// Semaphore for database access
sem_t db_sem;

// Thread function
void *thread_func(void *arg) {
    int id = (int)arg;

    // Acquire database lock
    sem_wait(&db_sem);

    // Access database
    printf("Thread %d: accessing database...\n", id);
    for (int i = 0; i < db_size; i++) {
        printf("Thread %d: %d %s %d\n", id, db[i].id, db[i].name, db[i].age);
    }

    // Release database lock
    sem_post(&db_sem);

    // Exit thread
    pthread_exit(NULL);
}

int main() {
    // Initialize database
    db_size = 10;
    db = malloc(sizeof(person_t) * db_size);
    for (int i = 0; i < db_size; i++) {
        db[i].id = i;
        db[i].name = malloc(10);
        sprintf(db[i].name, "Person %d", i);
        db[i].age = rand() % 100;
    }

    // Initialize semaphore
    sem_init(&db_sem, 0, 1);

    // Create threads
    pthread_t threads[10];
    for (int i = 0; i < 10; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void *)i);
    }

    // Join threads
    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy semaphore
    sem_destroy(&db_sem);

    // Free database
    for (int i = 0; i < db_size; i++) {
        free(db[i].name);
    }
    free(db);

    return 0;
}