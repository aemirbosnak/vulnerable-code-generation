//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_DISKS 10

typedef struct {
    int n;          // number of disks
    char source;   // source peg
    char target;   // target peg
    char auxiliary; // auxiliary peg
} TowerArgs;

// Function to simulate moving a disk
void* move_disk(void* args) {
    TowerArgs* targs = (TowerArgs*) args;
    printf("Moving disk from %c to %c\n", targs->source, targs->target);
    sleep(1); // Simulate time taken to move a disk
    free(targs);
    return NULL;
}

// Recursive function to solve Tower of Hanoi
void tower_of_hanoi(int n, char source, char target, char auxiliary) {
    if (n == 1) {
        // Create arguments and start a new thread for moving the disk
        TowerArgs *args = malloc(sizeof(TowerArgs));
        args->n = 1;
        args->source = source;
        args->target = target;
        args->auxiliary = auxiliary;
        
        pthread_t thread;
        pthread_create(&thread, NULL, move_disk, args);
        pthread_join(thread, NULL);
        return;
    }

    // Move n-1 disks from source to auxiliary using target as auxiliary
    tower_of_hanoi(n - 1, source, auxiliary, target);

    // Move the remaining disk from source to target
    TowerArgs *args = malloc(sizeof(TowerArgs));
    args->n = n; // Not really used, but for consistency
    args->source = source;
    args->target = target;
    args->auxiliary = auxiliary;

    pthread_t thread;
    pthread_create(&thread, NULL, move_disk, args);
    pthread_join(thread, NULL);

    // Move n-1 disks from auxiliary to target using source as auxiliary
    tower_of_hanoi(n - 1, auxiliary, target, source);
}

int main() {
    int n;

    printf("Enter the number of disks (1-%d): ", MAX_DISKS);
    scanf("%d", &n);

    if (n < 1 || n > MAX_DISKS) {
        fprintf(stderr, "Invalid number of disks. Please enter a number between 1 and %d.\n", MAX_DISKS);
        return 1;
    }

    printf("Starting Tower of Hanoi with %d disks.\n", n);
    tower_of_hanoi(n, 'A', 'C', 'B'); // A, B and C are names of rods
    printf("Tower of Hanoi solution completed.\n");

    return 0;
}