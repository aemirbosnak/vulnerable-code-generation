//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

#define MAX_LENGTH 1024 // Maximum length of command input
#define MAX_ARGS 100 // Maximum number of arguments in command

int main() {
    char command[MAX_LENGTH]; // Buffer to hold user's command input
    char *args[MAX_ARGS]; // Array to hold arguments from command input

    while(1) { // Loop to keep taking command inputs until user exits
        printf("MyShell> "); // Print prompt
        fflush(stdout); // Clear output buffer

        // Read user input
        fgets(command, MAX_LENGTH, stdin);
        command[strcspn(command, "\n")] = 0; // Remove newline from end of input

        // Tokenize command input into separate arguments
        int i = 0;
        char *token = strtok(command, " ");
        while(token != NULL) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL; // End argument array with NULL

        // Check if user wants to exit shell
        if(strcmp(args[0], "exit") == 0) {
            exit(0);
        }

        pid_t pid = fork(); // Fork process
        if(pid == 0) { // Child process
            execvp(args[0], args); // Execute command
            printf("%s: command not found\n", args[0]); // Print error message if command not found
            exit(1); // Exit child process with failure
        } else if(pid < 0) { // Error forking process
            printf("Error forking process\n");
        } else { // Parent process
            wait(NULL); // Wait for child process to finish
        }
    }   
    
    return 0;
}