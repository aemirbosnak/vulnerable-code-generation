//FormAI DATASET v1.0 Category: Interprocess communication ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHMSIZE 1024

int main() {
    key_t key;
    int shmid;
    char *data;
    char *shared_memory = (char *)0;

    // Create a unique key
    if ((key = ftok("ipcdemo.c", 'R')) == -1) {
        perror("ftok");
        exit(1);
    }

    // Create a shared memory segment
    if ((shmid = shmget(key, SHMSIZE, IPC_CREAT | 0666)) == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach to the shared memory segment
    if ((shared_memory = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Write to the shared memory segment
    sprintf(shared_memory, "Hello, World!");

    // Create a child process
    pid_t pid = fork();

    if (pid < 0) {  // fork failed
        perror("fork");
        exit(1);
    }
    else if (pid == 0) {  // child process
        printf("Child process is reading from shared memory: %s\n", shared_memory);

        // Append a message to the shared memory segment
        strcat(shared_memory, " This is the child process.");

        printf("Child process wrote to shared memory: %s\n", shared_memory);

        // Detach from the shared memory segment
        if (shmdt(shared_memory) == -1) {
            perror("shmdt");
            exit(1);
        }

        // Exit the child process
        exit(0);
    }
    else {  // parent process
        sleep(2);
        printf("Parent process is reading from shared memory: %s\n", shared_memory);

        // Append a message to the shared memory segment
        strcat(shared_memory, " This is the parent process.");

        printf("Parent process wrote to shared memory: %s\n", shared_memory);

        // Detach from the shared memory segment
        if (shmdt(shared_memory) == -1) {
            perror("shmdt");
            exit(1);
        }

        // Delete the shared memory segment
        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            perror("shmctl");
            exit(1);
        }
    }

    return 0;
}