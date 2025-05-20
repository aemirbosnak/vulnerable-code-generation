//FormAI DATASET v1.0 Category: Interprocess communication ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024  // size of shared memory

int main() {
    printf("Welcome to the IPC program!\n");

    // create a shared memory segment
    key_t key = ftok(".", 'a');
    int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error: Failed to create shared memory segment.\n");
        exit(1);
    }
    printf("Shared memory segment created successfully.\n");

    // attach to the shared memory segment
    char *shm = shmat(shmid, NULL, 0);
    if (shm == (char *) -1) {
        printf("Error: Failed to attach to shared memory segment.\n");
        exit(1);
    }
    printf("Attached to shared memory segment successfully.\n");

    // write a message to the shared memory
    strcpy(shm, "Hello, world!");

    // fork a child process
    pid_t pid = fork();
    if (pid == -1) {
        printf("Error: Failed to fork a child process.\n");
        exit(1);
    } else if (pid == 0) {  // child process
        printf("Child process started.\n");

        // read the message from the shared memory
        printf("Message received from parent process: %s\n", shm);

        // detach from the shared memory segment
        if (shmdt(shm) == -1) {
            printf("Error: Failed to detach from shared memory segment.\n");
            exit(1);
        }
        printf("Detached from shared memory segment successfully.\n");
    } else {  // parent process
        printf("Parent process started.\n");

        // wait for child process to finish
        if (waitpid(pid, NULL, 0) == -1) {
            printf("Error: Failed to wait for child process.\n");
            exit(1);
        }

        // detach from the shared memory segment
        if (shmdt(shm) == -1) {
            printf("Error: Failed to detach from shared memory segment.\n");
            exit(1);
        }
        printf("Detached from shared memory segment successfully.\n");

        // remove the shared memory segment
        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            printf("Error: Failed to remove shared memory segment.\n");
            exit(1);
        }
        printf("Removed shared memory segment successfully.\n");
    }

    printf("Goodbye!\n");
    return 0;
}