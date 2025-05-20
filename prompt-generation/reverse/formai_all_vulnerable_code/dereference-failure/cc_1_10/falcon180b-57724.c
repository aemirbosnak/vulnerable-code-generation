//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 10

int main() {
    int shmid;
    int *shm;
    pid_t pid;

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, SIZE * sizeof(int), IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Failed to create shared memory segment.\n");
        exit(1);
    }

    // Attach shared memory segment
    shm = shmat(shmid, NULL, 0);
    if (shm == (void *) - 1) {
        printf("Failed to attach shared memory segment.\n");
        exit(1);
    }

    // Initialize shared memory with random values
    for (int i = 0; i < SIZE; i++) {
        shm[i] = rand();
    }

    // Fork child process
    pid = fork();
    if (pid == -1) {
        printf("Failed to fork child process.\n");
        exit(1);
    } else if (pid == 0) {
        // Child process

        // Detach shared memory segment
        shmdt(shm);

        // Exit child process
        exit(0);
    } else {
        // Parent process

        // Wait for child process to exit
        wait(NULL);

        // Detach shared memory segment
        shmdt(shm);

        // Print shared memory values
        printf("Shared memory values:\n");
        for (int i = 0; i < SIZE; i++) {
            printf("%d ", shm[i]);
        }
        printf("\n");
    }

    return 0;
}