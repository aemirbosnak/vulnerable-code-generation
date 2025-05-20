//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024
#define CHILD_READ_FD 0
#define CHILD_WRITE_FD 1
#define PARENT_READ_FD 0
#define PARENT_WRITE_FD 1

// Function to handle errors
void error_handling(char* message) {
    perror(message);
    exit(1);
}

// Function to send data from parent to child
void send_data(int fd, char* data) {
    write(fd, data, strlen(data));
}

// Function to receive data from child to parent
void receive_data(int fd, char* buffer) {
    memset(buffer, 0, BUFFER_SIZE);
    read(fd, buffer, BUFFER_SIZE);
    printf("Received data from child: %s\n", buffer);
}

// Function to run child process
void child_process(int fd) {
    char buffer[BUFFER_SIZE];

    // Receive data from parent
    memset(buffer, 0, BUFFER_SIZE);
    read(fd, buffer, BUFFER_SIZE);
    printf("Received data from parent: %s\n", buffer);

    // Send data back to parent
    send_data(fd, "Child process completed successfully!");

    // Close file descriptors
    close(fd);
}

int main() {
    int fd[2]; // File descriptors for interprocess communication

    // Create pipe for interprocess communication
    if (pipe(fd) == -1) {
        error_handling("Pipe failed");
    }

    pid_t child_pid;

    // Fork a child process
    if ((child_pid = fork()) == -1) {
        error_handling("Fork failed");
    } else if (child_pid == 0) {
        // Child process
        close(fd[CHILD_READ_FD]);
        child_process(fd[CHILD_WRITE_FD]);
        exit(0);
    } else {
        // Parent process
        close(fd[CHILD_WRITE_FD]);
        receive_data(fd[PARENT_READ_FD], "Data sent to child process");
        wait(NULL);
        close(fd[PARENT_READ_FD]);
    }

    return 0;
}