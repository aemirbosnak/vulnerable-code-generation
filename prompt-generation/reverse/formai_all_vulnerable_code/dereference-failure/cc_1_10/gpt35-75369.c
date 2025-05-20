//FormAI DATASET v1.0 Category: Interprocess communication ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHMSIZE 1024

int main() {
    int shmid;
    key_t key;
    char *shm, *s;

    // generate a key for the shared memory segment
    key = ftok(".", 'A');

    // create a shared memory segment and return its ID
    shmid = shmget(key, SHMSIZE, IPC_CREAT | 0666);

    if (shmid == -1) {
        perror("shmget error");
        exit(1);
    }

    // attach the shared memory segment to our process's address space
    shm = shmat(shmid, NULL, 0);

    if (shm == (char *) -1) {
        perror("shmat error");
        exit(1);
    }

    // write a message to the shared memory segment
    strncpy(shm, "Hello, World!", SHMSIZE);

    // loop through the shared memory segment and print each character to stdout
    for (s = shm; *s != '\0'; s++) {
        putchar(*s);
    }

    putchar('\n');

    // detach the shared memory segment from our process's address space
    if (shmdt(shm) == -1) {
        perror("shmdt error");
        exit(1);
    }

    // remove the shared memory segment from the system
    if (shmctl(shmid, IPC_RMID, 0) == -1) {
        perror("shmctl error");
        exit(1);
    }

    return 0;
}