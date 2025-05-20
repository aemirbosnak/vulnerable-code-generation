//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 10

int main() {
    int shmid;
    char *shmptr;
    key_t key = 1234;
    int i;

    // Create shared memory segment
    if ((shmid = shmget(key, SIZE * sizeof(int), IPC_CREAT | 0666)) == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory segment
    if ((shmptr = shmat(shmid, NULL, 0)) == (void *) -1) {
        perror("shmat");
        exit(1);
    }

    // Initialize shared memory
    for (i = 0; i < SIZE; i++) {
        *(shmptr + i) = 0;
    }

    // Print shared memory
    printf("Shared Memory:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", *(shmptr + i));
    }
    printf("\n");

    // Detach shared memory segment
    if (shmdt(shmptr) == -1) {
        perror("shmdt");
        exit(1);
    }

    // Delete shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}