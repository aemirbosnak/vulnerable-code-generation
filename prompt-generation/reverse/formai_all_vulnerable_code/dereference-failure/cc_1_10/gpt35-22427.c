//FormAI DATASET v1.0 Category: Interprocess communication ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHMSIZE 27 // Size of shared memory segment

int main()
{
    int shmid; // Shared memory id
    key_t key; // Key for shared memory
    char *shm, *s; // Shared memory segment

    // Generate key for shared memory
    if ((key = ftok(".", 'R')) == -1) {
        perror("ftok");
        exit(1);
    }

    // Create shared memory segment
    if ((shmid = shmget(key, SHMSIZE, IPC_CREAT | 0666)) == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory segment to process
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Write to shared memory segment
    s = shm;
    for (char c = 'a'; c <= 'z'; c++) {
        *s++ = c;
    }
    *s = '\0';

    // Create child process
    pid_t pid = fork();

    if (pid == 0) {
        // Child process reads from shared memory segment
        printf("Child process reads from shared memory segment: ");
        for (s = shm; *s != '\0'; s++) {
            putchar(*s);
        }
        putchar('\n');
        exit(0);
    } else if (pid > 0) {
        // Parent process waits for child process to complete
        wait(NULL);

        // Parent process overwrites shared memory segment
        s = shm;
        for (char c = 'A'; c <= 'Z'; c++) {
            *s++ = c;
        }
        *s = '\0';

        // Parent process reads from shared memory segment
        printf("Parent process overwrites and reads from shared memory segment: ");
        for (s = shm; *s != '\0'; s++) {
            putchar(*s);
        }
        putchar('\n');

        // Detach and remove shared memory segment
        shmdt(shm);
        shmctl(shmid, IPC_RMID, NULL);
    } else {
        perror("fork");
        exit(1);
    }

    return 0;
}