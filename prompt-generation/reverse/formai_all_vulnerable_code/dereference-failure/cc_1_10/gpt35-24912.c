//FormAI DATASET v1.0 Category: Interprocess communication ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHMSZ 27 // Size of the shared memory segment

int main()
{
    int shmid;
    key_t key;
    char *shm, *s;

    // Generate a key for the shared memory segment
    if ((key = ftok(".", 'a')) == -1) {
        perror("ftok");
        exit(1);
    }

    // Create the shared memory segment
    if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    // Attach the shared memory segment to our process's address space
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Write a string to the shared memory segment
    s = shm;
    strcpy(s, "Hello, World!");

    // Increment the shared memory pointer by the length of the string
    s += strlen("Hello, World!");

    // Add a null terminator to the end of the string
    *s = '\0';

    // Wait for the other process to read the data
    while (*shm != '*') {
        sleep(1);
    }

    // Detach the shared memory segment from our process's address space
    if (shmdt(shm) == -1) {
        perror("shmdt");
        exit(1);
    }

    // Remove the shared memory segment
    if (shmctl(shmid, IPC_RMID, 0) == -1) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}