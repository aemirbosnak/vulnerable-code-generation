//FormAI DATASET v1.0 Category: Interprocess communication ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

// Define the shared memory size
#define SHM_SIZE 1024

// Define the key for the shared memory
#define SHM_KEY 0x12345

int main() {

    // Create shared memory ID
    int shm_id = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shm_id == -1) {
        perror("Failed to create shared memory.\n");
        exit(EXIT_FAILURE);
    }

    // Attach to the shared memory
    char *shared_mem = shmat(shm_id, NULL, 0);
    if (shared_mem == (char *) -1) {
        perror("Failed to attach to shared memory.\n");
        exit(EXIT_FAILURE);
    }
    // Initialize shared memory to 0
    memset(shared_mem, 0, SHM_SIZE);

    // Fork a process
    pid_t pid = fork();

    if (pid < 0) {
        perror("Failed to fork.\n");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        printf("Enter a message to send to the parent process:\n");
        fgets(shared_mem, SHM_SIZE, stdin);

        // Detach from shared memory
        if (shmdt(shared_mem) == -1) {
            perror("Failed to detach from shared memory.\n");
            exit(EXIT_FAILURE);
        }

        // Exit child process
        exit(EXIT_SUCCESS);
    } else {
        // Parent process
        printf("Waiting for message from child process...\n");
        wait(NULL);

        // Read message from shared memory
        printf("Received message from child process: %s", shared_mem);

        // Detach from shared memory
        if (shmdt(shared_mem) == -1) {
            perror("Failed to detach from shared memory.\n");
            exit(EXIT_FAILURE);
        }

        // Remove shared memory
        if (shmctl(shm_id, IPC_RMID, NULL) == -1) {
            perror("Failed to remove shared memory.\n");
            exit(EXIT_FAILURE);
        }

        // Exit parent process
        exit(EXIT_SUCCESS);
    }
}