//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 10

int main() {
    int shmid, i;
    key_t key;
    char *shm;

    // Get a unique key
    key = ftok("shm.c", 65);

    // Create shared memory segment
    shmid = shmget(key, SIZE * sizeof(int), IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory to process
    shm = shmat(shmid, NULL, 0);
    if (shm == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Initialize shared memory
    for (i = 0; i < SIZE; i++) {
        shm[i] = 0;
    }

    // Detach shared memory
    if (shmdt(shm) == -1) {
        perror("shmdt");
        exit(1);
    }

    // Destroy shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}