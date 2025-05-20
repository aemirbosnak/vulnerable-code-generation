//GPT-4o-mini DATASET v1.0 Category: Threading Library Implementation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 4

typedef struct {
    int start;
    int end;
    unsigned long long result;
} ThreadData;

void* calculate_factorial(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    unsigned long long factorial = 1;
    for (int i = data->start; i <= data->end; i++) {
        factorial *= i;
    }
    data->result = factorial;
    return NULL;
}

unsigned long long distributed_factorial(int n) {
    pthread_t threads[NUM_THREADS];
    ThreadData thread_data[NUM_THREADS];
    unsigned long long total_factorial = 1;

    int range_per_thread = n / NUM_THREADS;
    int leftover = n % NUM_THREADS;

    int start = 1;
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data[i].start = start;
        // Assign the end based on current start and range per thread.
        thread_data[i].end = start + range_per_thread - 1;
        
        if (i == NUM_THREADS - 1) {
            thread_data[i].end += leftover; // Last thread handles the leftover
        }
        
        thread_data[i].result = 1; // Initialize result for this thread
        pthread_create(&threads[i], NULL, calculate_factorial, &thread_data[i]);
        start = thread_data[i].end + 1; // Update start for the next thread
    }

    // Join the threads and accumulate the results
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
        total_factorial *= thread_data[i].result; // Combine the factorial from each thread
    }

    return total_factorial;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int n = atoi(argv[1]);
    if (n < 0) {
        fprintf(stderr, "Please enter a non-negative integer.\n");
        return EXIT_FAILURE;
    }

    unsigned long long factorial = distributed_factorial(n);
    printf("Factorial of %d is %llu\n", n, factorial);
    
    return EXIT_SUCCESS;
}