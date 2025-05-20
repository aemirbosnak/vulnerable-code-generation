//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SIZE 10

int main() {
    int shmid;
    int *shmptr;
    pid_t childpid;
    int status;

    // create shared memory segment
    shmid = shmget(IPC_PRIVATE, SIZE * sizeof(int), IPC_CREAT | 0777);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // attach shared memory segment to current process
    shmptr = shmat(shmid, NULL, 0);
    if (shmptr == (void *)-1) {
        perror("shmat");
        exit(1);
    }

    // initialize shared memory segment
    for (int i = 0; i < SIZE; i++) {
        shmptr[i] = 0;
    }

    // fork child process
    childpid = fork();
    if (childpid == -1) {
        perror("fork");
        exit(1);
    }

    // if parent process
    if (childpid > 0) {
        // wait for child process to terminate
        waitpid(childpid, &status, 0);

        // print shared memory segment
        for (int i = 0; i < SIZE; i++) {
            printf("%d ", shmptr[i]);
        }
        printf("\n");

        // detach shared memory segment
        shmdt(shmptr);

        // delete shared memory segment
        shmctl(shmid, IPC_RMID, NULL);
    }
    // if child process
    else {
        // wait for parent process to initialize shared memory segment
        sleep(1);

        // modify shared memory segment
        for (int i = 0; i < SIZE; i++) {
            shmptr[i] = i;
        }

        // exit child process
        exit(0);
    }

    return 0;
}