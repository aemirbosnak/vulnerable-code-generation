//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/ipc.h>

#define BUFFER_SIZE 1024

// Declare the shared memory segment
static int shm_id = -1;
static char *shm_addr = NULL;

// Declare the pipe for communication
static int pipe_fd[2] = { -1, -1 };

void create_shm(void) {
    // Create a new shared memory segment
    shm_id = shmget(IPC_PRIVATE, BUFFER_SIZE, IPC_CREAT | 0644);
    if (shm_id < 0) {
        perror("shmget() failed");
        exit(EXIT_FAILURE);
    }

    // Map the shared memory segment to the address space
    shm_addr = mmap(NULL, BUFFER_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_id, 0);
    if (shm_addr == MAP_FAILED) {
        perror("mmap() failed");
        exit(EXIT_FAILURE);
    }
}

void send_message(const char *message) {
    // Write the message to the shared memory segment
    char *ptr = shm_addr;
    strcpy(ptr, message);
}

char *receive_message(void) {
    // Read the message from the shared memory segment
    char *ptr = shm_addr;
    return ptr;
}

int main(void) {
    // Create the shared memory segment and pipe
    create_shm();
    pipe_fd[0] = pipe(pipe_fd);
    if (pipe_fd[0] < 0) {
        perror("pipe() failed");
        exit(EXIT_FAILURE);
    }

    // Fork a new process to read from the shared memory segment
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork() failed");
        exit(EXIT_FAILURE);
    }
    if (pid == 0) {
        // Child process reads from the shared memory segment
        char *message = receive_message();
        printf("Received message: %s\n", message);
        exit(EXIT_SUCCESS);
    } else {
        // Parent process writes to the shared memory segment
        send_message("Hello, world!");
        wait(NULL);
    }

    return 0;
}