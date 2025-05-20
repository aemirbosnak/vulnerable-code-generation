//FormAI DATASET v1.0 Category: Interprocess communication ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024 // Size of shared memory

int main()
{
    int shmid; // Shared memory ID
    key_t key = 1234; // Key to access shared memory
    char *shm, *s; // Pointers to shared memory and characters in memory
    int status; // Status variable
    
    // Create shared memory segment
    if ((shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    // Attach to shared memory segment
    if ((shm = shmat(shmid, NULL, 0)) == (char *) - 1) {
        perror("shmat");
        exit(1);
    }

    // Write message to shared memory
    char message[] = "Hello World!";
    memcpy(shm, message, sizeof(message));

    // Fork child process
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) { // Child process reads from shared memory
        s = shm;
        for (s = shm; *s != 0; s++)
            putchar(*s);
        putchar('\n');
        exit(0);
    } else { // Parent process waits for child process to finish
        wait(&status);
    }

    // Detach from shared memory segment
    if (shmdt(shm) == -1) {
        perror("shmdt");
        exit(1);
    }

    // Destroy shared memory segment
    if (shmctl(shmid, IPC_RMID, 0) == -1) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}