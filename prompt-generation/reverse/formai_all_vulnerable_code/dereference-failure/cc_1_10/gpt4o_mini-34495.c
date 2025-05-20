//GPT-4o-mini DATASET v1.0 Category: Threading Library Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_THREADS 5

// Struct to hold thread arguments
typedef struct {
    int thread_id;
    int n;
} thread_arg;

// Function to calculate Fibonacci number
unsigned long long fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    unsigned long long a = 0, b = 1;
    unsigned long long fib;
    for (int i = 2; i <= n; i++) {
        fib = a + b;
        a = b;
        b = fib;
    }
    return fib;
}

// Thread function
void *calculate_fibonacci(void *arg) {
    thread_arg *targ = (thread_arg *)arg;
    unsigned long long result = fibonacci(targ->n);
    printf("Thread %d: Fibonacci of %d is %llu\n", targ->thread_id, targ->n, result);
    free(arg); // Free the allocated memory
    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    int rc;

    printf("Starting Fibonacci Calculation with %d threads...\n", MAX_THREADS);

    for (int i = 0; i < MAX_THREADS; i++) {
        thread_arg *targ = (thread_arg *)malloc(sizeof(thread_arg));
        targ->thread_id = i + 1;
        targ->n = i + 5; // Calculate Fibonacci for different values: 5, 6, 7, 8, 9

        rc = pthread_create(&threads[i], NULL, calculate_fibonacci, (void *)targ);
        if (rc) {
            fprintf(stderr, "Error: Unable to create thread %d, return code: %d\n", i + 1, rc);
            exit(EXIT_FAILURE);
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < MAX_THREADS; i++) {
        rc = pthread_join(threads[i], NULL);
        if (rc) {
            fprintf(stderr, "Error: Unable to join thread %d, return code: %d\n", i + 1, rc);
            exit(EXIT_FAILURE);
        }
    }

    printf("All threads completed successfully.\n");
    return 0;
}