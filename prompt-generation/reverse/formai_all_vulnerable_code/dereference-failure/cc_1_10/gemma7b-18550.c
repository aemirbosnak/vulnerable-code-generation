//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 1024

typedef struct Command {
    char *name;
    char **args;
    struct Command *next;
} Command;

Command *parse_command(char *cmd) {
    Command *head = NULL;
    char *token, *cmd_copy;

    cmd_copy = strdup(cmd);

    token = strtok(cmd_copy, " ");

    while (token) {
        Command *new_cmd = malloc(sizeof(Command));
        new_cmd->name = strdup(token);

        new_cmd->args = NULL;

        if (head) {
            new_cmd->next = head;
        }

        head = new_cmd;

        token = strtok(NULL, " ");
    }

    free(cmd_copy);

    return head;
}

int main() {
    char cmd[MAX_CMD_LEN];

    printf("Enter a command: ");
    fgets(cmd, MAX_CMD_LEN, stdin);

    Command *commands = parse_command(cmd);

    for (Command *command = commands; command; command = command->next) {
        printf("Command: %s\n", command->name);

        for (int i = 0; command->args[i] != NULL; i++) {
            printf("Argument: %s\n", command->args[i]);
        }
    }

    return 0;
}