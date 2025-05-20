//FormAI DATASET v1.0 Category: System administration ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main() {
    char* command = NULL;
    size_t len = 0;
    ssize_t read;

    while(1) {
        // Print the prompt for the user to enter a command
        printf("Enter a command: ");

        // Read the command from the user
        read = getline(&command, &len, stdin);

        // Check if user wants to exit
        if(strncmp(command, "exit", 4) == 0) {
            printf("Exiting...\n");
            exit(0);
        }

        // Remove the newline character from the input
        char* pos;
        if((pos=strchr(command, '\n')) != NULL) {
            *pos = '\0';
        }

        // Create a new child process
        pid_t pid = fork();

        if(pid == -1) {
            // Error occurred creating the child process
            perror("fork");
            exit(1);
        } else if(pid == 0) {
            // Child process

            // Split the input command into an array of arguments
            char* args[10];
            char* token = strtok(command, " ");
            int i = 0;
            while(token != NULL) {
                args[i++] = token;
                token = strtok(NULL, " ");
            }
            args[i] = NULL;

            // Execute the command
            execvp(args[0], args);

            // If execvp returns, an error occurred
            perror("execvp");
            exit(1);
        } else {
            // Parent process
            int status;
            wait(&status);
        }
    }

    return 0;
}