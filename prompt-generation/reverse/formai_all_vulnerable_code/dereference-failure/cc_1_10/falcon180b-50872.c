//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: Sherlock Holmes
/* C Interprocess Communication Example */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 100

int main() {
    int shmid; // shared memory ID
    char *shmptr; // pointer to shared memory
    int pid; // process ID
    int status; // exit status of child process

    // create shared memory segment
    shmid = shmget(IPC_PRIVATE, MAX_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error creating shared memory segment.\n");
        exit(1);
    }

    // attach shared memory segment to process
    shmptr = (char *) shmat(shmid, NULL, 0);
    if (shmptr == (void *) -1) {
        printf("Error attaching shared memory segment.\n");
        exit(1);
    }

    // initialize shared memory
    for (int i = 0; i < MAX_SIZE; i++) {
        *(shmptr + i) = 0;
    }

    // fork child process
    pid = fork();
    if (pid == -1) {
        printf("Error forking child process.\n");
        exit(1);
    } else if (pid == 0) {
        // child process
        for (int i = 0; i < MAX_SIZE; i++) {
            *(shmptr + i) = i;
        }
        printf("Child process finished.\n");
        exit(0);
    } else {
        // parent process
        wait(&status);
        printf("Child process terminated with status %d.\n", status);
    }

    // detach shared memory segment
    if (shmdt(shmptr) == -1) {
        printf("Error detaching shared memory segment.\n");
        exit(1);
    }

    // destroy shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        printf("Error destroying shared memory segment.\n");
        exit(1);
    }

    return 0;
}

/* End of C Interprocess Communication Example */