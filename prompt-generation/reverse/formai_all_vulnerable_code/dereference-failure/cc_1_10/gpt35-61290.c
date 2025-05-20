//FormAI DATASET v1.0 Category: Interprocess communication ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main(int argc, char *argv[]) {
    int shmid;
    key_t key;
    char *shm, *s;

    // generate a unique key
    if ((key = ftok(".", 'R')) == -1) {
        perror("ftok");
        exit(1);
    }

    // create shared memory segment
    if ((shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    // attach to shared memory segment
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // write to shared memory segment
    strcpy(shm, "Hello, world!");

    // use pointer to traverse through shared memory segment
    for (s = shm; *s != '\0'; s++) {
        putchar(*s);
    }
    putchar('\n');

    // detach from shared memory segment
    if (shmdt(shm) == -1) {
        perror("shmdt");
        exit(1);
    }

    // remove shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}