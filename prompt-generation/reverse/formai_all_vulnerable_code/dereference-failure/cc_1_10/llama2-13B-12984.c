//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 1024
#define PIPE_NAME "my_pipe"

// Structure to hold the message to be sent
typedef struct {
    char *message;
    int length;
} message_t;

// Function to send a message to the other process
void send_message(int fd[2], message_t *message) {
    write(fd[1], message->message, message->length);
}

// Function to receive a message from the other process
void receive_message(int fd[2], message_t *message) {
    read(fd[0], message->message, MAX_MESSAGE_LENGTH);
}

// Function to create the pipe and fork the process
pid_t create_pipe_and_fork(int *fd) {
    int fd_read[2];
    int fd_write[2];

    // Create the pipe
    pipe(fd_read);
    pipe(fd_write);

    // Fork the process
    pid_t pid = fork();

    // If the process is the parent, close the write end of the pipe
    if (pid > 0) {
        close(fd_write[1]);
    }

    // If the process is the child, close the read end of the pipe
    if (pid == 0) {
        close(fd_read[0]);
    }

    // Set the file descriptors
    *fd = fd_read[0];

    return pid;
}

int main() {
    int fd[2];
    message_t message = {"Hello from the other process!", 13};

    // Create the pipe and fork the process
    pid_t pid = create_pipe_and_fork(fd);

    // Send the message to the other process
    send_message(fd, &message);

    // Receive the message from the other process
    receive_message(fd, &message);

    // Wait for the other process to finish
    wait(NULL);

    return 0;
}