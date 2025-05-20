//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 10

int main() {
    int shmid;
    key_t key;
    char *shmptr;
    int i;

    // Create a shared memory segment
    key = ftok("/tmp", 65);
    if ((shmid = shmget(key, SIZE * sizeof(int), IPC_CREAT|0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    // Attach the shared memory segment to our address space
    shmptr = shmat(shmid, NULL, 0);
    if ((long)shmptr == -1) {
        perror("shmat");
        exit(1);
    }

    // Initialize the shared memory segment
    for (i = 0; i < SIZE; i++) {
        *(shmptr + i) = 0;
    }

    // Detach the shared memory segment
    if (shmdt(shmptr) == -1) {
        perror("shmdt");
        exit(1);
    }

    // Attach the shared memory segment to our address space again
    if ((shmptr = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Print the contents of the shared memory segment
    for (i = 0; i < SIZE; i++) {
        printf("%d ", *(shmptr + i));
    }
    printf("\n");

    // Detach the shared memory segment
    if (shmdt(shmptr) == -1) {
        perror("shmdt");
        exit(1);
    }

    return 0;
}