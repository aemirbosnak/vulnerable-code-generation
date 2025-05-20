//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SIZE 10

int main() {
    int shmid;
    int *shmptr;
    pid_t pid;

    // create shared memory segment
    shmid = shmget(IPC_PRIVATE, SIZE * sizeof(int), IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // attach shared memory segment
    shmptr = shmat(shmid, NULL, 0);
    if (shmptr == (void *) -1) {
        perror("shmat");
        exit(1);
    }

    // initialize shared memory segment
    for (int i = 0; i < SIZE; ++i) {
        *(shmptr + i) = i;
    }

    // fork child process
    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // child process
        for (int i = 0; i < SIZE; ++i) {
            // modify shared memory segment
            *(shmptr + i) *= 2;
        }
        printf("Child process completed.\n");
        exit(0);
    } else {
        // parent process
        wait(NULL);
        printf("Parent process completed.\n");
        exit(0);
    }

    return 0;
}