//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: visionary
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
    char *str = "Hello, world!";

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error: Could not create shared memory segment.\n");
        exit(1);
    }

    // Attach shared memory segment to process
    shmptr = shmat(shmid, (void*) 0, 0);
    if (shmptr == (void*) -1) {
        printf("Error: Could not attach shared memory segment.\n");
        exit(1);
    }

    // Copy string to shared memory segment
    strcpy(shmptr, str);

    // Detach shared memory segment
    if (shmdt(shmptr) == -1) {
        printf("Error: Could not detach shared memory segment.\n");
        exit(1);
    }

    // Attach shared memory segment to process again
    shmptr = shmat(shmid, (void*) 0, 0);
    if (shmptr == (void*) -1) {
        printf("Error: Could not attach shared memory segment.\n");
        exit(1);
    }

    // Print string from shared memory segment
    printf("String from shared memory: %s\n", shmptr);

    // Detach shared memory segment
    if (shmdt(shmptr) == -1) {
        printf("Error: Could not detach shared memory segment.\n");
        exit(1);
    }

    // Remove shared memory segment
    if (shmctl(shmid, IPC_RMID, 0) == -1) {
        printf("Error: Could not remove shared memory segment.\n");
        exit(1);
    }

    return 0;
}