//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHM_KEY 12345
#define SHM_SIZE 1024

int main() {
    int shmid;
    char *shmptr;
    pid_t childpid;

    // create shared memory segment
    shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // attach to shared memory segment
    shmptr = shmat(shmid, NULL, 0);
    if (shmptr == (char *)-1) {
        perror("shmat");
        exit(1);
    }

    // initialize shared memory
    strcpy(shmptr, "Hello, world!");

    // fork a child process
    childpid = fork();
    if (childpid == -1) {
        perror("fork");
        exit(1);
    } else if (childpid == 0) {
        // child process

        // detach from shared memory segment
        if (shmdt(shmptr) == -1) {
            perror("shmdt");
            exit(1);
        }

        // modify shared memory
        shmptr = shmat(shmid, NULL, 0);
        if (shmptr == (char *)-1) {
            perror("shmat");
            exit(1);
        }
        strcpy(shmptr, "Goodbye, world!");

        // exit child process
        exit(0);
    } else {
        // parent process

        // wait for child process to exit
        wait(NULL);

        // detach from shared memory segment
        if (shmdt(shmptr) == -1) {
            perror("shmdt");
            exit(1);
        }

        // print contents of shared memory
        shmptr = shmat(shmid, NULL, 0);
        if (shmptr == (char *)-1) {
            perror("shmat");
            exit(1);
        }
        printf("Shared memory contains: %s\n", shmptr);

        // delete shared memory segment
        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            perror("shmctl");
            exit(1);
        }
    }

    return 0;
}