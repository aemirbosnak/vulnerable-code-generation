//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <string.h>

#define SHM_SIZE 1024  // Size of shared memory segment

int main() {
    // Create a shared memory segment
    int shm_id = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666);
    if (shm_id == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach the shared memory segment to the address space of the current process
    void *shm_addr = shmat(shm_id, NULL, 0);
    if (shm_addr == (void *)-1) {
        perror("shmat");
        exit(1);
    }

    // Create a child process
    pid_t child_pid = fork();
    if (child_pid < 0) {
        perror("fork");
        exit(1);
    }

    if (child_pid == 0) {  // Child process
        // Write a message to the shared memory segment
        strcpy(shm_addr, "Hello from the child process!");

        // Detach the shared memory segment from the address space of the current process
        if (shmdt(shm_addr) == -1) {
            perror("shmdt");
            exit(1);
        }
    } else {  // Parent process
        // Wait for the child process to finish
        int status;
        wait(&status);

        // Read the message from the shared memory segment
        printf("Message from the child process: %s\n", (char *)shm_addr);

        // Detach the shared memory segment from the address space of the current process
        if (shmdt(shm_addr) == -1) {
            perror("shmdt");
            exit(1);
        }

        // Deallocate the shared memory segment
        if (shmctl(shm_id, IPC_RMID, NULL) == -1) {
            perror("shmctl");
            exit(1);
        }
    }

    return 0;
}