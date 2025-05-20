//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <string.h>

#define SIZE 10

int main() {
    int shmid;
    char *shmptr;
    int i;

    // create shared memory segment
    shmid = shmget(IPC_PRIVATE, SIZE * sizeof(int), 0666 | IPC_CREAT);
    if (shmid == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // attach shared memory segment to process
    shmptr = shmat(shmid, NULL, 0);
    if (shmptr == (char *) -1) {
        printf("Error attaching shared memory segment\n");
        exit(1);
    }

    // initialize shared memory segment
    for (i = 0; i < SIZE; i++) {
        *(shmptr + i * sizeof(int)) = 0;
    }

    // fork a child process
    int pid = fork();
    if (pid == -1) {
        printf("Error forking child process\n");
        exit(1);
    } else if (pid == 0) {
        // child process
        int *ptr = (int *) shmat(shmid, NULL, 0);
        for (i = 0; i < SIZE; i++) {
            *(ptr + i) = i;
        }
        printf("Child process completed\n");
        exit(0);
    } else {
        // parent process
        wait(NULL);
        printf("Parent process completed\n");
        exit(0);
    }

    return 0;
}