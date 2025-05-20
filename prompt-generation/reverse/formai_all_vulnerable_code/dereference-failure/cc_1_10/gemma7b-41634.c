//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 255

typedef struct Command {
    char **cmd_args;
    char **cmd_history;
    int cmd_idx;
} Command;

Command commands[100];

void execute_command(Command *cmd) {
    int i = 0;
    char **args = cmd->cmd_args;

    for (; args[i] != NULL; i++) {
        printf("%s ", args[i]);
    }

    printf("\n");
}

int main() {

    char cmd_line[MAX_CMD_LEN];
    int cmd_idx = 0;

    commands[0].cmd_args = malloc(MAX_CMD_LEN);
    commands[0].cmd_history = malloc(MAX_CMD_LEN);

    while (1) {
        printf("$ ");
        fgets(cmd_line, MAX_CMD_LEN, stdin);

        // Parse the command line and create a new command object
        Command *new_cmd = &commands[cmd_idx];
        new_cmd->cmd_args = malloc(MAX_CMD_LEN);
        new_cmd->cmd_history = malloc(MAX_CMD_LEN);
        new_cmd->cmd_idx = cmd_idx++;

        // Split the command line into arguments and store them in the command object
        char *args = strtok(cmd_line, " ");
        int i = 0;
        new_cmd->cmd_args[i++] = args;

        while ((args = strtok(NULL, " ")) != NULL) {
            new_cmd->cmd_args[i++] = args;
        }

        // Execute the command
        execute_command(new_cmd);

        // Add the command to the command history
        new_cmd->cmd_history[0] = cmd_line;
        new_cmd->cmd_history[1] = NULL;
    }

    return 0;
}