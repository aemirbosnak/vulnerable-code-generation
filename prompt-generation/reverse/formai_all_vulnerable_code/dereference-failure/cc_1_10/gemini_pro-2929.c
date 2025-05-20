//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024  // Size of shared memory segment

int main() {
    // Create a shared memory segment
    int shmid = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach the shared memory segment to the current process
    void *shmptr = shmat(shmid, NULL, 0);
    if (shmptr == (void *)-1) {
        perror("shmat");
        exit(1);
    }

    // Initialize the shared memory segment with a value
    int *shm = (int *)shmptr;
    *shm = 0;

    // Create a child process
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    }

    // Child process increments the value in shared memory
    if (pid == 0) {
        *shm = *shm + 1;
        printf("Child process: incremented the value to %d\n", *shm);
        exit(0);
    }

    // Parent process waits for child process to finish
    int status;
    wait(&status);

    // Parent process prints the value in shared memory
    printf("Parent process: value in shared memory is %d\n", *shm);

    // Detach the shared memory segment from the current process
    shmdt(shmptr);

    // Destroy the shared memory segment
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}