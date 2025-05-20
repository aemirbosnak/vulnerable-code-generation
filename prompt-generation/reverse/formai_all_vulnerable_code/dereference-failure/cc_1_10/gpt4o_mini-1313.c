//GPT-4o-mini DATASET v1.0 Category: Threading Library Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#define NUM_THREADS 5
#define MESSAGE_LENGTH 50

typedef struct {
    int thread_id;
    char message[MESSAGE_LENGTH];
} thread_data_t;

void *print_message(void *thread_data) {
    thread_data_t *data = (thread_data_t *)thread_data;

    // Simulate some work
    for (int i = 0; i < 3; i++) {
        printf("Thread %d: %s (%d)\n", 
               data->thread_id, 
               data->message, 
               i + 1);
        sleep(1);  // Sleep for 1 second
    }

    free(thread_data); // Free the allocated memory
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    int i;

    // Populate thread data and create threads
    for (i = 0; i < NUM_THREADS; i++) {
        thread_data_t *data = malloc(sizeof(thread_data_t));
        data->thread_id = i;
        snprintf(data->message, MESSAGE_LENGTH, "Hello from thread %d!", i);
        
        rc = pthread_create(&threads[i], NULL, print_message, (void *)data);
        if (rc) {
            fprintf(stderr, "Error creating thread %d: %d\n", i, rc);
            free(data); // Free memory on error
            exit(-1);
        }
    }

    // Wait for all threads to complete
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads completed execution.\n");
    pthread_exit(NULL);
}