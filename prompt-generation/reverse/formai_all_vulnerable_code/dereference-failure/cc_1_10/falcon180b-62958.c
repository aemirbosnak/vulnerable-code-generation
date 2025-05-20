//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 100

int main() {
    int shmid;
    char *shmptr;
    int i;

    shmid = shmget(IPC_PRIVATE, SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Failed to get shared memory segment\n");
        exit(1);
    }

    shmptr = shmat(shmid, NULL, 0);
    if (shmptr == (char *) -1) {
        printf("Failed to attach shared memory\n");
        exit(1);
    }

    for (i = 0; i < SIZE; i++) {
        shmptr[i] = 'A';
    }

    printf("Shared memory segment created and initialized\n");

    sleep(5);

    for (i = 0; i < SIZE; i++) {
        shmptr[i] = 'B';
    }

    printf("Shared memory segment updated\n");

    sleep(5);

    shmdt(shmptr);
    shmctl(shmid, IPC_RMID, NULL);

    printf("Shared memory segment detached and removed\n");

    return 0;
}