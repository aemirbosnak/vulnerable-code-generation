//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024

// Function to create a named pipe
int create_pipe(char *pipe_name) {
    int fd;
    if ((fd = mkfifo(pipe_name, 0666)) == -1) {
        printf("Error creating pipe: %s\n", strerror(errno));
        exit(1);
    }
    return fd;
}

// Function to write data to a named pipe
void write_to_pipe(int fd, char *data) {
    int bytes_written;
    if ((bytes_written = write(fd, data, strlen(data))) == -1) {
        printf("Error writing to pipe: %s\n", strerror(errno));
        exit(1);
    }
    printf("Wrote %d bytes to pipe\n", bytes_written);
}

// Function to read data from a named pipe
void read_from_pipe(int fd, char *buffer) {
    int bytes_read;
    if ((bytes_read = read(fd, buffer, BUFFER_SIZE)) == -1) {
        printf("Error reading from pipe: %s\n", strerror(errno));
        exit(1);
    }
    printf("Read %d bytes from pipe: %s\n", bytes_read, buffer);
}

int main() {
    char input[BUFFER_SIZE];
    char output[BUFFER_SIZE];

    // Create named pipe
    char pipe_name[] = "my_pipe";
    int pipe_fd = create_pipe(pipe_name);

    // Fork child process
    pid_t child_pid = fork();
    if (child_pid == -1) {
        printf("Error forking process: %s\n", strerror(errno));
        exit(1);
    } else if (child_pid == 0) {
        // Child process reads from pipe and writes to stdout
        close(pipe_fd);
        while (1) {
            read_from_pipe(0, input);
            printf("Child received message: %s\n", input);
        }
    } else {
        // Parent process writes to pipe and reads from stdin
        close(pipe_fd);
        while (1) {
            printf("Enter message to send: ");
            fgets(input, BUFFER_SIZE, stdin);
            write_to_pipe(0, input);
        }
    }

    return 0;
}