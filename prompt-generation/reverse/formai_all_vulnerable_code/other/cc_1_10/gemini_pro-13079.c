//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_DISKS 5

// Semaphores to control access to the rods
sem_t rod1, rod2, rod3;

// Mutex to protect the shared variable 'num_moves'
pthread_mutex_t num_moves_lock;

// Shared variable to keep track of the number of moves
int num_moves = 0;

// Function to move a disk from one rod to another
void move_disk(int disk, int from_rod, int to_rod) {
    // Acquire the semaphores for the 'from' and 'to' rods
    sem_wait(&from_rod);
    sem_wait(&to_rod);

    // Increment the number of moves
    pthread_mutex_lock(&num_moves_lock);
    num_moves++;
    pthread_mutex_unlock(&num_moves_lock);

    // Print the move
    printf("Move disk %d from rod %d to rod %d\n", disk, from_rod, to_rod);

    // Release the semaphores for the 'from' and 'to' rods
    sem_post(&from_rod);
    sem_post(&to_rod);
}

// Function to solve the Tower of Hanoi problem recursively
void tower_of_hanoi(int num_disks, int from_rod, int to_rod, int aux_rod) {
    if (num_disks == 1) {
        // If there is only one disk, move it directly to the 'to' rod
        move_disk(1, from_rod, to_rod);
    } else {
        // Move the top num_disks-1 disks from the 'from' rod to the 'aux' rod
        tower_of_hanoi(num_disks - 1, from_rod, aux_rod, to_rod);

        // Move the remaining disk from the 'from' rod to the 'to' rod
        move_disk(num_disks, from_rod, to_rod);

        // Move the num_disks-1 disks from the 'aux' rod to the 'to' rod
        tower_of_hanoi(num_disks - 1, aux_rod, to_rod, from_rod);
    }
}

// Thread function to solve the Tower of Hanoi problem in a separate thread
void *tower_of_hanoi_thread(void *arg) {
    // Solve the Tower of Hanoi problem
    tower_of_hanoi(NUM_DISKS, 1, 3, 2);

    // Return NULL to indicate successful execution
    return NULL;
}

int main() {
    // Initialize the semaphores
    sem_init(&rod1, 0, 1);
    sem_init(&rod2, 0, 1);
    sem_init(&rod3, 0, 1);

    // Initialize the mutex
    pthread_mutex_init(&num_moves_lock, NULL);

    // Create a new thread to solve the Tower of Hanoi problem
    pthread_t thread;
    pthread_create(&thread, NULL, tower_of_hanoi_thread, NULL);

    // Wait for the thread to finish
    pthread_join(thread, NULL);

    // Print the total number of moves
    printf("Total number of moves: %d\n", num_moves);

    // Destroy the semaphores and mutex
    sem_destroy(&rod1);
    sem_destroy(&rod2);
    sem_destroy(&rod3);
    pthread_mutex_destroy(&num_moves_lock);

    return 0;
}