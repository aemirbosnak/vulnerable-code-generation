//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHM_SIZE 1024  // size of shared memory segment

int main() {
    // Create a shared memory segment
    int shmid = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach the shared memory segment to the current process
    char *shm_addr = shmat(shmid, NULL, 0);
    if (shm_addr == (char *)-1) {
        perror("shmat");
        exit(1);
    }

    // Create a child process
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) {  // Child process
        // Write to the shared memory segment
        strcpy(shm_addr, "Hello from the child process!");

        // Detach the shared memory segment from the current process
        if (shmdt(shm_addr) == -1) {
            perror("shmdt");
            exit(1);
        }

        exit(0);
    } else {  // Parent process
        // Wait for the child process to finish
        int status;
        waitpid(pid, &status, 0);

        // Read from the shared memory segment
        printf("Message from the child process: %s\n", shm_addr);

        // Detach the shared memory segment from the current process
        if (shmdt(shm_addr) == -1) {
            perror("shmdt");
            exit(1);
        }

        // Destroy the shared memory segment
        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            perror("shmctl");
            exit(1);
        }
    }

    return 0;
}