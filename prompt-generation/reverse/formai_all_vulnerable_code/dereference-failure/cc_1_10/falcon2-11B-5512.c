//Falcon2-11B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Global variables
int num_passengers = 0;
int num_bags = 0;
int num_bags_per_passenger = 1;
int total_bags = 0;
int num_threads = 1;
pthread_mutex_t mutex;
pthread_cond_t cond;

// Thread function
void* handle_baggage(void* arg) {
    int thread_id = *(int*)arg;
    int bags_to_handle = num_passengers * num_bags_per_passenger;
    int bags_handled = 0;

    // Wait for bags to handle
    pthread_mutex_lock(&mutex);
    while (bags_to_handle > bags_handled) {
        pthread_cond_wait(&cond, &mutex);
    }
    pthread_mutex_unlock(&mutex);

    // Print thread ID and number of bags handled
    printf("Thread %d handled %d bags\n", thread_id, bags_handled);

    return NULL;
}

// Main function
int main() {
    // Initialize global variables
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);
    num_passengers = 5;
    num_bags = 10;
    num_bags_per_passenger = 2;
    total_bags = num_passengers * num_bags_per_passenger;
    num_threads = 3;

    // Create threads
    pthread_t threads[num_threads];
    for (int i = 0; i < num_threads; i++) {
        int thread_id = i;
        pthread_create(&threads[i], NULL, handle_baggage, &thread_id);
    }

    // Wait for threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Cleanup
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}