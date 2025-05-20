//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_LEN 1024

char **parse_cmd(char *cmd) {
    char **argv = NULL;
    char *arg = NULL;
    int i = 0;

    // Allocate memory for argv
    argv = malloc(MAX_CMD_LEN * sizeof(char *));

    // Split the command into arguments
    arg = strtok(cmd, " ");
    while (arg) {
        argv[i++] = strdup(arg);
        arg = strtok(NULL, " ");
    }

    // Null terminate the array
    argv[i] = NULL;

    return argv;
}

int main() {
    char cmd[MAX_CMD_LEN];

    // Loop until the user enters "exit"
    while (1) {
        // Print the shell prompt
        printf("$ ");

        // Get the user input
        fgets(cmd, MAX_CMD_LEN, stdin);

        // Parse the command
        char **argv = parse_cmd(cmd);

        // Execute the command
        if (argv[0] != NULL) {
            execvp(argv[0], argv);
        } else {
            printf("Error: command not found.\n");
        }

        // Free the memory allocated for argv
        free(argv);
    }

    return 0;
}