//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHM_SIZE 1024

int main() {
    // Create a shared memory segment.
    int shm_id = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666);
    if (shm_id < 0) {
        perror("shmget");
        exit(1);
    }

    // Attach the shared memory segment to the current process.
    void *shm_ptr = shmat(shm_id, NULL, 0);
    if (shm_ptr == (void *)-1) {
        perror("shmat");
        exit(1);
    }

    // Create a child process.
    pid_t child_pid = fork();
    if (child_pid < 0) {
        perror("fork");
        exit(1);
    }

    // The child process writes to the shared memory segment.
    if (child_pid == 0) {
        strcpy(shm_ptr, "Hello from the child process!");
        exit(0);
    }

    // The parent process waits for the child process to finish.
    int status;
    wait(&status);

    // The parent process reads from the shared memory segment.
    printf("The child process wrote: %s\n", shm_ptr);

    // Detach the shared memory segment from the current process.
    if (shmdt(shm_ptr) < 0) {
        perror("shmdt");
        exit(1);
    }

    // Destroy the shared memory segment.
    if (shmctl(shm_id, IPC_RMID, NULL) < 0) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}