//GPT-4o-mini DATASET v1.0 Category: Threading Library Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_NUM 30  // Maximum Fibonacci number to calculate
#define THREAD_COUNT 3 // Number of threads

// Shared data structure
typedef struct {
    int start;
    int end;
    int* results;
    pthread_mutex_t* mutex;
} ThreadData;

// Function to compute Fibonacci number
int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Thread function to compute Fibonacci sequences
void* compute_fibonacci(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    for (int i = data->start; i <= data->end; i++) {
        int fib = fibonacci(i);
        
        // Lock mutex to safely update shared results array
        pthread_mutex_lock(data->mutex);
        data->results[i] = fib;
        pthread_mutex_unlock(data->mutex);
    }
    return NULL;
}

int main() {
    pthread_t threads[THREAD_COUNT];
    pthread_mutex_t mutex;
    int* results = calloc(MAX_NUM + 1, sizeof(int)); // Result array for Fibonacci numbers
    ThreadData thread_data[THREAD_COUNT];

    // Initialize mutex
    pthread_mutex_init(&mutex, NULL);

    // Create threads
    int range = MAX_NUM / THREAD_COUNT;
    for (int i = 0; i < THREAD_COUNT; i++) {
        thread_data[i].start = i * range;
        thread_data[i].end = (i + 1) * range - 1;
        if (i == THREAD_COUNT - 1) {
            thread_data[i].end = MAX_NUM; // Last thread handles remainder
        }
        thread_data[i].results = results;
        thread_data[i].mutex = &mutex;

        pthread_create(&threads[i], NULL, compute_fibonacci, (void*)&thread_data[i]);
    }

    // Join threads
    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print results
    printf("Fibonacci numbers up to %d:\n", MAX_NUM);
    for (int i = 0; i <= MAX_NUM; i++) {
        printf("Fibonacci(%d) = %d\n", i, results[i]);
    }

    // Clean up
    free(results);
    pthread_mutex_destroy(&mutex);
    return 0;
}