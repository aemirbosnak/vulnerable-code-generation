//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 0x12345678
#define SHM_SIZE 1024

int main() {
    int shmid;
    void *shmaddr;
    char *shmptr;

    // Create shared memory segment
    shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach to shared memory segment
    shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (void *) -1) {
        perror("shmat");
        exit(1);
    }

    // Map shared memory segment to process address space
    shmptr = (char *) shmaddr;

    // Initialize shared memory
    for (int i = 0; i < SHM_SIZE; i++) {
        *shmptr++ = '\0';
    }

    // Print shared memory contents
    printf("Shared memory contents:\n");
    for (int i = 0; i < SHM_SIZE; i++) {
        printf("%c", *(shmptr + i));
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