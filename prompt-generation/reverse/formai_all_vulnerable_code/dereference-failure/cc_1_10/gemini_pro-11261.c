//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of Fibonacci numbers to generate
#define MAX_FIB 100

// Define the thread structure
typedef struct {
    int start;
    int end;
} thread_data_t;

// Define the global array to store the Fibonacci numbers
int fib[MAX_FIB];

// Define the mutex lock to protect the global array
pthread_mutex_t fib_lock;

// Define the thread function
void *fib_thread(void *arg) {
    // Get the thread data
    thread_data_t *data = (thread_data_t *)arg;

    // Calculate the Fibonacci numbers
    for (int i = data->start; i < data->end; i++) {
        if (i == 0) {
            fib[i] = 0;
        } else if (i == 1) {
            fib[i] = 1;
        } else {
            // Acquire the mutex lock
            pthread_mutex_lock(&fib_lock);

            // Calculate the Fibonacci number
            fib[i] = fib[i - 1] + fib[i - 2];

            // Release the mutex lock
            pthread_mutex_unlock(&fib_lock);
        }
    }

    // Return NULL to indicate success
    return NULL;
}

// Define the main function
int main() {
    // Initialize the mutex lock
    pthread_mutex_init(&fib_lock, NULL);

    // Create the thread pool
    pthread_t threads[4];

    // Divide the work into four equal parts
    int part = MAX_FIB / 4;

    // Create the threads
    for (int i = 0; i < 4; i++) {
        thread_data_t data = {
            .start = i * part,
            .end = (i + 1) * part
        };

        pthread_create(&threads[i], NULL, fib_thread, &data);
    }

    // Join the threads
    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the Fibonacci numbers
    for (int i = 0; i < MAX_FIB; i++) {
        printf("%d ", fib[i]);
    }

    printf("\n");

    // Destroy the mutex lock
    pthread_mutex_destroy(&fib_lock);

    return 0;
}