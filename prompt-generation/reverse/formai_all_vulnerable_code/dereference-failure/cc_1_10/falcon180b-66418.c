//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define SIZE 100

char buffer[SIZE];
int fd[2];

// Function to create a pipe
void create_pipe() {
    if (pipe(fd) == -1) {
        printf("Error creating pipe\n");
        exit(1);
    }
}

// Function to write data to the pipe
void write_to_pipe(int fd, char *data) {
    int n = strlen(data);
    write(fd, data, n);
}

// Function to read data from the pipe
void read_from_pipe(int fd, char *buffer) {
    int n = read(fd, buffer, SIZE);
    buffer[n] = '\0';
}

int main() {
    create_pipe();

    // Fork a child process
    pid_t pid = fork();

    if (pid == -1) {
        printf("Error forking\n");
        exit(1);
    } else if (pid == 0) {
        // Child process
        close(fd[0]);
        write_to_pipe(fd[1], "Hello from child process");
        close(fd[1]);
    } else {
        // Parent process
        close(fd[1]);
        read_from_pipe(fd[0], buffer);
        printf("Received message: %s\n", buffer);
        close(fd[0]);
    }

    return 0;
}