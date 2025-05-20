//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>

// Shared memory segment
int *shared_memory;

int main() {
    // Create a shared memory segment
    int shmid = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach the shared memory segment to the current process
    shared_memory = (int *)shmat(shmid, NULL, 0);
    if (shared_memory == (void *)-1) {
        perror("shmat");
        exit(1);
    }

    // Initialize the shared memory
    *shared_memory = 0;

    // Fork a child process
    pid_t child_pid = fork();
    if (child_pid == -1) {
        perror("fork");
        exit(1);
    }

    // Parent process
    if (child_pid > 0) {
        // Wait for the child process to finish
        wait(NULL);

        // Print the shared memory value
        printf("Parent: The shared memory value is %d\n", *shared_memory);

        // Detach the shared memory segment from the current process
        if (shmdt(shared_memory) == -1) {
            perror("shmdt");
            exit(1);
        }

        // Remove the shared memory segment
        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            perror("shmctl");
            exit(1);
        }
    }
    // Child process
    else {
        // Increment the shared memory value
        *shared_memory += 1;

        // Print the shared memory value
        printf("Child: The shared memory value is %d\n", *shared_memory);

        // Detach the shared memory segment from the current process
        if (shmdt(shared_memory) == -1) {
            perror("shmdt");
            exit(1);
        }
    }

    return 0;
}