//FormAI DATASET v1.0 Category: Interprocess communication ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHM_SIZE 1024

int main() {
    int shmid;
    pid_t pid;
    char *shm, *s;

    // Create a shared memory segment
    if ((shmid = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        return 1;
    }

    // Attach the shared memory segment
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        return 1;
    }

    // Fork a child process
    if ((pid = fork()) < 0) {
        perror("fork");
        return 1;
    } else if (pid == 0) {  // Child process
        char *msg = "Hello, parent process!\n";
        strcpy(shm, msg);  // Write a message to the shared memory
        exit(0);
    } else {  // Parent process
        wait(NULL);  // Wait for the child to finish
        for (s = shm; *s != '\0'; s++)  // Read the message from the shared memory
            putchar(*s);
        putchar('\n');
    }

    // Detach the shared memory segment
    if (shmdt(shm) < 0) {
        perror("shmdt");
        return 1;
    }

    // Remove the shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) < 0) {
        perror("shmctl");
        return 1;
    }

    return 0;
}