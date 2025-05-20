//FormAI DATASET v1.0 Category: Interprocess communication ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define SHM_SIZE 1024

int main()
{
    int shmid;
    key_t key;
    char *shm, *s;

    // generate a unique key for shared memory
    key = ftok(".", 'm');

    // create shared memory segment with read and write permissions
    shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // attach the shared memory segment to the process's address space
    shm = shmat(shmid, NULL, 0);
    if (shm == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // write a message to the shared memory
    strcpy(shm, "Hello, World!");

    // iterate through the shared memory and increment each character
    for (s = shm; *s != '\0'; s++)
        (*s)++;

    // wait for the other process to read the data
    sleep(5);

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