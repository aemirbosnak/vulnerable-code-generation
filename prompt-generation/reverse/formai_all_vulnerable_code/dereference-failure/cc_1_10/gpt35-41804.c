//FormAI DATASET v1.0 Category: Interprocess communication ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHMSIZE 1024

int main(void) {
    int shmid;
    key_t key;
    char *shm, *s;

    // generate a key for shared memory
    key = ftok(".", 'C');

    // create the shared memory segment
    shmid = shmget(key, SHMSIZE, IPC_CREAT | 0666);

    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }

    // attach the shared memory segment to process
    shm = shmat(shmid, NULL, 0);

    if (shm == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // write a message to shared memory
    strncpy(shm, "Hello World!", SHMSIZE);

    // print out the message from shared memory
    for (s = shm; *s != '\0'; s++) {
        putchar(*s);
    }

    putchar('\n');

    // disconnect from shared memory segment
    shmdt(shm);

    // remove the shared memory segment
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}