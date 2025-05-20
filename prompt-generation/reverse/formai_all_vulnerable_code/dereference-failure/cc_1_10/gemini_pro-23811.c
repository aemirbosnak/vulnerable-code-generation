//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>

#define MAX_ARGS 10
#define MAX_LINE_LEN 100

// Define the structure of a command
typedef struct {
    char *argv[MAX_ARGS];
    int argc;
    pid_t pid;
} command_t;

// Define the structure of a shell
typedef struct {
    char *cwd;
    command_t *commands;
    int num_commands;
} shell_t;

// Initialize the shell
shell_t *init_shell() {
    shell_t *shell = malloc(sizeof(shell_t));
    shell->cwd = getcwd(NULL, 0);
    shell->commands = NULL;
    shell->num_commands = 0;
    return shell;
}

// Free the shell
void free_shell(shell_t *shell) {
    free(shell->cwd);
    for (int i = 0; i < shell->num_commands; i++) {
        free(shell->commands[i].argv);
    }
    free(shell->commands);
    free(shell);
}

// Parse the command line
command_t *parse_command(char *line) {
    command_t *command = malloc(sizeof(command_t));
    command->argc = 0;
    char *token = strtok(line, " ");
    while (token != NULL) {
        command->argv[command->argc] = token;
        command->argc++;
        token = strtok(NULL, " ");
    }
    return command;
}

// Execute the command
void execute_command(command_t *command) {
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        execvp(command->argv[0], command->argv);
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        // Parent process
        command->pid = pid;
    } else {
        // Fork failed
        perror("fork");
    }
}

// Wait for the command to finish
int wait_for_command(command_t *command) {
    int status;
    waitpid(command->pid, &status, 0);
    return status;
}

// Run the shell
void run_shell(shell_t *shell) {
    while (1) {
        // Print the prompt
        printf("%s $ ", shell->cwd);

        // Read the command line
        char line[MAX_LINE_LEN];
        fgets(line, MAX_LINE_LEN, stdin);

        // Parse the command
        command_t *command = parse_command(line);

        // Execute the command
        execute_command(command);

        // Wait for the command to finish
        int status = wait_for_command(command);

        // Print the exit status
        printf("Exit status: %d\n", status);

        // Free the command
        free(command);
    }
}

// Main function
int main() {
    // Initialize the shell
    shell_t *shell = init_shell();

    // Run the shell
    run_shell(shell);

    // Free the shell
    free_shell(shell);

    return 0;
}