//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_LEN 256

char **parse_cmd(char **argv) {
    char **new_argv = NULL;
    int i = 0;

    // Allocate memory for new_argv
    new_argv = malloc(sizeof(char *) * (MAX_CMD_LEN + 1));

    // Iterate over the input command line arguments
    while (*argv) {
        new_argv[i++] = strdup(*argv);
        argv++;
    }

    new_argv[i] = NULL;

    return new_argv;
}

int main() {
    char cmd[MAX_CMD_LEN];
    char **argv = NULL;
    char **new_argv = NULL;

    // Get the user input
    printf("$ ");
    fgets(cmd, MAX_CMD_LEN, stdin);

    // Parse the command line arguments
    argv = parse_cmd(cmd);

    // Allocate memory for new_argv
    new_argv = malloc(sizeof(char *) * (MAX_CMD_LEN + 1));

    // Copy the parsed arguments into new_argv
    memcpy(new_argv, argv, sizeof(char *) * (MAX_CMD_LEN + 1));

    // Execute the command
    execvp(new_argv[0], new_argv);

    // Free the allocated memory
    free(new_argv);
    free(argv);

    return 0;
}