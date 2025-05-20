//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LINE 80 // Maximum length for a command line
#define MAX_ARGS 10 // Maximum arguments for a command

int main() {
    char *args[MAX_ARGS]; // Array to store command line arguments
    char cmd[MAX_LINE]; // String to store command line input
    int should_run = 1; // Flag to control the program loop

    while(should_run) {
        printf("osh> "); // Print shell prompt
        fflush(stdout); // Flush output buffer to make sure prompt is printed

        fgets(cmd, MAX_LINE, stdin); // Read input from user

        // Remove newline character from end of input
        if (cmd[strlen(cmd)-1] == '\n')
            cmd[strlen(cmd)-1] = '\0';

        // Parse input into argument array
        char *token = strtok(cmd, " ");
        int i = 0;

        while(token != NULL && i < MAX_ARGS - 1) {
            args[i] = token;
            i++;
            token = strtok(NULL, " ");
        }

        args[i] = NULL; // Make last argument NULL for execvp()

        // Check if user entered "exit" command
        if(strcmp(args[0], "exit") == 0) {
            should_run = 0; // Stop program loop
        }
        else {
            pid_t pid = fork(); // Create child process

            if(pid < 0) { // Forking failed
                printf("Forking failed\n");
                exit(1);
            }
            else if(pid == 0) { // Child process
                if(execvp(args[0], args) == -1) {
                    printf("Unknown command '%s'\n", args[0]);
                    exit(1);
                }
            }
            else { // Parent process
                wait(NULL); // Wait for child process to complete
            }
        }
    }

    return 0;
}