//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 1024
#define KEY 0x1234

int main() {
    int shmid;
    char *shm;

    // Create a shared memory segment
    shmid = shmget(KEY, SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error: shmget() failed with error %d\n", errno);
        exit(1);
    }

    // Attach the shared memory segment
    shm = shmat(shmid, NULL, 0);
    if (shm == (char*) -1) {
        printf("Error: shmat() failed with error %d\n", errno);
        exit(1);
    }

    // Initialize shared memory segment
    memset(shm, 0, SIZE);

    // Write data to shared memory segment
    strcpy(shm, "Hello, world!");

    // Detach shared memory segment
    if (shmdt(shm) == -1) {
        printf("Error: shmdt() failed with error %d\n", errno);
        exit(1);
    }

    // Delete shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        printf("Error: shmctl() failed with error %d\n", errno);
        exit(1);
    }

    return 0;
}