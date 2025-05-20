//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_LEN 1024

char **parse_cmd(char **cmd) {
    char **args = NULL;
    int i = 0;

    *cmd = strdup(*cmd);
    args = malloc(MAX_CMD_LEN * sizeof(char *));

    // Tokenize the command
    char *token = strtok(*cmd, " ");

    // Allocate memory for each argument
    while (token) {
        args[i++] = strdup(token);
        token = strtok(NULL, " ");
    }

    args[i] = NULL;

    return args;
}

int main() {
    char cmd[MAX_CMD_LEN];

    // Loop until the user enters "exit"
    while (1) {
        // Print the prompt
        printf("$ ");

        // Get the command
        fgets(cmd, MAX_CMD_LEN, stdin);

        // Parse the command
        char **args = parse_cmd(&cmd);

        // Execute the command
        system(args[0]);

        // Free the memory allocated for the arguments
        free(args);
    }

    return 0;
}