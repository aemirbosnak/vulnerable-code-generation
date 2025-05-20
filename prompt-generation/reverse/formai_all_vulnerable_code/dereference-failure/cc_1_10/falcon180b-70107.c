//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 100

int main(int argc, char *argv[]) {
    int shmid, i;
    char *shmptr;
    pid_t pid;

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error creating shared memory segment.\n");
        exit(1);
    }

    // Attach shared memory segment to process
    shmptr = shmat(shmid, NULL, 0);
    if (shmptr == (char *) -1) {
        printf("Error attaching shared memory segment.\n");
        exit(1);
    }

    // Initialize shared memory segment
    for (i = 0; i < SIZE; i++) {
        shmptr[i] = i;
    }

    // Fork child process
    pid = fork();
    if (pid == -1) {
        printf("Error forking child process.\n");
        exit(1);
    } else if (pid == 0) {
        // Child process
        sleep(1); // Allow parent process to initialize shared memory segment
        printf("Child process reading from shared memory segment:\n");
        for (i = 0; i < SIZE; i++) {
            printf("%d ", shmptr[i]);
        }
        printf("\n");
        exit(0);
    } else {
        // Parent process
        sleep(1); // Allow child process to read from shared memory segment
        printf("Parent process writing to shared memory segment:\n");
        for (i = 0; i < SIZE; i++) {
            shmptr[i] = -i;
        }
        sleep(1); // Allow child process to read from shared memory segment
        printf("Parent process reading from shared memory segment:\n");
        for (i = 0; i < SIZE; i++) {
            printf("%d ", shmptr[i]);
        }
        printf("\n");
        exit(0);
    }
}