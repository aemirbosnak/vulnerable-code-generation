//FormAI DATASET v1.0 Category: Interprocess communication ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main(void)
{
    int shmid;
    key_t key;
    char *shm, *s;

    // generate key
    key = ftok(".", 'a');

    // create shared memory segment
    if ((shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    // attach shared memory segment
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // write some data to shared memory
    s = shm;
    for (char c = 'a'; c <= 'z'; c++) {
        *s++ = c;
    }
    *s = '\0';

    // wait for child process to read from shared memory
    sleep(1);

    // read data from shared memory
    for (s = shm; *s != '\0'; s++) {
        putchar(*s);
    }
    putchar('\n');

    // detach from shared memory
    if (shmdt(shm) == -1) {
        perror("shmdt");
        exit(1);
    }

    // delete shared memory segment
    if (shmctl(shmid, IPC_RMID, 0) == -1) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}