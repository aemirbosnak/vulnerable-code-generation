//GEMINI-pro DATASET v1.0 Category: Arithmetic ; Style: optimized
// A multi-threaded program that calculates the sum of the first n natural numbers.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// The number of threads to create.
#define NUM_THREADS 4

// The number of natural numbers to sum.
#define NUM_NUMBERS 10000000

// The partial sums calculated by each thread.
int partial_sums[NUM_THREADS];

// The mutex used to protect the partial sums.
pthread_mutex_t mutex;

// The thread function.
void *sum_numbers(void *arg) {
    int thread_id = *(int *)arg;

    // Calculate the starting and ending indices of the numbers to be summed by this thread.
    int start_index = thread_id * (NUM_NUMBERS / NUM_THREADS);
    int end_index = (thread_id + 1) * (NUM_NUMBERS / NUM_THREADS);

    // Calculate the partial sum.
    int partial_sum = 0;
    for (int i = start_index; i < end_index; i++) {
        partial_sum += i;
    }

    // Lock the mutex and update the shared partial sum.
    pthread_mutex_lock(&mutex);
    partial_sums[thread_id] = partial_sum;
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main() {
    // Create the threads.
    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        int *thread_id = malloc(sizeof(int));
        *thread_id = i;
        pthread_create(&threads[i], NULL, sum_numbers, thread_id);
    }

    // Wait for the threads to finish.
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Calculate the total sum.
    int total_sum = 0;
    for (int i = 0; i < NUM_THREADS; i++) {
        total_sum += partial_sums[i];
    }

    // Print the total sum.
    printf("The sum of the first %d natural numbers is %d.\n", NUM_NUMBERS, total_sum);

    return 0;
}