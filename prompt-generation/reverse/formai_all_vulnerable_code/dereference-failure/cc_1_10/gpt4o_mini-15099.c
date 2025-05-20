//GPT-4o-mini DATASET v1.0 Category: Threading Library Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#define NUM_THREADS 5
#define BUFSIZE 100

// Create a structure to hold thread data
typedef struct {
    int thread_id;
    char message[BUFSIZE];
} ThreadData;

// Global variables
pthread_mutex_t print_mutex;

// Function that each thread will run
void* perform_work(void* data) {
    ThreadData* thread_data = (ThreadData*)data;
    int thread_id = thread_data->thread_id;

    // Simulate doing some work
    sleep(random() % 3); // Sleep for a random duration between 0-2 seconds

    // Lock the mutex before printing
    pthread_mutex_lock(&print_mutex);
    printf("Thread %d: %s\n", thread_id, thread_data->message);
    pthread_mutex_unlock(&print_mutex);

    free(thread_data);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    pthread_mutex_init(&print_mutex, NULL);
    srand(time(NULL)); // Seed for random generator

    // Create and start threads
    for (int i = 0; i < NUM_THREADS; i++) {
        ThreadData* thread_data = malloc(sizeof(ThreadData));
        thread_data->thread_id = i;
        snprintf(thread_data->message, BUFSIZE, "Hello from thread %d!", i);

        if (pthread_create(&threads[i], NULL, perform_work, (void*)thread_data)) {
            fprintf(stderr, "Error creating thread %d\n", i);
            return 1;
        }
    }

    // Wait for all threads to complete
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Clean up mutex
    pthread_mutex_destroy(&print_mutex);
    
    printf("All threads completed successfully!\n");
    return 0;
}