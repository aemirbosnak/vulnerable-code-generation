//FormAI DATASET v1.0 Category: Interprocess communication ; Style: detailed
// A unique C Interprocess Communication example program
//
// This program demonstrates Interprocess Communication using
// shared memory and semaphores.
//
// In this program, two processes are created - parent and child.
// The parent process creates a shared memory block and initializes it
// with some data. The child process attaches to the shared memory block
// and reads the data.
//
// This program also uses semaphores to synchronize access to the shared
// memory block.
//
// Author: Jane Doe

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define SHM_SIZE 1024

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

void error(char* message) {
    fprintf(stderr, "%s\n", message);
    exit(EXIT_FAILURE);
}

int main() {
    int shmid;
    key_t key;
    char* shm;
    union semun sem_un;
    struct sembuf sem_op[1];

    // Generate a unique key for the shared memory block.
    if ((key = ftok("shared_mem_example.c", 'R')) == -1) {
        error("Unable to generate a key for the shared memory block.");
    }

    // Create the shared memory block.
    if ((shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666)) == -1) {
        error("Unable to create the shared memory block.");
    }

    // Attach to the shared memory block.
    if ((shm = shmat(shmid, NULL, 0)) == (char*)-1) {
        error("Unable to attach to the shared memory block.");
    }

    // Initialize the shared memory block with some data.
    strcpy(shm, "Hello, world!");

    // Initialize the semaphore.
    int semid = semget(key, 1, IPC_CREAT | 0666);
    if (semid == -1) {
        error("Unable to create the semaphore.");
    }
    sem_un.val = 1;
    if (semctl(semid, 0, SETVAL, sem_un) == -1) {
        error("Unable to initialize the semaphore.");
    }

    // Fork a child process.
    pid_t pid = fork();
    if (pid == -1) {
        error("Unable to fork a child process.");
    } else if (pid == 0) {
        // Child process
        printf("Child process: waiting to read from the shared memory block...\n");

        // Wait for the semaphore to become available.
        sem_op[0].sem_num = 0;
        sem_op[0].sem_op = -1;
        sem_op[0].sem_flg = 0;

        if (semop(semid, sem_op, 1) == -1) {
            error("Unable to acquire semaphore.");
        }

        // Read the data from the shared memory block.
        printf("Child process: read '%s' from the shared memory block.\n", shm);

        // Release the semaphore.
        sem_op[0].sem_num = 0;
        sem_op[0].sem_op = 1;
        sem_op[0].sem_flg = 0;

        if (semop(semid, sem_op, 1) == -1) {
            error("Unable to release semaphore.");
        }

    } else {
        // Parent process
        printf("Parent process: wrote '%s' to the shared memory block.\n", shm);

        // Wait for the child process to finish.
        wait(NULL);
    }

    // Detach from the shared memory block.
    if (shmdt(shm) == -1) {
        error("Unable to detach from the shared memory block.");
    }

    // Clean up the shared memory block.
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        error("Unable to clean up the shared memory block.");
    }

    // Clean up the semaphore.
    if (semctl(semid, 0, IPC_RMID, sem_un) == -1) {
        error("Unable to clean up the semaphore.");
    }

    return EXIT_SUCCESS;
}