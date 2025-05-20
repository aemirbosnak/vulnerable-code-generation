//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_TERMS 20

// Shared resource array for Fibonacci sequence
long long fib[MAX_TERMS];
// Mutex for synchronization
pthread_mutex_t mutex;

// Function to calculate Fibonacci numbers
void* calculate_fibonacci(void* arg) {
    int n = *(int*)arg;
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
        sleep(1); // Sleep for a second to visualize the calculation
    }

    // Signal that calculation is complete
    pthread_mutex_lock(&mutex);
    printf("Fibonacci calculation complete.\n");
    pthread_mutex_unlock(&mutex);
    return NULL;
}

// Function to visualize the Fibonacci sequence
void* visualize_fibonacci(void* arg) {
    int n = *(int*)arg;

    for (int i = 0; i < n; i++) {
        pthread_mutex_lock(&mutex);
        printf("Fibonacci(%d) = %lld\n", i, fib[i]);
        pthread_mutex_unlock(&mutex);
        sleep(1); // Sleep for a second for better visualization
    }
    
    return NULL;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number_of_terms>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int n = atoi(argv[1]);
    if (n <= 0 || n > MAX_TERMS) {
        fprintf(stderr, "Please provide a positive integer between 1 and %d.\n", MAX_TERMS);
        exit(EXIT_FAILURE);
    }

    // Initialize the mutex
    pthread_mutex_init(&mutex, NULL);

    pthread_t calc_thread, vis_thread;

    // Create threads for calculation and visualization
    pthread_create(&calc_thread, NULL, calculate_fibonacci, &n);
    pthread_create(&vis_thread, NULL, visualize_fibonacci, &n);
    
    // Wait for both threads to complete
    pthread_join(calc_thread, NULL);
    pthread_join(vis_thread, NULL);
    
    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}