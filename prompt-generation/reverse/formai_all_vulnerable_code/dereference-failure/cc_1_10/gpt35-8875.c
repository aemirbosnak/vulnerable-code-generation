//FormAI DATASET v1.0 Category: Interprocess communication ; Style: Donald Knuth
// Knuth Style Interprocess Communication Example Program
// By (your name)

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>

#define SHM_SIZE 1024  // Shared memory size

int main()
{
    int shmid;
    key_t key;
    char *shm, *s;

    // Generate Key
    if((key = ftok(".", 'A')) == -1) {
        perror("ftok");
        exit(1);
    }

    // Get shared memory segment
    if((shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666)) == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach to shared memory
    if((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Write to shared memory
    strncpy(shm, "Hello World", 11);

    // Read from shared memory
    for(s = shm; *s != '\0'; s++)
        putchar(*s);
    putchar('\n');

    // Detach from shared memory
    if(shmdt(shm) == -1) {
        perror("shmdt");
        exit(1);
    }

    // Remove shared memory segment
    if(shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}