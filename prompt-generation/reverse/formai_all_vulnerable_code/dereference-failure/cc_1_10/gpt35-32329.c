//FormAI DATASET v1.0 Category: Interprocess communication ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHMSIZE 100

int main() {
    int shmid;
    key_t key;
    char *shm, *s;

    key = 1234; // Sets the key value to access the shared memory

    if ((shmid = shmget(key, SHMSIZE, IPC_CREAT | 0666)) < 0) { // Creates a shared memory segment
        perror("shmget");
        exit(1);
    }

    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) { // Attaches the shared memory segment to process's address space
        perror("shmat");
        exit(1);
    }

    printf("Enter message to be passed between processes: ");
    fgets(s, SHMSIZE, stdin);

    // Writing the data into the shared memory
    s = shm;
    // Copying the message into the shared memory
    for (int i = 0; s[i] != '\0'; i++) {
        *shm++ = *s++;
    }
    *shm = '\0';

    pid_t pid = fork(); // Creating a child process

    if (pid < 0) {
        perror("fork");
        exit(1);
    } else if (pid == 0) { // Child Process
        printf("Child process is reading the shared memory\n");

        // Reading the data from the shared memory
        s = shm;
        while (*s != '\0') {
            putchar(*s);
            s++;
        }
        putchar('\n');

        // Detaching the shared memory
        if (shmdt(shm) == -1) {
            perror("shmdt");
            exit(1);
        }

        // Deleting the shared memory segment
        if (shmctl(shmid, IPC_RMID, 0) == -1) {
            perror("shmctl");
            exit(1);
        }
    } else { // Parent Process
        wait(NULL); // Waiting for the child process to finish
    }

    return 0;
}