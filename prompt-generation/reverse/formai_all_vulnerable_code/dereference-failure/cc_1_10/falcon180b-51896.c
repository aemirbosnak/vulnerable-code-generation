//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 1024

int main() {
    int shmid;
    int *shmptr;
    pid_t pid;
    char *shmaddr;

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, SIZE, IPC_CREAT | 0666);

    if (shmid < 0) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // Attach shared memory segment to process
    shmaddr = shmat(shmid, NULL, 0);

    if (shmaddr == (void*)-1) {
        printf("Error attaching shared memory segment\n");
        exit(1);
    }

    // Initialize shared memory
    for (int i = 0; i < SIZE; i++) {
        *(shmaddr + i) = 0;
    }

    // Fork child process
    pid = fork();

    if (pid == -1) {
        printf("Error forking child process\n");
        exit(1);
    } else if (pid == 0) {
        // Child process
        for (int i = 0; i < SIZE; i++) {
            *(shmaddr + i) = i;
        }
        printf("Child process finished\n");
        exit(0);
    } else {
        // Parent process
        wait(NULL);
        printf("Parent process finished\n");
        exit(0);
    }
}