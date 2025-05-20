//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

#define SIZE 100

int main() {
    int shmid;
    char *shm_ptr;
    pid_t pid;
    int status;

    // create shared memory segment
    shmid = shmget(IPC_PRIVATE, SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error: shmget failed\n");
        exit(1);
    }

    // attach shared memory segment
    shm_ptr = shmat(shmid, NULL, 0);
    if (shm_ptr == (char *)-1) {
        printf("Error: shmat failed\n");
        exit(2);
    }

    // initialize shared memory
    strcpy(shm_ptr, "Hello, world!");

    // fork a child process
    pid = fork();
    if (pid == -1) {
        printf("Error: fork failed\n");
        exit(3);
    } else if (pid == 0) {
        // child process
        sleep(1);

        // modify shared memory
        shm_ptr[0] = 'H';
        printf("Child: Shared memory modified\n");

        // exit child process
        exit(0);
    } else {
        // parent process
        waitpid(pid, &status, 0);

        // print shared memory
        printf("Parent: Shared memory: %s\n", shm_ptr);

        // detach shared memory segment
        if (shmdt(shm_ptr) == -1) {
            printf("Error: shmdt failed\n");
            exit(4);
        }

        // destroy shared memory segment
        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            printf("Error: shmctl failed\n");
            exit(5);
        }
    }

    return 0;
}