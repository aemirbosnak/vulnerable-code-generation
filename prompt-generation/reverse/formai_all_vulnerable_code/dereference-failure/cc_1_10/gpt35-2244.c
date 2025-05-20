//FormAI DATASET v1.0 Category: Interprocess communication ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define SHMSIZE 27

int main() {
    char c;
    int shmid;
    key_t key;
    char *shm, *s;

    // Generate a unique key
    key = ftok("ipcdemo", 'R');

    // Allocate shared memory
    shmid = shmget(key, SHMSIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach to shared memory
    shm = shmat(shmid, NULL, 0);
    if (shm == (char*) -1) {
        perror("shmat");
        exit(1);
    }

    // Write data to shared memory
    s = shm;
    for (c = 'a'; c <= 'z'; c++)
        *s++ = c;
    *s = '\0';

    // Wait until the other process has consumed the data
    while (*shm != '*')
        sleep(1);

    // Detach from shared memory
    if (shmdt(shm) == -1) {
        perror("shmdt");
        exit(1);
    }

    // Deallocate shared memory
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}