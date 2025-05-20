//Falcon2-11B DATASET v1.0 Category: Task Scheduler ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4

// Define a function for each task
void* task1(void* arg) {
    // Do something in task 1
    printf("Task 1 running...\n");
    pthread_exit(NULL);
}

void* task2(void* arg) {
    // Do something in task 2
    printf("Task 2 running...\n");
    pthread_exit(NULL);
}

void* task3(void* arg) {
    // Do something in task 3
    printf("Task 3 running...\n");
    pthread_exit(NULL);
}

void* task4(void* arg) {
    // Do something in task 4
    printf("Task 4 running...\n");
    pthread_exit(NULL);
}

// Main function to create and start the threads
int main() {
    pthread_t threads[NUM_THREADS];
    int i;

    // Create and start each thread
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, task1, NULL);
        pthread_create(&threads[i+1], NULL, task2, NULL);
        pthread_create(&threads[i+2], NULL, task3, NULL);
        pthread_create(&threads[i+3], NULL, task4, NULL);
    }

    // Wait for all threads to finish
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}