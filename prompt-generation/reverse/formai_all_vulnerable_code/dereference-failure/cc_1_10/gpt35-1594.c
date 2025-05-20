//FormAI DATASET v1.0 Category: Interprocess communication ; Style: thoughtful
/* Interprocess Communication Example */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHMSZ     27 //shared memory size

int main() {
    char c;
    int shmid;
    key_t key;
    char *shm, *s;

    //Generate a unique key using ftok()
    if ((key = ftok("ipc_prog", 'R')) == -1) {
        perror("ftok");
        exit(1);
    }

    //Create the shared memory segment
    if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) == -1) {
        perror("shmget");
        exit(1);
    }

    //Attach the shared memory segment
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    //Write to the shared memory segment
    s = shm;
    for (c = 'a'; c <= 'z'; c++)
        *s++ = c;
    *s = '\0';

    //Read from the shared memory segment
    s = shm;
    while (*s != NULL) {
        putchar(*s);
        s++;
    }
    putchar('\n');

    //Detach from the shared memory segment
    if (shmdt(shm) == -1) {
        perror("shmdt");
        exit(1);
    }

    //Delete the shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    exit(0);
}