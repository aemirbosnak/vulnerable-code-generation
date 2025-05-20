//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define BUFFER_SIZE 100

// Function to send data through pipe
void send_data(int fd, char *data) {
    int bytes_sent = 0;
    while (bytes_sent < strlen(data)) {
        int result = write(fd, data + bytes_sent, BUFFER_SIZE);
        if (result <= 0) {
            if (errno == EINTR) {
                continue;
            } else {
                printf("Error sending data: %s\n", strerror(errno));
                exit(1);
            }
        }
        bytes_sent += result;
    }
}

// Function to receive data from pipe
void receive_data(int fd, char *buffer) {
    int bytes_received = 0;
    while (bytes_received < BUFFER_SIZE) {
        int result = read(fd, buffer + bytes_received, BUFFER_SIZE - bytes_received);
        if (result <= 0) {
            if (errno == EINTR) {
                continue;
            } else {
                printf("Error receiving data: %s\n", strerror(errno));
                exit(1);
            }
        }
        bytes_received += result;
    }
    buffer[bytes_received] = '\0';
}

// Function to perform interprocess communication
void interprocess_communication(int pipe_fd[2]) {
    char data[BUFFER_SIZE];
    char buffer[BUFFER_SIZE];

    // Parent process writes data to pipe
    if (fork() == 0) {
        strcpy(data, "Hello from child process!");
        send_data(pipe_fd[1], data);
        close(pipe_fd[1]);
        exit(0);
    } else {
        wait(NULL);

        // Parent process reads data from pipe
        receive_data(pipe_fd[0], buffer);
        close(pipe_fd[0]);
        printf("Received data: %s\n", buffer);
    }
}

int main() {
    int pipe_fd[2];

    // Create pipe
    if (pipe(pipe_fd) == -1) {
        printf("Error creating pipe: %s\n", strerror(errno));
        exit(1);
    }

    // Perform interprocess communication
    interprocess_communication(pipe_fd);

    return 0;
}