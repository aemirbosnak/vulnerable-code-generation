//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 100

void parentProcess(int pipe1[], int pipe2[]);
void childProcess(int pipe1[], int pipe2[]);

int main() {
    // Creating two pipes: one for parent to child, one for child to parent
    int pipe1[2], pipe2[2];

    if (pipe(pipe1) == -1 || pipe(pipe2) == -1) {
        perror("pipe failed");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) {
        // Parent process
        parentProcess(pipe1, pipe2);
    } else {
        // Child process
        childProcess(pipe1, pipe2);
    }

    return 0;
}

void parentProcess(int pipe1[], int pipe2[]) {
    char message[BUFFER_SIZE] = "Hello from the Parent!";
    char response[BUFFER_SIZE];

    // Close unused ends of pipes
    close(pipe1[0]); // Close read end of pipe1
    close(pipe2[1]); // Close write end of pipe2

    // Write the message to the child
    write(pipe1[1], message, strlen(message) + 1);
    printf("Parent: Sent message: %s\n", message);

    // Wait for the child to finish
    wait(NULL);

    // Read response from the child
    read(pipe2[0], response, BUFFER_SIZE);
    printf("Parent: Received response: %s\n", response);

    // Close remaining pipe ends
    close(pipe1[1]); // Close write end of pipe1
    close(pipe2[0]); // Close read end of pipe2
}

void childProcess(int pipe1[], int pipe2[]) {
    char message[BUFFER_SIZE];

    // Close unused ends of pipes
    close(pipe1[1]); // Close write end of pipe1
    close(pipe2[0]); // Close read end of pipe2

    // Read the message from the parent
    read(pipe1[0], message, BUFFER_SIZE);
    printf("Child: Received message: %s\n", message);

    // Modify the message for response
    char response[BUFFER_SIZE];
    snprintf(response, BUFFER_SIZE, "%s – modified by Child!", message);

    // Send the response back to the parent
    write(pipe2[1], response, strlen(response) + 1);
    printf("Child: Sending response: %s\n", response);

    // Close remaining pipe ends
    close(pipe1[0]); // Close read end of pipe1
    close(pipe2[1]); // Close write end of pipe2
}