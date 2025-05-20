//FormAI DATASET v1.0 Category: Database simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_SIZE 100 // Maximum size of the database
#define MAX_THREADS 10 // Maximum number of threads

int db[MAX_SIZE]; // The database where integers are stored
int db_size = 0; // The current size of the database
pthread_mutex_t db_mutex; // Mutex to protect the database

void *add_data(void *arg) {
    int n = *(int *) arg; // Get the number to add to the database
    pthread_mutex_lock(&db_mutex); // Lock the database
    if (db_size < MAX_SIZE) {
        db[db_size++] = n; // Add the number to the database
        printf("%d added to the database\n", n);
    } else {
        printf("Database full, %d cannot be added\n", n);
    }
    pthread_mutex_unlock(&db_mutex); // Unlock the database
    free(arg); // Free the memory used by the argument
    pthread_exit(NULL); // Terminate the thread
}

void *remove_data(void *arg) {
    int n = *(int *) arg; // Get the number to remove from the database
    pthread_mutex_lock(&db_mutex); // Lock the database
    for (int i = 0; i < db_size; i++) {
        if (db[i] == n) {
            db[i] = db[--db_size]; // Remove the number from the database
            printf("%d removed from the database\n", n);
            break;
        }
    }
    pthread_mutex_unlock(&db_mutex); // Unlock the database
    free(arg); // Free the memory used by the argument
    pthread_exit(NULL); // Terminate the thread
}

int main() {
    pthread_t threads[MAX_THREADS]; // The threads
    int thread_count = 0; // The current number of threads
    pthread_mutex_init(&db_mutex, NULL); // Initialize the mutex

    // Add some numbers to the database
    int numbers[] = {5, 10, 15, 20, 25};
    for (int i = 0; i < sizeof(numbers) / sizeof(int); i++) {
        int *arg = malloc(sizeof(int)); // Allocate memory for the argument
        *arg = numbers[i]; // Set the argument value
        pthread_create(&threads[thread_count++], NULL, add_data, arg); // Create a thread to add the number
    }

    // Remove some numbers from the database
    int to_remove[] = {10, 15};
    for (int i = 0; i < sizeof(to_remove) / sizeof(int); i++) {
        int *arg = malloc(sizeof(int)); // Allocate memory for the argument
        *arg = to_remove[i]; // Set the argument value
        pthread_create(&threads[thread_count++], NULL, remove_data, arg); // Create a thread to remove the number
    }

    // Wait for all threads to finish
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&db_mutex); // Destroy the mutex
    return 0;
}