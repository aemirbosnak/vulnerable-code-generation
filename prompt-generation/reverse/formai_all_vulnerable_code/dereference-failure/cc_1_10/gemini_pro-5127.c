//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_DISKS 3

// Semaphore to control access to the towers
sem_t towers_mutex;

// Semaphore to signal when a disk has been moved
sem_t disk_moved;

// Tower data structure
typedef struct tower {
    int num_disks;
    int *disks;
} tower_t;

// Function to create a new tower
tower_t *create_tower(int num_disks) {
    tower_t *tower = malloc(sizeof(tower_t));
    tower->num_disks = num_disks;
    tower->disks = malloc(sizeof(int) * num_disks);
    for (int i = 0; i < num_disks; i++) {
        tower->disks[i] = i + 1;
    }
    return tower;
}

// Function to move a disk from one tower to another
void move_disk(tower_t *from, tower_t *to) {
    // Wait for access to the towers
    sem_wait(&towers_mutex);

    // Move the disk from the from tower to the to tower
    to->disks[to->num_disks++] = from->disks[--from->num_disks];

    // Signal that a disk has been moved
    sem_post(&disk_moved);

    // Release access to the towers
    sem_post(&towers_mutex);
}

// Function to solve the Tower of Hanoi problem
void solve_tower_of_hanoi(tower_t *towers, int num_disks, int from, int to, int via) {
    // Base case: no disks to move
    if (num_disks == 0) {
        return;
    }

    // Recursive case: move the top n-1 disks from the from tower to the via tower
    solve_tower_of_hanoi(towers, num_disks - 1, from, via, to);

    // Move the remaining disk from the from tower to the to tower
    move_disk(&towers[from], &towers[to]);

    // Wait for the disk to be moved
    sem_wait(&disk_moved);

    // Recursive case: move the n-1 disks from the via tower to the to tower
    solve_tower_of_hanoi(towers, num_disks - 1, via, to, from);
}

// Function to print the state of the towers
void print_towers(tower_t *towers) {
    for (int i = 0; i < 3; i++) {
        printf("Tower %d: ", i + 1);
        for (int j = 0; j < towers[i].num_disks; j++) {
            printf("%d ", towers[i].disks[j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Initialize the semaphores
    sem_init(&towers_mutex, 0, 1);
    sem_init(&disk_moved, 0, 0);

    // Create the towers
    tower_t towers[3];
    towers[0] = *create_tower(NUM_DISKS);
    towers[1] = *create_tower(0);
    towers[2] = *create_tower(0);

    // Solve the Tower of Hanoi problem
    solve_tower_of_hanoi(towers, NUM_DISKS, 0, 2, 1);

    // Print the state of the towers
    print_towers(towers);

    // Destroy the semaphores
    sem_destroy(&towers_mutex);
    sem_destroy(&disk_moved);

    return 0;
}