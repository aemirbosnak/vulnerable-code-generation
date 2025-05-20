//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 10

// Structure to store the Fibonacci numbers
typedef struct {
    int fib_num;
    pthread_mutex_t lock;
} fib_num_t;

// Array of Fibonacci numbers
fib_num_t fib_nums[NUM_THREADS];

// Mutex to protect the Fibonacci numbers
pthread_mutex_t fib_nums_lock;

// Thread function to calculate the Fibonacci numbers
void *calc_fib_num(void *arg) {
    int index = *(int *)arg;
    pthread_mutex_lock(&fib_nums_lock);
    if (index < 2) {
        fib_nums[index].fib_num = index;
    } else {
        fib_nums[index].fib_num = fib_nums[index - 1].fib_num + fib_nums[index - 2].fib_num;
    }
    pthread_mutex_unlock(&fib_nums_lock);
    pthread_exit(NULL);
}

// Main function
int main() {
    // Initialize the mutexes
    pthread_mutex_init(&fib_nums_lock, NULL);
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_mutex_init(&fib_nums[i].lock, NULL);
    }

    // Create the threads
    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        int *index = malloc(sizeof(int));
        *index = i;
        pthread_create(&threads[i], NULL, calc_fib_num, index);
    }

    // Join the threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the Fibonacci numbers
    for (int i = 0; i < NUM_THREADS; i++) {
        printf("fib_nums[%d]: %d\n", i, fib_nums[i].fib_num);
    }

    // Destroy the mutexes
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_mutex_destroy(&fib_nums[i].lock);
    }
    pthread_mutex_destroy(&fib_nums_lock);

    return 0;
}