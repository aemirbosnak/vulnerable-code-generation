//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 100

int main() {
    int shmid;
    char *shm;
    int i;

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory segment
    shm = shmat(shmid, NULL, 0);
    if (shm == (void *) -1) {
        perror("shmat");
        exit(1);
    }

    // Initialize shared memory segment
    for (i = 0; i < SIZE; i++) {
        *(shm + i) = 0;
    }

    // Fork child process
    int pid = fork();
    if (pid == 0) {
        // Child process
        sleep(1);
        for (i = 0; i < SIZE; i++) {
            *(shm + i) = 1;
        }
        printf("Child process done.\n");
        exit(0);
    } else {
        // Parent process
        sleep(2);
        for (i = 0; i < SIZE; i++) {
            if (*(shm + i)!= 1) {
                printf("Interprocess communication failed.\n");
                exit(1);
            }
        }
        printf("Interprocess communication successful.\n");
        exit(0);
    }
}