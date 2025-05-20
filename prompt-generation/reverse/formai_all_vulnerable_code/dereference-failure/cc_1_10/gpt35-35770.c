//FormAI DATASET v1.0 Category: Interprocess communication ; Style: energetic
// Let's create an IP communication program in C
// This program demonstrates how two processes can communicate with each other
// using shared memory

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

// Define the size of shared memory
#define SHM_SIZE 1024

int main() {

    // First, create a key for the shared memory segment
    key_t key = ftok(".", 'x');

    // Check if key creation was successful
    if (key == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    // Next, allocate the shared memory segment
    int shm_id = shmget(key, SHM_SIZE, IPC_CREAT | 0666);

    // Check if allocation was successful
    if (shm_id == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // Now, attach to the shared memory segment
    char *shared_memory = (char*) shmat(shm_id, NULL, 0);

    // Check if attachment was successful
    if (shared_memory == (char*) -1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    // Let's communicate with the other process now

    // Start an infinite loop
    while(1) {
        printf("\nEnter data to send to the other process: ");
        fgets(shared_memory, SHM_SIZE, stdin); // read input from user

        // Let's notify the other process that we have written to shared memory
        shared_memory[0] = '*';

        // Wait until the other process has read from shared memory
        while (shared_memory[0] == '*') {
            sleep(1); // busy waiting for one second
        }

        // The other process has read from shared memory, so let's continue
        printf("Data received from the other process: %s\n", shared_memory);
    }

    // Finally, detach from the shared memory segment
    if (shmdt(shared_memory) == -1) {
        perror("shmdt");
        exit(EXIT_FAILURE);
    }

    // Destroy the shared memory segment
    if (shmctl(shm_id, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(EXIT_FAILURE);
    }

    return 0;
}