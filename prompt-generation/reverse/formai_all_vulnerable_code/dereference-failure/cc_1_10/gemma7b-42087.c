//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_LEN 256

typedef struct ShellState {
    char **commands;
    int command_size;
    int current_command_index;
} ShellState;

ShellState shell_state;

void shell_init() {
    shell_state.commands = NULL;
    shell_state.command_size = 0;
    shell_state.current_command_index = 0;
}

void shell_add_command(char *command) {
    shell_state.commands = realloc(shell_state.commands, (shell_state.command_size + 1) * sizeof(char *));
    shell_state.commands[shell_state.command_size++] = command;
}

void shell_execute_command(char *command) {
    char **args = NULL;
    char *arg = NULL;
    int i = 0;

    // Parse the command into arguments
    arg = strtok(command, " ");
    while (arg) {
        args = realloc(args, (i + 1) * sizeof(char *));
        args[i++] = arg;
        arg = strtok(NULL, " ");
    }

    // Execute the command
    execvp(args[0], args);

    // Free the allocated memory
    free(args);
}

int main() {
    char cmd[MAX_CMD_LEN];

    shell_init();

    // Loop until the user enters "exit"
    while (strcmp(cmd, "exit") != 0) {
        printf("$ ");
        fgets(cmd, MAX_CMD_LEN, stdin);

        // Add the command to the shell state
        shell_add_command(cmd);

        // Execute the command
        shell_execute_command(cmd);
    }

    // Free the allocated memory
    free(shell_state.commands);

    return 0;
}