//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 1024

int main() {
    int shmid, i;
    key_t key;
    char *shm;

    // Create shared memory segment
    key = ftok("shm_key", 65);
    shmid = shmget(key, SIZE, IPC_CREAT | 0666);

    if (shmid < 0) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // Attach shared memory segment
    shm = shmat(shmid, NULL, 0);

    if (shm == (char *) -1) {
        printf("Error attaching shared memory segment\n");
        exit(1);
    }

    // Initialize shared memory segment
    for (i = 0; i < SIZE; i++) {
        shm[i] = 0;
    }

    // Fork child process
    int pid = fork();

    if (pid == 0) {
        // Child process
        sleep(2);
        for (i = 0; i < SIZE; i++) {
            shm[i] = i;
        }
        printf("Child process finished\n");
        exit(0);
    } else {
        // Parent process
        wait(NULL);
        for (i = 0; i < SIZE; i++) {
            if (shm[i]!= i) {
                printf("Error: shared memory segment not updated correctly\n");
                exit(1);
            }
        }
        printf("Parent process finished\n");
        exit(0);
    }
}