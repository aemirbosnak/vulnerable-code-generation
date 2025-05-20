//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 10

int main() {
    int shmid;
    char *shmaddr;
    int i;

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, SIZE * sizeof(int), IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // Attach shared memory segment to process
    shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (void *) -1) {
        printf("Error attaching shared memory segment\n");
        exit(1);
    }

    // Initialize shared memory segment
    for (i = 0; i < SIZE; i++) {
        ((int *) shmaddr)[i] = 0;
    }

    // Detach shared memory segment from process
    shmdt(shmaddr);

    // Attach shared memory segment to parent process
    shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (void *) -1) {
        printf("Error attaching shared memory segment\n");
        exit(1);
    }

    // Read and display shared memory segment
    for (i = 0; i < SIZE; i++) {
        printf("%d ", ((int *) shmaddr)[i]);
    }

    // Detach shared memory segment from process
    shmdt(shmaddr);

    // Remove shared memory segment from system
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}