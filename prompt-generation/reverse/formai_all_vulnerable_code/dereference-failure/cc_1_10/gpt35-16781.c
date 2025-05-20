//FormAI DATASET v1.0 Category: Interprocess communication ; Style: medieval
/* This C program simulates Interprocess communication among knights in a medieval castle */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHMSZ 27 // Size of the shared memory region

int main() {
    int shmid; // Shared memory id
    key_t key; // Shared memory key
    char *shm, *s; // Shared memory pointer and character pointer for writing & reading from it

    key = 5678; // Arbitrary value for shared memory key

    // Create the shared memory segment
    if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    // Attach the shared memory segment to the data space
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Write a message to the shared memory region
    sprintf(shm, "Greetings, fellow knights!");

    // Wait for messages from other knights
    while (*shm != '*') {
        sleep(1);
    }

    // Print out all the messages received
    for (s = shm; *s != '\0'; s++) {
        putchar(*s);
    }
    putchar('\n');

    // Detach the shared memory segment from the data space
    if (shmdt(shm) == -1) {
        perror("shmdt");
        exit(1);
    }

    // Delete the shared memory segment
    if (shmctl(shmid, IPC_RMID, 0) == -1) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}