//FormAI DATASET v1.0 Category: Interprocess communication ; Style: irregular
// Initializing variables
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024 // size of shared memory block

// signal handler function
void sigHandler(int sig) {
    printf("\nSignal %d detected. Exiting program.\n", sig);
    exit(0);
}

int main() {
    // Initializing variables
    pid_t pid;
    key_t key;
    int shmID;
    char *shmPtr;

    // signal handlers for SIGINT and SIGTERM
    signal(SIGINT, sigHandler);
    signal(SIGTERM, sigHandler);

    // generate unique key for shared memory segment
    if ((key = ftok("ipc_example.c", 'R')) == -1) {
        perror("ftok error");
        exit(1);
    }

    // allocate shared memory segment
    if ((shmID = shmget(key, SHM_SIZE, 0644 | IPC_CREAT)) == -1) {
        perror("shmget error");
        exit(1);
    }

    // attach shared memory segment to program's address space
    if ((shmPtr = shmat(shmID, 0, 0)) == (char *) -1) {
        perror("shmat error");
        exit(1);
    }

    // fork process to create child
    if ((pid = fork()) == -1) {
        perror("fork error");
        exit(1);
    } else if (pid == 0) { // child process
        printf("Child process is running...\n");

        // write data to shared memory segment
        memset(shmPtr, 0, SHM_SIZE);
        snprintf(shmPtr, SHM_SIZE, "Hello world from child process!\n");

        exit(0);
    } else { // parent process
        printf("Parent process is running...\n");

        // wait for child process to finish writing to shared memory segment
        wait(NULL);

        // print data read from shared memory segment
        printf("Message from child process: %s\n", shmPtr);

        // detach shared memory segment from program's address space and release resources
        if (shmdt(shmPtr) == -1) {
            perror("shmdt error");
            exit(1);
        }

        if (shmctl(shmID, IPC_RMID, NULL) == -1) {
            perror("shmctl error");
            exit(1);
        }

        exit(0);
    }

    return 0;
}