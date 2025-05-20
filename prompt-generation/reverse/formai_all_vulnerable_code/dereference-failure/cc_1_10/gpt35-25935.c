//FormAI DATASET v1.0 Category: Interprocess communication ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHMSZ 27

int main() {
    char c;
    int shmid;
    key_t key;
    char *shm, *s;

    //generate key for shared memory
    key = 5678;

    //get id of shared memory segment
    if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    //attach shared memory segment to data space
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    //write message to shared memory
    s = shm;
    for (c = 'a'; c <= 'z'; c++) {
        *s++ = c;
    }
    *s = '\0';

    //wait for another process to read the shared memory
    while (*shm != '*') {
        sleep(1);
    }

    //detach shared memory segment from data space
    if (shmdt(shm) == -1) {
        perror("shmdt");
        exit(1);
    }

    //delete shared memory segment
    if (shmctl(shmid, IPC_RMID, 0) == -1) {
        perror("shmctl");
        exit(1);
    }

    printf("Shared memory cleaned up.\n");

    return 0;
}