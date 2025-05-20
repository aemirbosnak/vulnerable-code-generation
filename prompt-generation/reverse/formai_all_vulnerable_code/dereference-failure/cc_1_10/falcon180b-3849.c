//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SIZE 1024
#define KEY 1234

int main() {
    int shmid;
    char *shmptr;
    pid_t pid;

    // Create shared memory segment
    shmid = shmget(KEY, SIZE, IPC_CREAT | 0777);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory segment
    shmptr = shmat(shmid, NULL, 0);
    if (shmptr == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Initialize shared data
    strcpy(shmptr, "Hello, World!");

    // Fork child process
    pid = fork();
    if (pid == 0) {
        // Child process

        // Detach shared memory segment
        shmdt(shmptr);

        // Modify shared data
        shmptr = shmat(shmid, NULL, 0);
        strcpy(shmptr, "Child says Hi!");

        // Print modified data
        printf("Child: %s\n", shmptr);

        // Detach shared memory segment
        shmdt(shmptr);

        // Exit child process
        exit(0);
    } else {
        // Parent process

        // Wait for child process to finish
        wait(NULL);

        // Attach shared memory segment
        shmptr = shmat(shmid, NULL, 0);

        // Print modified data
        printf("Parent: %s\n", shmptr);

        // Detach shared memory segment
        shmdt(shmptr);

        // Delete shared memory segment
        shmctl(shmid, IPC_RMID, NULL);

        // Exit parent process
        exit(0);
    }

    return 0;
}