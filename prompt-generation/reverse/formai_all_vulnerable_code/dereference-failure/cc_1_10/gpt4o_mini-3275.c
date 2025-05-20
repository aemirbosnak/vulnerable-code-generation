//GPT-4o-mini DATASET v1.0 Category: Threading Library Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 5
#define MAX_COUNT 10

// Structure to represent data for thread
typedef struct {
    int thread_id;
    int count_to;
} ThreadData;

// Mutex for thread synchronization
pthread_mutex_t lock;

// Function to simulate work done by threads
void* threadFunction(void* arg) {
    ThreadData* data = (ThreadData*)arg;

    for (int i = 1; i <= data->count_to; i++) {
        pthread_mutex_lock(&lock);
        printf("Thread %d working on count: %d\n", data->thread_id, i);
        pthread_mutex_unlock(&lock);
        sleep(1);
    }

    free(data);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    pthread_mutex_init(&lock, NULL);

    // Creating threads
    for (int t = 0; t < NUM_THREADS; t++) {
        ThreadData* data = (ThreadData*)malloc(sizeof(ThreadData));
        data->thread_id = t + 1;
        data->count_to = MAX_COUNT - t; // Varying count for each thread
        
        if (pthread_create(&threads[t], NULL, threadFunction, (void*)data) != 0) {
            fprintf(stderr, "Error creating thread %d\n", t + 1);
            return 1; // Return error
        }
    }

    // Joining threads
    for (int t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }

    pthread_mutex_destroy(&lock);
    printf("All threads completed successfully!\n");
    return 0;
}