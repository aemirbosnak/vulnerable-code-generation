//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024  // Size of shared memory segment

int main() {
    // Create a shared memory segment
    int shm_id = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666);
    if (shm_id == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach the shared memory segment to the current process
    void *shm_ptr = shmat(shm_id, NULL, 0);
    if (shm_ptr == (void *)-1) {
        perror("shmat");
        exit(1);
    }

    // Create a child process
    pid_t child_pid = fork();
    if (child_pid == -1) {
        perror("fork");
        exit(1);
    }

    // Parent process
    if (child_pid > 0) {
        // Write to shared memory
        strcpy(shm_ptr, "Hello from parent");

        // Wait for child process to finish
        wait(NULL);

        // Read from shared memory
        printf("Child process wrote: %s\n", shm_ptr);

        // Detach shared memory segment from current process
        shmdt(shm_ptr);

        // Remove shared memory segment
        shmctl(shm_id, IPC_RMID, NULL);
    }
    // Child process
    else {
        // Read from shared memory
        printf("Parent process wrote: %s\n", shm_ptr);

        // Write to shared memory
        strcpy(shm_ptr, "Hello from child");

        // Detach shared memory segment from current process
        shmdt(shm_ptr);
    }

    return 0;
}