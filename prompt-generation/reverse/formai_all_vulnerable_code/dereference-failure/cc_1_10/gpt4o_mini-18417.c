//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define READ_END 0
#define WRITE_END 1
#define BUFFER_SIZE 256

void handleError(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int main() {
    int pipe1[2]; // Parent to child
    int pipe2[2]; // Child to parent
    pid_t pid;
    
    // Create the pipes
    if (pipe(pipe1) == -1) {
        handleError("Failed to create pipe1");
    }
    if (pipe(pipe2) == -1) {
        handleError("Failed to create pipe2");
    }

    pid = fork();
    if (pid < 0) {
        handleError("Failed to fork");
    }

    // Child Process
    if (pid == 0) {
        char readBuffer[BUFFER_SIZE];
        char responseBuffer[BUFFER_SIZE];

        // Close unused ends
        close(pipe1[WRITE_END]);
        close(pipe2[READ_END]);

        // Read from pipe1 (parent to child)
        if (read(pipe1[READ_END], readBuffer, BUFFER_SIZE) < 0) {
            handleError("Child: Failed to read from pipe1");
        }
        printf("Child received: %s\n", readBuffer);
        
        // Create a response message
        snprintf(responseBuffer, BUFFER_SIZE, "Hello from child!");
        
        // Write response back to parent
        if (write(pipe2[WRITE_END], responseBuffer, strlen(responseBuffer) + 1) < 0) {
            handleError("Child: Failed to write to pipe2");
        }

        // Close pipes before exiting
        close(pipe1[READ_END]);
        close(pipe2[WRITE_END]);
        exit(EXIT_SUCCESS);
    }

    // Parent Process
    if (pid > 0) {
        char message[BUFFER_SIZE] = "Hello from parent!";
        char readBuffer[BUFFER_SIZE];

        // Close unused ends
        close(pipe1[READ_END]);
        close(pipe2[WRITE_END]);

        // Write message to child
        if (write(pipe1[WRITE_END], message, strlen(message) + 1) < 0) {
            handleError("Parent: Failed to write to pipe1");
        }

        // Read response from child
        if (read(pipe2[READ_END], readBuffer, BUFFER_SIZE) < 0) {
            handleError("Parent: Failed to read from pipe2");
        }
        printf("Parent received: %s\n", readBuffer);

        // Close pipes
        close(pipe1[WRITE_END]);
        close(pipe2[READ_END]);

        // Wait for child to finish
        wait(NULL);
    }

    return 0;
}