//FormAI DATASET v1.0 Category: Interprocess communication ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main() {
    int shmid;
    key_t key;
    char *shm, *s;

    // Generate a unique key for the shared memory segment
    if ((key = ftok(".", 'R')) == -1) {
        perror("ftok");
        exit(1);
    }

    // Create the shared memory segment and attach to it
    if ((shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Write to the shared memory segment
    memset(shm, 0, SHM_SIZE);
    sprintf(shm, "Hello, World!");

    // Create a child process to read from the shared memory segment
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process reads from the shared memory segment
        s = shm;
        while (*s == '\0') {
            sleep(1);
        }
        printf("Child process read from shared memory: %s\n", s);
        _exit(0);
    } else {
        // Parent process waits for child to finish
        wait(NULL);
        printf("Parent process finished waiting for child.\n");
    }

    // Detach from the shared memory segment and remove it
    if (shmdt(shm) == -1) {
        perror("shmdt");
        exit(1);
    }
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}