//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_BUFFER 100

void modify_message(char* message) {
    // Transform the message to uppercase
    for (int i = 0; message[i] != '\0'; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = message[i] - ('a' - 'A');
        }
    }
}

int main() {
    int pipe1[2]; // For parent to child communication
    int pipe2[2]; // For child to parent communication
    pid_t pid;
    char message[MAX_BUFFER];
    char buffer[MAX_BUFFER];

    // Create the pipes
    if (pipe(pipe1) == -1) {
        perror("Pipe1 creation failed");
        exit(EXIT_FAILURE);
    }
    if (pipe(pipe2) == -1) {
        perror("Pipe2 creation failed");
        exit(EXIT_FAILURE);
    }

    // Create the child process
    pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }
    
    if (pid > 0) { // Parent process
        // Close unused ends of the pipes
        close(pipe1[0]); // Close reading end of pipe1
        close(pipe2[1]); // Close writing end of pipe2

        // Prepare the message to send to the child
        snprintf(message, sizeof(message), "Hello, child process!");
        write(pipe1[1], message, strlen(message) + 1); // Send message to child

        // Wait for child to finish
        wait(NULL);
        
        // Read modified message from child
        read(pipe2[0], buffer, sizeof(buffer));
        printf("Parent received: %s\n", buffer);

        // Close the writing end of pipe1 and reading end of pipe2
        close(pipe1[1]);
        close(pipe2[0]);
    } 
    else { // Child process
        // Close unused ends of the pipes
        close(pipe1[1]); // Close writing end of pipe1
        close(pipe2[0]); // Close reading end of pipe2

        // Read message from parent
        read(pipe1[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);

        // Modify the received message
        modify_message(buffer);
        
        // Send the modified message back to the parent
        write(pipe2[1], buffer, strlen(buffer) + 1);
    
        // Close the reading end of pipe1 and writing end of pipe2
        close(pipe1[0]);
        close(pipe2[1]);
    }

    return 0;
}