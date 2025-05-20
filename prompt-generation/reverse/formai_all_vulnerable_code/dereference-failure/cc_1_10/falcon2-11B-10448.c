//Falcon2-11B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of threads
#define NUM_THREADS 10

// Define the thread data structure
typedef struct {
    int id;
    int priority;
} Thread;

// Function to sort threads based on their random number
int compare_threads(const void *a, const void *b) {
    Thread *t1 = (Thread *)a;
    Thread *t2 = (Thread *)b;

    return t1->priority - t2->priority;
}

// Function to generate random numbers for threads
void generate_rand_numbers(Thread *threads, int num_threads) {
    srand(time(NULL));

    // Generate random numbers for each thread
    for (int i = 0; i < num_threads; i++) {
        threads[i].id = i;
        threads[i].priority = rand() % 1000;
    }
}

// Function to schedule threads
Thread *schedule(Thread threads[], int num_threads) {
    // Sort threads based on their random numbers
    qsort(threads, num_threads, sizeof(Thread), compare_threads);

    // Create a new array to store sorted threads
    Thread *sorted_arr = (Thread *)malloc(num_threads * sizeof(Thread));

    // Copy sorted threads into the new array
    for (int i = 0; i < num_threads; i++) {
        sorted_arr[i] = threads[i];
    }

    return sorted_arr;
}

int main() {
    Thread threads[NUM_THREADS];

    // Generate random numbers for threads
    generate_rand_numbers(threads, NUM_THREADS);

    // Schedule threads
    Thread *sorted_arr = schedule(threads, NUM_THREADS);

    // Print sorted threads
    for (int i = 0; i < NUM_THREADS; i++) {
        printf("%d ", sorted_arr[i].id);
    }
    printf("\n");

    // Schedule threads again in a loop
    while (1) {
        srand(time(NULL));
        generate_rand_numbers(threads, NUM_THREADS);
        sorted_arr = schedule(threads, NUM_THREADS);
        for (int i = 0; i < NUM_THREADS; i++) {
            printf("%d ", sorted_arr[i].id);
        }
        printf("\n");
    }

    return 0;
}