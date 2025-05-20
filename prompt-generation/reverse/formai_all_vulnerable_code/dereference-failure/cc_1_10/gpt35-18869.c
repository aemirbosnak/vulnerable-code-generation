//FormAI DATASET v1.0 Category: Interprocess communication ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 200
#define KEY 1234

int main() {
    int shmid;
    char *shm, *s;

    // Create a shared memory segment
    if ((shmid = shmget(KEY, SHM_SIZE, 0666)) < 0) {
        perror("shmget");
        return 1;
    }

    // Attach the shared memory segment to our data space
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        return 1;
    }

    // Write message to shared memory
    strcpy(shm, "Hello, World!");

    // Synchronous communication loop
    while (*shm != '*') {
        // Print message from shared memory
        for (s = shm; *s != '\0'; s++) {
            putchar(*s);
        }
        putchar('\n');

        // Wait for the other process to read message
        while (*shm != '%') {
            sleep(1);
        }

        // Write message to shared memory for other process to read
        strcpy(shm, "Goodbye, World!");
        *shm = '#';

        // Wait for the other process to acknowledge it received message
        while (*shm != '&') {
            sleep(1);
        }

        // Reset shared memory for next message
        *shm = '!';
    }

    // Detach shared memory segment
    if (shmdt(shm) == -1) {
        perror("shmdt");
        return 1;
    }

    // Delete the shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        return 1;
    }

    return 0;
}