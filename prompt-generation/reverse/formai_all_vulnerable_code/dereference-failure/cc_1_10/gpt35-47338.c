//FormAI DATASET v1.0 Category: Interprocess communication ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <errno.h>

#define MEMSIZE 256

int main() {

    // Declare variables for shared memory
    int shmid;
    char *shm;
    key_t key = 5678;
    char message[MEMSIZE];

    // Create a shared memory segment with a key
    if ((shmid = shmget(key, MEMSIZE, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    // Attach the shared memory segment to our data space
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Write a message to shared memory
    printf("Enter a message to send to another process: ");
    fgets(message, MEMSIZE, stdin);
    strncpy(shm, message, MEMSIZE);

    // Detach from shared memory segment
    shmdt(shm);

    // Fork another process to receive the message
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) { // Child process

        // Attach to the shared memory segment
        if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
            perror("shmat");
            exit(1);
        }

        // Read the message from shared memory and print it
        printf("Message received: %s\n", shm);

        // Detach from shared memory segment
        shmdt(shm);

        // Delete shared memory segment
        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            perror("shmctl");
            exit(1);
        }

        exit(0);
    }

    // Wait for child process to terminate
    while (wait(NULL) != pid) {}

    return 0;
}