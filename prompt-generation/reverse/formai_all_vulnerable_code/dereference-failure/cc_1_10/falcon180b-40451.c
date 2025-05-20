//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SIZE 100

int main() {
    int fd, shmid;
    char *shm;
    pid_t childpid;
    char *message = "Hello from parent process!";

    // Create a shared memory segment
    shmid = shmget(IPC_PRIVATE, SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach the shared memory segment
    shm = shmat(shmid, NULL, 0);
    if (shm == (void *) -1) {
        perror("shmat");
        exit(1);
    }

    // Fork a child process
    childpid = fork();
    if (childpid == 0) {
        // Child process
        printf("Child process started.\n");

        // Write a message to the shared memory segment
        strcpy(shm, message);

        // Detach the shared memory segment
        if (shmdt(shm) == -1) {
            perror("shmdt");
            exit(1);
        }

        // Exit the child process
        exit(0);
    } else {
        // Parent process
        printf("Parent process waiting for child to write message.\n");

        // Wait for the child process to finish
        waitpid(childpid, NULL, 0);

        // Read the message from the shared memory segment
        printf("Message from child: %s\n", shm);

        // Detach the shared memory segment
        if (shmdt(shm) == -1) {
            perror("shmdt");
            exit(1);
        }
    }

    return 0;
}