//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

// Maximum command length
#define MAX_CMD_LEN 1024

// Maximum number of arguments
#define MAX_ARGS 32

// Structure to store a command
typedef struct {
    char *cmd;
    char *args[MAX_ARGS];
} Command;

// Function to parse a command line
Command *parse_command(char *line) {
    Command *cmd = malloc(sizeof(Command));
    char *ptr = line;

    // Get the command
    cmd->cmd = strtok(ptr, " ");

    // Get the arguments
    int i = 0;
    while ((cmd->args[i] = strtok(NULL, " ")) != NULL) {
        i++;
    }

    return cmd;
}

// Function to execute a command
int execute_command(Command *cmd) {
    // Fork a child process
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return -1;
    }

    // If child process, execute the command
    if (pid == 0) {
        // Replace the current process with the command
        execvp(cmd->cmd, cmd->args);

        // If execvp fails, print an error message and exit
        perror("execvp");
        exit(1);
    }

    // If parent process, wait for the child process to finish
    int status;
    waitpid(pid, &status, 0);

    // Return the exit status of the child process
    return WEXITSTATUS(status);
}

// Function to run the shell
int main() {
    // Main loop
    while (1) {
        // Print the prompt
        printf("> ");

        // Get the command line
        char line[MAX_CMD_LEN];
        if (fgets(line, MAX_CMD_LEN, stdin) == NULL) {
            break;
        }

        // Parse the command line
        Command *cmd = parse_command(line);

        // Execute the command
        int status = execute_command(cmd);

        // Free the command
        free(cmd);

        // Check the exit status of the command
        if (status != 0) {
            fprintf(stderr, "Error: %d\n", status);
        }
    }

    return 0;
}