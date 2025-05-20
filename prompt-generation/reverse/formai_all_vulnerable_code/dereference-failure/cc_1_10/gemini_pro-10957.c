//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

// Declare the shared memory segment.
int *shared_memory;

// Define the key for the shared memory segment.
#define SHM_KEY 1234

int main() {
    // Create the shared memory segment.
    int shm_id = shmget(SHM_KEY, sizeof(int), IPC_CREAT | 0666);
    if (shm_id == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // Attach the shared memory segment to the current process.
    shared_memory = (int *)shmat(shm_id, NULL, 0);
    if (shared_memory == (void *)-1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    // Initialize the shared memory segment to 0.
    *shared_memory = 0;

    // Create a child process.
    pid_t child_pid = fork();
    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    // Increment the shared memory segment in the child process.
    if (child_pid == 0) {
        (*shared_memory)++;
        printf("Child process incremented the shared memory segment to %d.\n", *shared_memory);
    }
    // Decrement the shared memory segment in the parent process.
    else {
        (*shared_memory)--;
        printf("Parent process decremented the shared memory segment to %d.\n", *shared_memory);
    }

    // Detach the shared memory segment from the current process.
    if (shmdt(shared_memory) == -1) {
        perror("shmdt");
        exit(EXIT_FAILURE);
    }

    // Remove the shared memory segment.
    if (shmctl(shm_id, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}