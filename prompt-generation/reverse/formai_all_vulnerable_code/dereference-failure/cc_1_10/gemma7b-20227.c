//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 256

char **parse_command(char *command) {
    char **args = NULL;
    int i = 0;
    char *arg = NULL;

    // Allocate memory for arguments
    args = malloc(MAX_CMD_LEN * sizeof(char *));

    // Split the command into arguments
    arg = strtok(command, " ");
    while (arg) {
        args[i++] = strdup(arg);
        arg = strtok(NULL, " ");
    }

    // Null-terminate the arguments
    args[i] = NULL;

    return args;
}

int main() {
    char command[MAX_CMD_LEN];

    // Enter the shell prompt
    printf("$ ");

    // Get the command from the user
    fgets(command, MAX_CMD_LEN, stdin);

    // Parse the command and get the arguments
    char **args = parse_command(command);

    // Print the arguments
    printf("Arguments:");
    for (int i = 0; args[i] != NULL; i++) {
        printf(" %s", args[i]);
    }

    // Free the memory allocated for arguments
    free(args);

    return 0;
}