//Falcon2-11B DATASET v1.0 Category: Interprocess communication ; Style: realistic
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

// Function to create a named pipe
int create_pipe(const char* pipe_name) {
    int pipe_fd[2];
    if (pipe(pipe_fd) == -1) {
        perror("Error creating pipe");
        return -1;
    }
    if (chmod(pipe_name, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP) == -1) {
        perror("Error setting permissions on pipe");
        return -1;
    }
    return pipe_fd[0];
}

// Function to send data to the pipe
void send_data(int pipe_fd, const char* data) {
    write(pipe_fd, data, strlen(data));
}

// Function to receive data from the pipe
char* receive_data(int pipe_fd) {
    char buffer[256];
    ssize_t bytes_read;
    bytes_read = read(pipe_fd, buffer, sizeof(buffer));
    if (bytes_read == -1) {
        perror("Error reading from pipe");
        return NULL;
    }
    return buffer;
}

// Main function
int main() {
    const char* pipe_name = "my_pipe";
    int pipe_fd[2];
    if (create_pipe(pipe_name) == -1) {
        perror("Error creating pipe");
        return -1;
    }
    int child_pid = fork();
    if (child_pid == -1) {
        perror("Error forking");
        return -1;
    }
    if (child_pid == 0) {
        // Child process
        int input_fd = pipe_fd[1];
        close(pipe_fd[0]);
        char* data = receive_data(input_fd);
        printf("Child received data: %s\n", data);
        free(data);
        exit(0);
    } else {
        // Parent process
        int output_fd = pipe_fd[0];
        char* data = "Hello, parent!";
        send_data(output_fd, data);
        free(data);
        wait(NULL);
        printf("Parent received data: %s\n", receive_data(output_fd));
        close(output_fd);
        return 0;
    }
}