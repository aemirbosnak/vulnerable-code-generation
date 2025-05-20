//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/mman.h>

#define SIZE 10

int main() {
    int shmid, i;
    char *shm;
    pid_t pid;

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, SIZE * sizeof(char), IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory segment to process
    shm = (char *) shmat(shmid, NULL, 0);
    if (shm == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Fill shared memory segment with data
    for (i = 0; i < SIZE; i++) {
        shm[i] = i;
    }

    // Fork a child process
    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process

        // Attach shared memory segment to child process
        shm = (char *) shmat(shmid, NULL, 0);
        if (shm == (char *) -1) {
            perror("shmat");
            exit(1);
        }

        // Print data in shared memory segment
        for (i = 0; i < SIZE; i++) {
            printf("%d ", shm[i]);
        }

        // Detach shared memory segment from child process
        if (shmdt(shm) == -1) {
            perror("shmdt");
            exit(1);
        }

        // Exit child process
        exit(0);
    } else {
        // Parent process

        // Wait for child process to finish
        wait(NULL);

        // Detach shared memory segment from parent process
        if (shmdt(shm) == -1) {
            perror("shmdt");
            exit(1);
        }

        // Exit parent process
        exit(0);
    }
}