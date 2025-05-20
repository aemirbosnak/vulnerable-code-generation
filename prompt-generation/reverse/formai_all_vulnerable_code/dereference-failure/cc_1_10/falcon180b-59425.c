//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: sophisticated
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
    shmid = shmget(IPC_PRIVATE, sizeof(char) * 50, IPC_CREAT | 0600);
    if (shmid == -1) {
        printf("Error creating shared memory segment.\n");
        exit(1);
    }

    // Attach shared memory segment to process
    shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (void *) -1) {
        printf("Error attaching shared memory segment.\n");
        exit(1);
    }

    // Initialize shared memory
    shmptr = shmaddr;
    for (i = 0; i < 50; i++) {
        *shmptr++ = 'A' + i;
    }

    // Detach shared memory segment
    if (shmdt(shmaddr) == -1) {
        printf("Error detaching shared memory segment.\n");
        exit(1);
    }

    // Reattach shared memory segment (in read-only mode)
    shmaddr = shmat(shmid, NULL, SHM_RDONLY);
    if (shmaddr == (void *) -1) {
        printf("Error reattaching shared memory segment.\n");
        exit(1);
    }

    // Read from shared memory segment
    shmptr = shmaddr;
    for (i = 0; i < 50; i++) {
        printf("%c", *shmptr++);
    }

    // Detach shared memory segment
    if (shmdt(shmaddr) == -1) {
        printf("Error detaching shared memory segment.\n");
        exit(1);
    }

    return 0;
}