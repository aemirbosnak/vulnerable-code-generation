//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 1024

char **parse_cmd(char **cmd) {
    char **argv = malloc(sizeof(char *) * MAX_CMD_LEN);
    int i = 0;

    // Remove trailing newline character
    cmd[strlen(cmd) - 1] = '\0';

    // Split the command line into arguments
    char *token = strtok(cmd, " ");
    while (token) {
        argv[i++] = strdup(token);
        token = strtok(NULL, " ");
    }

    return argv;
}

int main() {
    char cmd[MAX_CMD_LEN];

    // Loop until the user enters an exit command
    while (1) {
        // Print prompt
        printf("$ ");

        // Get the user input
        fgets(cmd, MAX_CMD_LEN, stdin);

        // Parse the command line
        char **argv = parse_cmd(cmd);

        // Execute the command
        if (argv[0] == NULL) {
            printf("Error: Invalid command.\n");
        } else if (strcmp(argv[0], "exit") == 0) {
            exit(0);
        } else {
            // Implement your own commands here
            printf("Command: %s\n", argv[0]);
            printf("Arguments: ");
            for (int i = 1; argv[i] != NULL; i++) {
                printf("%s ", argv[i]);
            }
            printf("\n");
        }

        // Free the memory allocated for argv
        free(argv);
    }

    return 0;
}