//Falcon2-11B DATASET v1.0 Category: Interprocess communication ; Style: portable
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

// Define the size of the buffer for communication
#define BUFFER_SIZE 1024

// Function to write data to a pipe
void write_data_to_pipe(int fd, char* data) {
    int bytes_written = write(fd, data, strlen(data));
    if (bytes_written == -1) {
        perror("write failed");
        exit(EXIT_FAILURE);
    }
}

// Function to read data from a pipe
char* read_data_from_pipe(int fd) {
    char* data = malloc(BUFFER_SIZE);
    int bytes_read = read(fd, data, BUFFER_SIZE);
    if (bytes_read == -1) {
        perror("read failed");
        exit(EXIT_FAILURE);
    }
    return data;
}

// Main function
int main() {
    // Create two pipes for communication
    int pipe_in[2];
    int pipe_out[2];
    if (pipe(pipe_in) == -1 || pipe(pipe_out) == -1) {
        perror("pipe failed");
        exit(EXIT_FAILURE);
    }

    // Fork the process
    pid_t child_pid = fork();
    if (child_pid == -1) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }

    // Child process
    if (child_pid == 0) {
        // Close the read end of the pipe
        close(pipe_in[0]);

        // Write data to the write end of the pipe
        char data[] = "Hello, parent!\n";
        write_data_to_pipe(pipe_out[1], data);
        exit(EXIT_SUCCESS);
    }

    // Parent process
    else {
        // Close the write end of the pipe
        close(pipe_out[1]);

        // Read data from the read end of the pipe
        char* data = read_data_from_pipe(pipe_in[0]);
        printf("Received data: %s\n", data);
        free(data);
        exit(EXIT_SUCCESS);
    }
}