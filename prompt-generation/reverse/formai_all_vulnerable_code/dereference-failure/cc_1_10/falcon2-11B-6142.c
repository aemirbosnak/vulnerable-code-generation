//Falcon2-11B DATASET v1.0 Category: Interprocess communication ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

// Create a pipe for client-server communication
int pipe_fd[2];

// Function to create a child process
void child_process(int child_pid) {
    // Read from pipe and write to stdout
    while (1) {
        if (read(pipe_fd[0], stdout, 1)!= 1) {
            break;
        }
    }
    // Exit child process
    exit(0);
}

// Function to create a parent process
void parent_process(int parent_pid) {
    // Create child process
    if (fork() == 0) {
        // Child process
        child_process(parent_pid);
    } else {
        // Parent process
        close(pipe_fd[0]);
        int fd = open("server.txt", O_CREAT | O_WRONLY, 0644);
        dup2(fd, 1);
        close(fd);
        // Write to pipe and read from stdin
        while (1) {
            if (write(pipe_fd[1], stdin, 1)!= 1) {
                break;
            }
        }
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <parent or child>\n", argv[0]);
        return 1;
    }

    int parent_pid = atoi(argv[1]);

    if (parent_pid == 0) {
        // Create parent process
        parent_process(parent_pid);
    } else {
        // Create child process
        int child_pid = fork();
        if (child_pid == 0) {
            // Child process
            child_process(parent_pid);
        } else {
            // Parent process
            wait(NULL);
        }
    }

    return 0;
}