//GEMINI-pro DATASET v1.0 Category: System administration ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>

// Custom data structure to store command and its arguments
typedef struct {
    char *command;
    char **args;
    int arg_count;
} Command;

// Function to free the memory allocated for a command
void free_command(Command *cmd) {
    free(cmd->command);
    for (int i = 0; i < cmd->arg_count; i++) {
        free(cmd->args[i]);
    }
    free(cmd->args);
    free(cmd);
}

// Function to execute a single command
int execute_command(Command *cmd) {
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        execvp(cmd->command, cmd->args);
        perror("execvp failed");
        exit(1);
    } else if (pid > 0) {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
        return status;
    } else {
        // Fork failed
        perror("fork failed");
        return -1;
    }
}

// Main function that reads input and executes commands
int main() {
    // Read input until EOF
    char *line = NULL;
    size_t line_len = 0;
    while (getline(&line, &line_len, stdin) != -1) {
        // Parse input into a command and its arguments
        Command *cmd = malloc(sizeof(Command));
        char *token = strtok(line, " ");
        cmd->command = strdup(token);
        cmd->arg_count = 0;
        while ((token = strtok(NULL, " ")) != NULL) {
            cmd->arg_count++;
            cmd->args = realloc(cmd->args, cmd->arg_count * sizeof(char *));
            cmd->args[cmd->arg_count - 1] = strdup(token);
        }

        // Execute the command
        int status = execute_command(cmd);

        // Check if the command executed successfully
        if (status == 0) {
            printf("Command executed successfully\n");
        } else {
            printf("Command failed with status %d\n", status);
        }

        // Free the memory allocated for the command
        free_command(cmd);
    }

    // Free the memory allocated for the input line
    free(line);

    return 0;
}