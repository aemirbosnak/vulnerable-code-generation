//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/shm.h>

#define MESSAGE_SIZE 1024

int main() {
    // Create a shared memory segment
    int shmid = shmget(IPC_PRIVATE, MESSAGE_SIZE, IPC_CREAT | 0644);
    if (shmid < 0) {
        perror("shmget() failed");
        return 1;
    }

    // Attach to the shared memory segment
    char *shm = shmat(shmid, NULL, 0);
    if (shm == (char *) -1) {
        perror("shmat() failed");
        return 1;
    }

    // Write a message to the shared memory
    char message[MESSAGE_SIZE];
    strcpy(message, "Hello from the parent process!");
    memcpy(shm, message, strlen(message));

    // Create a new process
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork() failed");
        return 1;
    }

    // In the child process, read the message from the shared memory
    if (pid > 0) {
        // Child process
        char *msg = shm;
        printf("Received message: %s\n", msg);
    } else {
        // Parent process
        char *msg = shm;
        printf("Sent message: %s\n", msg);
    }

    // Exit the child process
    if (pid > 0) {
        exit(0);
    }

    // Unmap the shared memory segment
    shmctl(shmid, IPC_RMID, 0);

    return 0;
}