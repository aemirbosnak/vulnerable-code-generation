//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    shell_state.current_command_index = -1;
}

void shell_add_command(char *command) {
    shell_state.commands = realloc(shell_state.commands, (shell_state.command_size + 1) * sizeof(char *));
    shell_state.commands[shell_state.command_size++] = command;
}

void shell_execute_command(char *command) {
    system(command);
}

int shell_prompt() {
    printf("$ ");
    char command[MAX_CMD_LEN];
    fgets(command, MAX_CMD_LEN, stdin);
    return strlen(command);
}

int main() {
    shell_init();

    while (1) {
        int cmd_len = shell_prompt();
        char *command = malloc(cmd_len + 1);
        fgets(command, cmd_len + 1, stdin);
        shell_add_command(command);
        shell_execute_command(command);
        free(command);
    }

    return 0;
}