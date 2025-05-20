//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_ARGS 10

// Function to parse the command line into arguments
char **parse_args(char *line) {
    char **args = malloc(sizeof(char *) * MAX_ARGS);
    int i = 0;
    char *arg = strtok(line, " ");
    while (arg != NULL && i < MAX_ARGS) {
        args[i++] = arg;
        arg = strtok(NULL, " ");
    }
    args[i] = NULL;
    return args;
}

// Function to execute a command
int execute_command(char **args) {
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        execvp(args[0], args);
        // If execvp fails, print an error message and exit
        perror("execvp");
        exit(1);
    } else if (pid > 0) {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
        return status;
    } else {
        // Error forking
        perror("fork");
        return -1;
    }
}

// Function to run the shell loop
void shell_loop() {
    char *line;
    char **args;
    int status;

    // Run the shell loop until the user enters "exit"
    while (1) {
        // Print the prompt
        printf("osh> ");

        // Read the command line from the user
        size_t len = 0;
        getline(&line, &len, stdin);

        // Parse the command line into arguments
        args = parse_args(line);

        // Execute the command
        status = execute_command(args);

        // Free the memory allocated for the arguments
        free(args);

        // Check if the user entered "exit"
        if (strcmp(args[0], "exit") == 0) {
            break;
        }
    }

    // Free the memory allocated for the line
    free(line);
}

// Main function
int main() {
    // Run the shell loop
    shell_loop();

    return 0;
}