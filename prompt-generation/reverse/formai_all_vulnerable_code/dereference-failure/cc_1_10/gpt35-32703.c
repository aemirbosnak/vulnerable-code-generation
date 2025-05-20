//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

#define MAX_LENGTH 1024 // Define the maximum length of the command

int main() {
    char command[MAX_LENGTH]; // Initialize the command buffer
    char* arguments[MAX_LENGTH/2 + 1]; // Initialize the arguments buffer
    int should_run = 1; // Initialize a variable to determine if the program should continue running
    pid_t pid; // Initialize a variable to store the process ID

    while (should_run) {
        printf("sh> "); // Print the shell prompt

        fflush(stdout); // Flush the output buffer

        fgets(command, MAX_LENGTH, stdin); // Read the command from standard input

        /* Parse the command */

        int num_arguments = 0; // Initialize the number of arguments

        arguments[num_arguments] = strtok(command, " \n"); // Parse the first argument

        while (arguments[num_arguments] != NULL) { // Parse the rest of the arguments
            num_arguments++;
            arguments[num_arguments] = strtok(NULL, " \n");
        }

        arguments[num_arguments] = NULL; // Set the last argument to NULL

        /* Execute the command */

        if (strcmp(arguments[0], "exit") == 0) { // If the command is "exit"
            should_run = 0; // Exit the while loop
        }
        else {
            pid = fork(); // Fork a child process

            if (pid < 0) { // If the fork failed
                fprintf(stderr, "Fork failed\n");
                exit(EXIT_FAILURE);
            }
            else if (pid == 0) { // If this is the child process
                if (execvp(arguments[0], arguments) == -1) { // Execute the command
                    fprintf(stderr, "Execution failed\n");
                    exit(EXIT_FAILURE);
                }
            }
            else { // If this is the parent process
                wait(NULL); // Wait for the child process to complete
            }
        }
    }

    return 0;
}