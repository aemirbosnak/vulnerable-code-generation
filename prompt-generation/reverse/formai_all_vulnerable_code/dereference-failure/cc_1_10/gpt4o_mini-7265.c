//GPT-4o-mini DATASET v1.0 Category: Threading Library Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 5

// Structure to hold thread data
typedef struct {
    int thread_id;
    const char *message;
} thread_data_t;

// Function to be executed by each thread
void *PrintHello(void *threadarg) {
    thread_data_t *data = (thread_data_t *) threadarg;
    printf("Thread %d: %s\n", data->thread_id, data->message);
    free(threadarg); // Freeing the allocated memory for thread data
    pthread_exit(NULL);
}

// Function to create and manage threads
void createThreads() {
    pthread_t threads[NUM_THREADS];
    int rc;
    const char *messages[NUM_THREADS] = {
        "Hello from Thread 1",
        "Hello from Thread 2",
        "Hello from Thread 3",
        "Hello from Thread 4",
        "Hello from Thread 5"
    };

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data_t *data = (thread_data_t *) malloc(sizeof(thread_data_t));
        data->thread_id = i + 1; // Thread IDs are 1-indexed
        data->message = messages[i];

        rc = pthread_create(&threads[i], NULL, PrintHello, (void *) data);
        if (rc) {
            printf("Error: Unable to create thread %d, %d\n", i+1, rc);
            exit(-1);
        }
    }

    // Waiting for all threads to complete
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
}

// Main function
int main() {
    printf("Main: Starting thread creation...\n");
    createThreads();
    printf("Main: All threads completed successfully!\n");
    pthread_exit(NULL);
}