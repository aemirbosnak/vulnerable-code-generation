//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    int shmid;
    void *shmaddr;
    char *shmptr;
    int i;

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, 1024, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach to shared memory segment
    shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (void *)-1) {
        perror("shmat");
        exit(1);
    }

    // Initialize shared memory segment
    shmptr = (char *)shmaddr;
    for (i = 0; i < 1024; i++) {
        shmptr[i] = 0;
    }

    // Print shared memory segment
    printf("Shared memory segment initialized\n");
    for (i = 0; i < 1024; i++) {
        printf("%d ", shmptr[i]);
    }
    printf("\n");

    // Detach from shared memory segment
    if (shmdt(shmaddr) == -1) {
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