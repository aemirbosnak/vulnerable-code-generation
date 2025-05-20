//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHM_KEY 0x1234
#define SHM_SIZE 1024

int main() {
    int shmid;
    char *shm;
    pid_t pid;

    // create shared memory segment
    shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        fprintf(stderr, "shmget error\n");
        exit(1);
    }

    // attach shared memory segment
    shm = shmat(shmid, NULL, 0);
    if (shm == (void *) -1) {
        fprintf(stderr, "shmat error\n");
        exit(1);
    }

    // initialize shared memory
    memset(shm, 0, SHM_SIZE);

    // fork child process
    pid = fork();
    if (pid == -1) {
        fprintf(stderr, "fork error\n");
        exit(1);
    } else if (pid == 0) {
        // child process
        // increment shared memory value
        int *counter = shm;
        (*counter)++;

        // detach shared memory segment
        if (shmdt(shm) == -1) {
            fprintf(stderr, "shmdt error\n");
            exit(1);
        }

        // exit child process
        exit(0);
    } else {
        // parent process
        // wait for child process to finish
        wait(NULL);

        // detach shared memory segment
        if (shmdt(shm) == -1) {
            fprintf(stderr, "shmdt error\n");
            exit(1);
        }

        // print shared memory value
        int *counter = shm;
        printf("Shared memory value: %d\n", *counter);
    }

    return 0;
}