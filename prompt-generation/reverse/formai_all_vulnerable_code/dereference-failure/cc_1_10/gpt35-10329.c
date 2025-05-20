//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_THREADS 5 // Maximum number of threads to create
#define MAX_COUNT 10 // Maximum number of times to print

int count = 0; // Global variable to keep track of count
pthread_mutex_t mutex; // Mutex lock to ensure thread safety

void* print_count(void* thread_id) {
    int tid = *((int*) thread_id);
    free(thread_id); // Free the memory allocated to the thread id

    for (int i = 0; i < MAX_COUNT; i++) {
        pthread_mutex_lock(&mutex); // Lock the mutex

        printf("Thread %d: count = %d\n", tid, count);
        count++; // Increment the global count variable

        pthread_mutex_unlock(&mutex); // Unlock the mutex

        sleep(1); // Sleep for 1 second to simulate work
    }

    pthread_exit(NULL); // Exit the thread
}

int main() {
    pthread_t threads[MAX_THREADS]; // Array to store thread IDs
    int rc;

    // Initialize the mutex lock
    if (pthread_mutex_init(&mutex, NULL) != 0) {
        printf("Error: Unable to initialize mutex!\n");
        exit(1);
    }

    // Create threads
    for (int i = 0; i < MAX_THREADS; i++) {
        int* tid = malloc(sizeof(int)); // Allocate memory for thread ID
        *tid = i;

        rc = pthread_create(&threads[i], NULL, print_count, tid);
        if (rc) {
            printf("Error: Unable to create thread %d. Return code from pthread_create() is %d.\n", i, rc);
            exit(1);
        }
    }

    // Wait for threads to finish
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the mutex lock
    pthread_mutex_destroy(&mutex);

    printf("Finished!\n");

    return 0;
}