//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 256

char **parse_cmd(char **cmd_line) {
    char **cmd_args = NULL;
    int num_args = 0;
    char *cmd_str = strdup(*cmd_line);
    char *token = strtok(cmd_str, " ");
    while (token) {
        cmd_args = realloc(cmd_args, (num_args + 1) * sizeof(char *));
        cmd_args[num_args++] = token;
        token = strtok(NULL, " ");
    }
    cmd_args[num_args] = NULL;
    return cmd_args;
}

int main() {
    char cmd_line[MAX_CMD_LEN];
    char **cmd_args = NULL;

    printf("Welcome to the Unix-like Shell!\n");

    while (1) {
        printf("$ ");
        fgets(cmd_line, MAX_CMD_LEN, stdin);

        cmd_args = parse_cmd(&cmd_line);

        // Here, you can implement your shell commands based on the parsed arguments
        // For example:
        if (strcmp(cmd_args[0], "exit") == 0) {
            exit(0);
        } else if (strcmp(cmd_args[0], "help") == 0) {
            printf("Available commands: exit, help, ls, cd\n");
        } else if (strcmp(cmd_args[0], "ls") == 0) {
            // Implement ls command logic
        } else if (strcmp(cmd_args[0], "cd") == 0) {
            // Implement cd command logic
        } else {
            printf("Unknown command: %s\n", cmd_args[0]);
        }

        free(cmd_args);
    }

    return 0;
}