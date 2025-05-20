//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 10

int main() {
    int shmid, i;
    char *shmptr;
    pid_t pid;

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, SIZE * sizeof(int), 0777 | IPC_CREAT);
    if (shmid == -1) {
        printf("Error creating shared memory segment");
        exit(1);
    }

    // Attach shared memory segment to process
    shmptr = shmat(shmid, NULL, 0);
    if (shmptr == (void *) -1) {
        printf("Error attaching shared memory segment");
        exit(1);
    }

    // Initialize shared memory segment
    for (i = 0; i < SIZE; i++) {
        *(shmptr + i) = i;
    }

    // Create child process
    pid = fork();
    if (pid == -1) {
        printf("Error creating child process");
        exit(1);
    }

    // Parent process
    if (pid > 0) {
        int status;
        waitpid(pid, &status, 0);
        printf("Child process terminated\n");
        exit(0);
    }

    // Child process
    else {
        printf("Child process started\n");

        // Modify shared memory segment
        for (i = 0; i < SIZE; i++) {
            *(shmptr + i) = i * 2;
        }

        // Detach shared memory segment
        if (shmdt(shmptr) == -1) {
            printf("Error detaching shared memory segment");
            exit(1);
        }

        // Exit child process
        exit(0);
    }
}