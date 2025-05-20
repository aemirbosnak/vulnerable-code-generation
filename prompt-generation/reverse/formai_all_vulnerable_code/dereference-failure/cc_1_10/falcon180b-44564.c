//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: beginner-friendly
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
    int i;

    // create shared memory segment
    shmid = shmget(IPC_PRIVATE, SIZE * sizeof(int), 0777 | IPC_CREAT);
    if (shmid == -1) {
        printf("Error creating shared memory segment.\n");
        exit(1);
    }

    // attach shared memory segment to process
    shmptr = (char *)shmat(shmid, NULL, 0);
    if (shmptr == (char *)-1) {
        printf("Error attaching shared memory segment.\n");
        exit(2);
    }

    // initialize shared memory segment
    for (i = 0; i < SIZE; i++) {
        *(shmptr + i * sizeof(int)) = 0;
    }

    // fork child process
    int pid = fork();
    if (pid == 0) {
        sleep(2);
        // child process writes to shared memory segment
        for (i = 0; i < SIZE; i++) {
            *(shmptr + i * sizeof(int)) = i + 1;
        }
        printf("Child process finished writing to shared memory segment.\n");
    } else {
        // parent process reads from shared memory segment
        sleep(1);
        for (i = 0; i < SIZE; i++) {
            printf("Shared memory segment value %d: %d\n", i, *(shmptr + i * sizeof(int)));
        }
        printf("Parent process finished reading from shared memory segment.\n");
    }

    // detach shared memory segment
    if (shmdt(shmptr) == -1) {
        printf("Error detaching shared memory segment.\n");
        exit(3);
    }

    // destroy shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        printf("Error destroying shared memory segment.\n");
        exit(4);
    }

    return 0;
}