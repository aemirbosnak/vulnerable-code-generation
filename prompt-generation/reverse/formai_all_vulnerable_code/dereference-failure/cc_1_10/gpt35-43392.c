//FormAI DATASET v1.0 Category: System administration ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024

int main() {
    char command[MAX_COMMAND_LENGTH]; // Maximum command length is 1024 characters
    printf("Welcome to the System Administration Example Program!\n");
    printf("Please enter your command:\n");

    // Loop indefinitely until the user enters "exit"
    while (1) {
        printf("> ");
        fflush(stdout); // Flush stdout to ensure the prompt is printed

        // Read in the user's command
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        // Remove the newline character at the end of the command string
        command[strcspn(command, "\n")] = '\0';

        // If the user entered "exit", exit the program
        if (strcmp(command, "exit") == 0) {
            printf("Exiting the program...\n");
            exit(0); // Exit with code 0 to indicate successful termination
        }

        // Execute the user's command using the system() function
        int status = system(command);

        // Check the exit status of the command
        if (status == -1) {
            // If system() returns -1, an error occurred
            printf("Failed to execute command: %s\n", strerror(errno));
        } else if (WIFEXITED(status)) {
            // If WIFEXITED() returns true, the command exited normally
            printf("Command exited with status %d\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            // If WIFSIGNALED() returns true, the command was terminated by a signal
            printf("Command terminated by signal %d\n", WTERMSIG(status));
        } else if (WIFSTOPPED(status)) {
            // If WIFSTOPPED() returns true, the command was stopped by a signal
            printf("Command stopped by signal %d\n", WSTOPSIG(status));
        }
    }
    return 0;
}