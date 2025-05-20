//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

// Define the number of disks
#define NUM_DISKS 5

// Define the semaphore
sem_t mutex;

// Define the structure for the thread data
typedef struct {
    int from;
    int to;
    int thread_id;
} thread_data;

// Define the function for the thread
void *move_disk(void *arg) {
    thread_data *data = (thread_data *) arg;
    int from = data->from;
    int to = data->to;
    int thread_id = data->thread_id;

    // Print the thread information
    printf("Thread %d is moving disk %d from peg %d to peg %d\n", thread_id, NUM_DISKS-1, from, to);

    // Move the disk
    printf("Moving disk %d from peg %d to peg %d\n", NUM_DISKS-1, from, to);

    // Update the global variables
    if (to == 0) {
        printf("Disk %d has been moved to peg 0\n", NUM_DISKS-1);
    } else if (from == 0) {
        printf("Disk %d has been moved from peg 0\n", NUM_DISKS-1);
    } else {
        printf("Disk %d has been moved from peg %d to peg %d\n", NUM_DISKS-1, from, to);
    }

    // Release the mutex
    sem_post(&mutex);

    // Exit the thread
    pthread_exit(NULL);
}

// Define the main function
int main() {
    int i;
    pthread_t threads[NUM_DISKS];

    // Initialize the mutex
    sem_init(&mutex, 0, 1);

    // Create the threads
    for (i = 0; i < NUM_DISKS; i++) {
        thread_data *data = malloc(sizeof(thread_data));
        data->from = 0;
        data->to = 2;
        data->thread_id = i+1;
        pthread_create(&threads[i], NULL, move_disk, data);
    }

    // Join the threads
    for (i = 0; i < NUM_DISKS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the mutex
    sem_destroy(&mutex);

    // Exit the program
    return 0;
}