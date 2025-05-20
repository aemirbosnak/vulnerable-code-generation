//FormAI DATASET v1.0 Category: Interprocess communication ; Style: systematic
/*
  Program: Interprocess Communication
  Language: C
  Created by: [Your Name]
  Created on: [Date]
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHMSZ 27

int main()
{
    int shmid;
    key_t key;
    char *shm, *s;

    // Generate a unique key for shared memory
    key = 5678;

    // Create the shared memory segment
    if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    // Attach the shared memory segment
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Write to the shared memory
    char message[] = "Hello, World!";
    memcpy(shm, message, strlen(message));

    // Read from the shared memory
    for (s = shm; *s != '\0'; s++) {
        putchar(*s);
    }
    putchar('\n');

    // Detach from the shared memory
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