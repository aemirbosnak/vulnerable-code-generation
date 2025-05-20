//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: asynchronous
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define BUFFER_SIZE 1024

int main() {
    int shmid;
    int fds[2];
    char buffer[BUFFER_SIZE];

    // Create a shared memory segment
    shmid = shmget(IPC_PRIVATE, BUFFER_SIZE, IPC_CREAT | 0644);
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // Create a pipe for asynchronous communication
    if (pipe(fds) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Fork a child process
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    // In parent process, write to shared memory and wait for child process to read
    if (pid > 0) {
        char *message = "Hello, child!";
        write(shmid, message, strlen(message));
        wait(NULL);
    }

    // In child process, read from shared memory and write to pipe
    else {
        char buffer[BUFFER_SIZE];
        read(shmid, buffer, BUFFER_SIZE);
        write(fds[1], buffer, strlen(buffer));
        exit(EXIT_SUCCESS);
    }

    return 0;
}