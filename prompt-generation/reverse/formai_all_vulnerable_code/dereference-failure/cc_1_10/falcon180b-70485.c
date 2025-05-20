//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define a global variable to store the maximum value
int max_value = 0;

// Function to calculate the maximum value
void* calculate_max(void* arg) {
    // Get the value from the argument
    int value = *((int*) arg);

    // If the value is greater than the current maximum value, update the maximum value
    if (value > max_value) {
        max_value = value;
    }

    return NULL;
}

// Function to print the maximum value
void print_max() {
    printf("The maximum value is %d\n", max_value);
}

int main() {
    // Initialize the pthread library
    pthread_t threads[10];
    int thread_ids[10];

    // Create 10 threads
    for (int i = 0; i < 10; i++) {
        // Allocate memory for the argument
        int* arg = (int*) malloc(sizeof(int));
        *arg = i * 10;

        // Create the thread and store the ID in the array
        pthread_create(&threads[i], NULL, calculate_max, arg);
        thread_ids[i] = i * 10;
    }

    // Join the threads
    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the maximum value
    print_max();

    return 0;
}