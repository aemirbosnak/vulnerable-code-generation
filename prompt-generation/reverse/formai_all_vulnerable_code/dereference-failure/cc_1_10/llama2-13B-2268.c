//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

// Structure to store the shared memory block
struct shared_memory {
    char message[BUFFER_SIZE];
};

// Function to create and attach to a shared memory block
void create_shared_memory(void) {
    key_t key = IPC_PRIVATE;
    int shm_id = shmget(key, BUFFER_SIZE, IPC_CREAT | 0644);
    if (shm_id == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // Attach to the shared memory block
    struct shared_memory *shm = shmat(shm_id, NULL, 0);
    if (shm == (struct shared_memory *) -1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    // Set the message in the shared memory block
    strcpy(shm->message, "Hello, world!");
}

// Function to communicate between processes using shared memory
void communicate(void) {
    // Create a pipe for communication
    int pipe_fd[2];
    if (pipe(pipe_fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Fork a new process to read from the shared memory block
    pid_t pid = fork();
    if (pid == 0) {
        // Child process reads from the shared memory block
        char message[BUFFER_SIZE];
        read(pipe_fd[0], message, BUFFER_SIZE);
        printf("Received message: %s\n", message);
    } else {
        // Parent process writes to the shared memory block
        char message[] = "Hello, world!";
        write(pipe_fd[1], message, strlen(message));
    }

    // Wait for the child process to finish
    wait(NULL);
}

int main(void) {
    create_shared_memory();
    communicate();
    return 0;
}