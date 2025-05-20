//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

// Function to send message through pipe
void send_message(int fd, char* message) {
    write(fd, message, strlen(message));
}

// Function to receive message through pipe
void receive_message(int fd, char* buffer) {
    read(fd, buffer, BUFFER_SIZE);
}

int main() {
    int fd[2]; // File descriptors for pipe communication
    pid_t child_pid; // Process ID of child process

    // Create pipe for interprocess communication
    if (pipe(fd) == -1) {
        fprintf(stderr, "Pipe failed: %s\n", strerror(errno));
        exit(1);
    }

    // Fork a new process
    child_pid = fork();

    if (child_pid == -1) { // Fork failed
        fprintf(stderr, "Fork failed: %s\n", strerror(errno));
        exit(1);
    } else if (child_pid == 0) { // Child process
        close(fd[0]); // Close reading end of pipe
        send_message(fd[1], "Hello from child process!");
        close(fd[1]); // Close writing end of pipe
        exit(0);
    } else { // Parent process
        close(fd[1]); // Close writing end of pipe
        char buffer[BUFFER_SIZE];
        receive_message(fd[0], buffer);
        printf("Received message: %s\n", buffer);
        close(fd[0]); // Close reading end of pipe
        wait(NULL); // Wait for child process to exit
    }

    return 0;
}