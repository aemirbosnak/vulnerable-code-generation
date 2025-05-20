//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 128

void to_uppercase(char* str) {
    while (*str) {
        *str = toupper(*str);
        str++;
    }
}

int main() {
    int pipe1[2]; // Parent to child
    int pipe2[2]; // Child to parent
    pid_t pid;
    char buffer[BUFFER_SIZE];

    // Create pipes
    if (pipe(pipe1) == -1 || pipe(pipe2) == -1) {
        perror("Pipe failed");
        exit(EXIT_FAILURE);
    }

    // Create child process
    pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { // Child process
        close(pipe1[1]); // Close unused write end of pipe1
        close(pipe2[0]); // Close unused read end of pipe2

        // Read from parent
        read(pipe1[0], buffer, BUFFER_SIZE);
        printf("Child received: %s\n", buffer);

        // Convert to uppercase
        to_uppercase(buffer);
        
        // Send back to parent
        write(pipe2[1], buffer, strlen(buffer) + 1);
        close(pipe1[0]);
        close(pipe2[1]);
        exit(EXIT_SUCCESS);
    } else { // Parent process
        close(pipe1[0]); // Close unused read end of pipe1
        close(pipe2[1]); // Close unused write end of pipe2

        // Message to send to child
        char* message = "Hello from parent!";
        printf("Parent sending: %s\n", message);

        // Send message to child
        write(pipe1[1], message, strlen(message) + 1);
        
        // Wait for child to finish
        wait(NULL);

        // Read response from child
        read(pipe2[0], buffer, BUFFER_SIZE);
        printf("Parent received: %s\n", buffer);

        close(pipe1[1]);
        close(pipe2[0]);
    }

    return 0;
}