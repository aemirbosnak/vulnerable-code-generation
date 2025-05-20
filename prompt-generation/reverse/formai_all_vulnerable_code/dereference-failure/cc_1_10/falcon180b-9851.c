//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 1000

int main(int argc, char *argv[]) {
    int shmid;
    char *shmptr;
    char *shmptr2;
    int i;
    pid_t childpid;

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Shared memory segment creation failed\n");
        return 1;
    }

    // Attach shared memory segment to process
    shmptr = (char *) shmat(shmid, 0, 0);
    if (shmptr == (char *) -1) {
        printf("Shared memory segment attachment failed\n");
        return 1;
    }

    // Initialize shared memory segment
    for (i = 0; i < SIZE; i++) {
        shmptr[i] = 0;
    }

    // Fork child process
    childpid = fork();
    if (childpid == 0) {
        // Child process
        shmptr2 = (char *) shmat(shmid, 0, 0);
        if (shmptr2 == (char *) -1) {
            printf("Shared memory segment attachment failed\n");
            return 1;
        }

        // Modify shared memory segment
        for (i = 0; i < SIZE; i++) {
            shmptr2[i] = 1;
        }

        printf("Child process has modified shared memory segment\n");
        return 0;
    } else {
        // Parent process
        wait(NULL);
        printf("Parent process has received signal from child process\n");
    }

    // Detach shared memory segment
    if (shmdt(shmptr) == -1) {
        printf("Shared memory segment detachment failed\n");
        return 1;
    }

    return 0;
}