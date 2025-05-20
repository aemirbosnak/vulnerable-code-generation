//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: detailed
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
    key_t key = 12345;

    // Create shared memory segment
    shmid = shmget(key, SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error: shmget failed\n");
        exit(1);
    }

    // Attach to shared memory segment
    shmptr = shmat(shmid, NULL, 0);
    if (shmptr == (char *) -1) {
        printf("Error: shmat failed\n");
        exit(1);
    }

    // Initialize shared memory segment
    for (int i = 0; i < SIZE; i++) {
        *(shmptr + i) = 'A' + i;
    }

    // Detach from shared memory segment
    if (shmdt(shmptr) == -1) {
        printf("Error: shmdt failed\n");
        exit(1);
    }

    // Attach to shared memory segment again
    shmptr = shmat(shmid, NULL, 0);
    if (shmptr == (char *) -1) {
        printf("Error: shmat failed\n");
        exit(1);
    }

    // Print contents of shared memory segment
    for (int i = 0; i < SIZE; i++) {
        printf("%c", *(shmptr + i));
    }

    return 0;
}