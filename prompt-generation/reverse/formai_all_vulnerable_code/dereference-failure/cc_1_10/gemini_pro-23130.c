//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024  // Size of shared memory segment

int main() {
    // Create a shared memory segment
    int shm_id = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666);
    if (shm_id == -1) {
        perror("shmget");
        return EXIT_FAILURE;
    }

    // Attach the shared memory segment to the current process
    void *shm_ptr = shmat(shm_id, NULL, 0);
    if (shm_ptr == (void *)-1) {
        perror("shmat");
        return EXIT_FAILURE;
    }

    // Initialize shared memory
    memset(shm_ptr, 0, SHM_SIZE);

    // Create a child process
    pid_t child_pid = fork();
    if (child_pid == -1) {
        perror("fork");
        return EXIT_FAILURE;
    }

    if (child_pid == 0) {  // Child process
        // Write to shared memory
        sprintf(shm_ptr, "Hello from child process!");

        // Detach shared memory from current process
        if (shmdt(shm_ptr) == -1) {
            perror("shmdt");
            return EXIT_FAILURE;
        }
    } else {  // Parent process
        // Wait for child process to write to shared memory
        while (strcmp(shm_ptr, "") == 0) {
            sleep(1);
        }

        // Read from shared memory
        printf("Message from child process: %s\n", (char *)shm_ptr);

        // Detach shared memory from current process
        if (shmdt(shm_ptr) == -1) {
            perror("shmdt");
            return EXIT_FAILURE;
        }

        // Remove shared memory segment
        if (shmctl(shm_id, IPC_RMID, NULL) == -1) {
            perror("shmctl");
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}