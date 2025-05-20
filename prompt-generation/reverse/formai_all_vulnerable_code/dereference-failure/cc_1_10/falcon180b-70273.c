//Falcon-180B DATASET v1.0 Category: Error handling ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 64
#define MAX_ARGUMENTS 10

typedef struct {
    char *command;
    char **arguments;
    int num_arguments;
} command_t;

void print_command(command_t *cmd) {
    printf("command: %s\n", cmd->command);
    for (int i = 0; i < cmd->num_arguments; i++) {
        printf("argument %d: %s\n", i, cmd->arguments[i]);
    }
}

command_t *parse_command(char *input) {
    command_t *cmd = malloc(sizeof(command_t));
    cmd->command = strtok(input, " ");
    cmd->num_arguments = 0;
    cmd->arguments = malloc(MAX_ARGUMENTS * sizeof(char *));

    while (cmd->num_arguments < MAX_ARGUMENTS && (cmd->arguments[cmd->num_arguments] = strtok(NULL, " "))!= NULL) {
        cmd->num_arguments++;
    }

    return cmd;
}

int execute_command(command_t *cmd) {
    if (strcmp(cmd->command, "exit") == 0) {
        return 0;
    } else if (strcmp(cmd->command, "ls") == 0) {
        for (int i = 0; i < cmd->num_arguments; i++) {
            printf("argument %d: %s\n", i, cmd->arguments[i]);
        }
        return 0;
    } else {
        fprintf(stderr, "Unknown command: %s\n", cmd->command);
        return 1;
    }
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    command_t *cmd;

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        cmd = parse_command(input);
        if (cmd == NULL) {
            fprintf(stderr, "Error parsing command\n");
            continue;
        }

        print_command(cmd);
        execute_command(cmd);

        for (int i = 0; i < cmd->num_arguments; i++) {
            free(cmd->arguments[i]);
        }
        free(cmd->arguments);
        free(cmd);
    }

    return 0;
}