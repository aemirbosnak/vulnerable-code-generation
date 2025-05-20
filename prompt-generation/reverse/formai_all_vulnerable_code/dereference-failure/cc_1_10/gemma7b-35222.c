//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 1024

char **parse_command(char **cmd) {
    char **args = NULL;
    int i = 0;

    // Allocate memory for arguments
    args = malloc(MAX_CMD_LEN * sizeof(char *));

    // Tokenize the command
    char *token = strtok(*cmd, " ");
    while (token) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }

    // Null-terminate the arguments
    args[i] = NULL;

    return args;
}

int main() {
    char cmd[MAX_CMD_LEN];

    // Loop until the user enters a quit command
    while (1) {
        // Print the shell prompt
        printf("$ ");

        // Get the user input
        fgets(cmd, MAX_CMD_LEN, stdin);

        // Parse the command
        char **args = parse_command(&cmd);

        // Execute the command
        if (args[0] != NULL) {
            execvp(args[0], args);
        } else {
            printf("Error: invalid command.\n");
        }

        // Free the memory allocated for arguments
        free(args);
    }

    return 0;
}