//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT 1024 // Maximum size of input

int main() {
    char input[MAX_INPUT]; // Buffer for user input

    while (1) {
        printf("shell> "); // Print the prompt
        fflush(stdout); // Flush stdout to force the prompt to be printed

        // Read the user's input
        fgets(input, MAX_INPUT, stdin);

        // Remove the newline character from the end of the input
        input[strcspn(input, "\n")] = '\0';

        // Split the input into an array of arguments
        char *args[100];
        char *arg = strtok(input, " ");
        int i = 0;
        while (arg != NULL) {
            args[i] = arg;
            i++;
            arg = strtok(NULL, " ");
        }
        args[i] = NULL;

        // Check if the user typed "exit"
        if (strcmp(args[0], "exit") == 0) {
            printf("Goodbye!\n");
            exit(0);
        }

        // Check if the user typed "cd"
        if (strcmp(args[0], "cd") == 0) {
            // Change the directory to the specified directory
            chdir(args[1]);
            continue;
        }

        // Fork a new process to execute the command
        pid_t pid = fork();
        if (pid < 0) {
            printf("Failed to fork a new process.\n");
            exit(1);
        } else if (pid == 0) {
            // Child process
            execvp(args[0], args);
            printf("Command not found: %s\n", args[0]);
            exit(1);
        } else {
            // Parent process
            // Wait for the child process to complete before continuing
            wait(NULL);
        }
    }

    return 0;
}