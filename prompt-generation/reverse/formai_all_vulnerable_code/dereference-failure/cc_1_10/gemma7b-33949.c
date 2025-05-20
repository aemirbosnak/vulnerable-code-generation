//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CMD_LEN 256

char **parse_command(char *command) {
    char **argv = NULL;
    int i = 0;

    // Allocate memory for argv
    argv = malloc(MAX_CMD_LEN * sizeof(char *));

    // Split the command into arguments
    char *tokens = strtok(command, " ");
    while (tokens) {
        argv[i++] = strdup(tokens);
        tokens = strtok(NULL, " ");
    }

    // Null terminate argv
    argv[i] = NULL;

    return argv;
}

int main() {
    char command[MAX_CMD_LEN];

    // Prompt for a command
    printf("$ ");

    // Get the command
    fgets(command, MAX_CMD_LEN, stdin);

    // Parse the command
    char **argv = parse_command(command);

    // Execute the command
    if (argv[0] != NULL) {
        execvp(argv[0], argv);
    } else {
        printf("Error: command not found.\n");
    }

    // Free memory
    free(argv);

    return 0;
}