//FormAI DATASET v1.0 Category: Interprocess communication ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHMSZ 27

int main()
{
    char c;
    int shmid;
    key_t key;
    char *shm, *s;

    // generate a unique key
    key = 5678;

    // create a shared memory segment
    if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    // attach the shared memory segment to our data space
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // write some data to the shared memory segment
    s = shm;
    for (c = 'a'; c <= 'z'; c++)
        *s++ = c;
    *s = '\0';

    // wait for the other process to read from the shared memory segment
    while (*shm != '*')
        sleep(1);

    // print out the contents of the shared memory segment
    for (s = shm; *s != '\0'; s++)
        putchar(*s);

    putchar('\n');

    // detach the shared memory segment from our data space
    if (shmdt(shm) == -1) {
        perror("shmdt");
        exit(1);
    }

    // delete the shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}