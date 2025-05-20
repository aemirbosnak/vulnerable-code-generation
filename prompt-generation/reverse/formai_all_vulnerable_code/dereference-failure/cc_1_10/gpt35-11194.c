//FormAI DATASET v1.0 Category: Interprocess communication ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHMSZ 27  // size of shared memory segment

int main()
{
    int shmid;
    key_t key;
    char *shm, *s;

    // generate a unique key
    key = ftok(".", 'S');
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    // create the shared memory segment
    shmid = shmget(key, SHMSZ, 0666|IPC_CREAT);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // attach the shared memory segment to the process's address space
    shm = shmat(shmid, NULL, 0);
    if (shm == (char *)-1) {
        perror("shmat");
        exit(1);
    }

    // write some data to the shared memory segment
    s = shm;
    for (int i = 65; i < 91; i++) {
        *s++ = i;
    }
    *s = '\0';

    // read the data from the shared memory segment and print it out
    s = shm;
    while (*s != '\0') {
        putchar(*s++);
    }
    putchar('\n');

    // detach the shared memory segment
    if (shmdt(shm) == -1) {
        perror("shmdt");
        exit(1);
    }

    // remove the shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}