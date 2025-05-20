//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 10

int main() {
    int shmid;
    char *shmaddr;
    int i;

    // create shared memory segment
    shmid = shmget(IPC_PRIVATE, SIZE * sizeof(int), IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // attach shared memory segment to process
    shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (char *) -1) {
        printf("Error attaching shared memory segment\n");
        exit(2);
    }

    // initialize shared memory with values
    for (i = 0; i < SIZE; i++) {
        *(shmaddr + i * sizeof(int)) = i;
    }

    // fork child process
    pid_t pid = fork();
    if (pid == -1) {
        printf("Error forking process\n");
        exit(3);
    }
    else if (pid == 0) {
        // child process
        for (i = 0; i < SIZE; i++) {
            // add one to each value in shared memory
            *(shmaddr + i * sizeof(int)) += 1;
        }
        printf("Child process completed\n");
        exit(0);
    }
    else {
        // parent process
        sleep(5);
        for (i = 0; i < SIZE; i++) {
            // display updated values in shared memory
            printf("Value at index %d: %d\n", i, *(shmaddr + i * sizeof(int)));
        }
        printf("Parent process completed\n");
        exit(0);
    }
}