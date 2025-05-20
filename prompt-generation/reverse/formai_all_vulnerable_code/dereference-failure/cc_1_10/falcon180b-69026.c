//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 100

int main() {
    int shmid;
    char *shmptr;
    int i;

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, SIZE, IPC_CREAT | 0600);
    if (shmid == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // Attach shared memory segment to process
    shmptr = shmat(shmid, NULL, 0);
    if (shmptr == (char *) -1) {
        printf("Error attaching shared memory segment\n");
        exit(1);
    }

    // Initialize shared memory
    for (i = 0; i < SIZE; i++) {
        *(shmptr + i) = 0;
    }

    // Fork a child process
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        sleep(1);
        // Modify shared memory
        for (i = 0; i < SIZE; i++) {
            *(shmptr + i) = 1;
        }
        printf("Child process completed\n");
        exit(0);
    } else {
        // Parent process
        wait(NULL);
        // Check shared memory
        for (i = 0; i < SIZE; i++) {
            if (*(shmptr + i)!= 1) {
                printf("Error: shared memory not modified by child process\n");
                exit(1);
            }
        }
        printf("Parent process completed\n");
        exit(0);
    }
}