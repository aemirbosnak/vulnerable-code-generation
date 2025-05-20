//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 1024

char **parse_cmd(char **cmd_line) {
    char **cmd_args = NULL;
    int num_args = 0;
    char *cmd_str = strdup(*cmd_line);

    // Remove trailing newline character
    if (cmd_str[strlen(cmd_str) - 1] == '\n') {
        cmd_str[strlen(cmd_str) - 1] = '\0';
    }

    // Tokenize the command line
    char *token = strtok(cmd_str, " ");
    while (token) {
        cmd_args = realloc(cmd_args, (num_args + 1) * sizeof(char *));
        cmd_args[num_args++] = token;
        token = strtok(NULL, " ");
    }

    // Return the command arguments
    return cmd_args;
}

int main() {
    char cmd_line[MAX_CMD_LEN];

    // Prompt the user for a command line
    printf("$ ");
    fgets(cmd_line, MAX_CMD_LEN, stdin);

    // Parse the command line
    char **cmd_args = parse_cmd(&cmd_line);

    // Print the command arguments
    for (int i = 0; cmd_args[i] != NULL; i++) {
        printf("%s ", cmd_args[i]);
    }

    printf("\n");

    // Free the command arguments
    free(cmd_args);

    return 0;
}