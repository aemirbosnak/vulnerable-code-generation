//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 1024

char **parse_cmd(char **cmd) {
    char **args = NULL;
    int i = 0;
    char *arg = NULL;

    // Allocate memory for arguments
    args = malloc(MAX_CMD_LEN * sizeof(char *));

    // Split the command into arguments
    arg = strtok(cmd[0], " ");
    while (arg) {
        args[i++] = strdup(arg);
        arg = strtok(NULL, " ");
    }

    // Null terminate the arguments
    args[i] = NULL;

    return args;
}

int main() {
    char cmd[MAX_CMD_LEN];

    // Enter the shell prompt
    printf("$ ");

    // Get the user command
    scanf("%s", cmd);

    // Parse the command
    char **args = parse_cmd(cmd);

    // Execute the command
    if (args[0] != NULL) {
        execvp(args[0], args);
    } else {
        printf("Error: command not found.\n");
    }

    // Free the memory allocated for arguments
    free(args);

    return 0;
}