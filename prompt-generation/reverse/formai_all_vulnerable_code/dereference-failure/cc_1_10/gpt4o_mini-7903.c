//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

// Structure to hold arguments for each thread
typedef struct {
    int n; // Fibonacci index
    long long *result; // Pointer to store the result
} ThreadArgs;

// Function to compute Fibonacci number using dynamic programming
long long fibonacci(int n) {
    if (n < 0) return -1; // Error case
    if (n <= 1) return n; // Base cases

    long long *fib = (long long *)malloc((n + 1) * sizeof(long long));
    if (fib == NULL) return -1; // Memory allocation failure

    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    long long result = fib[n];
    free(fib); // Free allocated memory
    return result;
}

// Thread function to calculate Fibonacci number
void *thread_fibonacci(void *arg) {
    ThreadArgs *args = (ThreadArgs *)arg;
    *(args->result) = fibonacci(args->n);
    pthread_exit(NULL);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <n1> <n2> ... <nk>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int num_threads = argc - 1;
    pthread_t threads[num_threads];
    ThreadArgs thread_args[num_threads];
    long long results[num_threads];

    // Create threads to compute Fibonacci numbers
    for (int i = 0; i < num_threads; i++) {
        thread_args[i].n = atoi(argv[i + 1]);
        thread_args[i].result = &results[i];

        if (pthread_create(&threads[i], NULL, thread_fibonacci, (void *)&thread_args[i]) != 0) {
            fprintf(stderr, "Error creating thread %d\n", i);
            return EXIT_FAILURE;
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Output the results
    printf("Fibonacci results:\n");
    for (int i = 0; i < num_threads; i++) {
        printf("F(%d) = %lld\n", thread_args[i].n, results[i]);
    }

    return EXIT_SUCCESS;
}