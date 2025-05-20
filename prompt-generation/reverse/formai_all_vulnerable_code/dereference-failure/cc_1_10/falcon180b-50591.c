//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 10
#define KEY 1234

int main() {
    int shmid;
    int fd;
    int i;
    char *shm;

    // Create shared memory segment
    shmid = shmget(KEY, SIZE * sizeof(int), IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error creating shared memory segment.\n");
        exit(1);
    }

    // Attach shared memory segment to process
    shm = shmat(shmid, NULL, 0);
    if (shm == (char *) -1) {
        printf("Error attaching shared memory segment.\n");
        exit(1);
    }

    // Initialize shared memory segment
    for (i = 0; i < SIZE; i++) {
        *(shm + i) = 0;
    }

    // Fork child process
    fd = fork();
    if (fd == -1) {
        printf("Error forking child process.\n");
        exit(1);
    } else if (fd == 0) {
        // Child process
        sleep(1);
        for (i = 0; i < SIZE; i++) {
            *(shm + i) = i;
        }
        printf("Child process completed.\n");
        exit(0);
    } else {
        // Parent process
        wait(NULL);
        for (i = 0; i < SIZE; i++) {
            printf("%d ", *(shm + i));
        }
        printf("\n");
    }

    return 0;
}