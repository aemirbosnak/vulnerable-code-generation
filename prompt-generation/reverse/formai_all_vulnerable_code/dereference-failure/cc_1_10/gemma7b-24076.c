//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 1024

char shell_prompt[] = "$ ";

void execute_command(char *command) {
    char **args = NULL;
    int num_args = 0;
    char *arg = NULL;

    // Tokenize the command
    args = malloc(MAX_CMD_LEN * sizeof(char *));
    arg = strtok(command, " ");
    while (arg) {
        args[num_args++] = arg;
        arg = strtok(NULL, " ");
    }

    // Check if the command is valid
    if (strcmp(args[0], "exit") == 0) {
        exit(0);
    } else if (strcmp(args[0], "help") == 0) {
        // Print help information
    } else if (strcmp(args[0], "dir") == 0) {
        // Print directory listing
    } else {
        // Execute the command
    }

    // Free memory
    free(args);
}

int main() {
    char command[MAX_CMD_LEN];

    // Loop until the user enters "exit"
    while (1) {
        // Print the shell prompt
        printf("%s", shell_prompt);

        // Get the user's command
        fgets(command, MAX_CMD_LEN, stdin);

        // Execute the command
        execute_command(command);
    }

    return 0;
}