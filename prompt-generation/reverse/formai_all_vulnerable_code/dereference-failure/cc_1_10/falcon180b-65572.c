//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 100

int main() {
    int shmid;
    char *shmptr;
    key_t key = 1234;

    // Create shared memory segment
    if ((shmid = shmget(key, SIZE, IPC_CREAT | 0666)) < 0) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // Attach to shared memory segment
    if ((shmptr = shmat(shmid, NULL, 0)) == (char *) -1) {
        printf("Error attaching to shared memory segment\n");
        exit(1);
    }

    // Write data to shared memory segment
    strcpy(shmptr, "Hello, world!");

    // Create child process
    pid_t pid = fork();

    if (pid < 0) {
        printf("Error creating child process\n");
        exit(1);
    } else if (pid == 0) {
        // Child process

        // Attach to shared memory segment
        if ((shmptr = shmat(shmid, NULL, 0)) == (char *) -1) {
            printf("Error attaching to shared memory segment\n");
            exit(1);
        }

        // Read data from shared memory segment
        printf("Child process: %s\n", shmptr);

        // Detach from shared memory segment
        if (shmdt(shmptr) < 0) {
            printf("Error detaching from shared memory segment\n");
            exit(1);
        }

        // Exit child process
        exit(0);
    } else {
        // Parent process

        // Detach from shared memory segment
        if (shmdt(shmptr) < 0) {
            printf("Error detaching from shared memory segment\n");
            exit(1);
        }

        // Wait for child process to finish
        wait(NULL);

        // Delete shared memory segment
        if (shmctl(shmid, IPC_RMID, NULL) < 0) {
            printf("Error deleting shared memory segment\n");
            exit(1);
        }
    }

    return 0;
}