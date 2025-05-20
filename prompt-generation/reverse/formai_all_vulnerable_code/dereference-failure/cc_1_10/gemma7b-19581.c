//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_LEN 256

typedef struct Command {
    char *cmd;
    char **args;
    struct Command *next;
} Command;

Command *parse_command(char *line) {
    Command *cmd = malloc(sizeof(Command));
    cmd->cmd = malloc(MAX_CMD_LEN);
    cmd->args = malloc(MAX_CMD_LEN * sizeof(char *));

    char *cmd_start = strchr(line, ' ');
    if (cmd_start) {
        strncpy(cmd->cmd, line, cmd_start - line);
    } else {
        strncpy(cmd->cmd, line, MAX_CMD_LEN - 1);
    }

    char **arg_start = strchr(cmd_start, ' ');
    int arg_index = 0;
    if (arg_start) {
        cmd->args[arg_index++] = strdup(arg_start + 1);
    }

    while (arg_start && (arg_start = strchr(arg_start, ' '))) {
        cmd->args[arg_index++] = strdup(arg_start + 1);
    }

    cmd->args[arg_index] = NULL;
    cmd->next = NULL;

    return cmd;
}

void execute_command(Command *cmd) {
    if (!cmd) {
        return;
    }

    if (fork() == 0) {
        execvp(cmd->cmd, cmd->args);
        exit(1);
    } else {
        wait(NULL);
    }
}

int main() {
    char line[MAX_CMD_LEN];

    // Prompt for a command
    printf("$ ");

    // Get the command line
    fgets(line, MAX_CMD_LEN, stdin);

    // Parse the command
    Command *cmd = parse_command(line);

    // Execute the command
    execute_command(cmd);

    return 0;
}