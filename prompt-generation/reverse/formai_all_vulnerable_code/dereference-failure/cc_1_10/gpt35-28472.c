//FormAI DATASET v1.0 Category: Interprocess communication ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHM_SIZE 1024

int main() {
    int shmid;
    key_t key;
    char *shm, *s;

    // Generate a key for shared memory segment
    if ((key = ftok("ipc_example.c", 'R')) == -1) { 
        perror("ftok");
        exit(1);
    }

    // Create the shared memory segment
    if ((shmid = shmget(key, SHM_SIZE, 0644 | IPC_CREAT)) == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach the shared memory to our data space
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Write a message to the shared memory
    char message[SHM_SIZE];
    printf("Enter a message to share: ");
    fgets(message, SHM_SIZE, stdin);
    strncpy(shm, message, SHM_SIZE);

    // Fork a child process
    pid_t pid = fork();

    if (pid < 0) { // Failed to fork
        perror("fork");
        exit(1);
    } else if (pid == 0) { // Child process
        printf("Child process is waiting for the message...\n");
        sleep(2);

        // Read the message from the shared memory
        printf("Child process received message: ");
        for (s = shm; *s != '\0'; s++)
            putchar(*s); // Print the message character by character
        putchar('\n');

        // Detach the shared memory segment
        if (shmdt(shm) == -1) {
            perror("shmdt");
            exit(1);
        }

        // Mark the shared memory segment for deletion
        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            perror("shmctl");
            exit(1);
        }

        printf("Child process is done.\n");
        exit(0);
    } else { // Parent process
        printf("Parent process is waiting for the child process...\n");
        wait(NULL);

        // Detach the shared memory segment
        if (shmdt(shm) == -1) {
            perror("shmdt");
            exit(1);
        }

        printf("Parent process is done.\n");
        exit(0);
    }

    return 0;
}