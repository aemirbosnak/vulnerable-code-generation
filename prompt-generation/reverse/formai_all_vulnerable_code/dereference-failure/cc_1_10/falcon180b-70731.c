//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: ephemeral
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
    char *shm;
    pid_t pid;

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, SIZE * sizeof(int), IPC_CREAT | 0666);
    if (shmid < 0) {
        printf("Error: shmget() failed\n");
        exit(1);
    }

    // Attach shared memory segment to process's address space
    shm = shmat(shmid, NULL, 0);
    if (shm == (char *) -1) {
        printf("Error: shmat() failed\n");
        exit(1);
    }

    // Fill shared memory segment with random values
    for (int i = 0; i < SIZE; i++) {
        *(shm + i * sizeof(int)) = rand();
    }

    // Fork child process
    pid = fork();
    if (pid < 0) {
        printf("Error: fork() failed\n");
        exit(1);
    } else if (pid == 0) {
        // Child process
        for (int i = 0; i < SIZE; i++) {
            *(shm + i * sizeof(int)) *= 2;
        }
        printf("Child process finished\n");
        exit(0);
    } else {
        // Parent process
        wait(NULL);
        for (int i = 0; i < SIZE; i++) {
            printf("%d ", *(shm + i * sizeof(int)));
        }
        printf("\n");
    }

    return 0;
}