//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024

char **parse_cmd(char **argv, char *cmd) {
    int i = 0;
    char **new_argv = NULL;

    // Allocate memory for new argv
    new_argv = malloc((cmd[0] + 1) * sizeof(char *));

    // Tokenize the command
    char *token = strtok(cmd, " ");

    // Loop over the tokens
    while (token) {
        new_argv[i++] = strdup(token);
        token = strtok(NULL, " ");
    }

    new_argv[i] = NULL;

    return new_argv;
}

int main() {

    char cmd[MAX_CMD_LEN];

    // Loop until the user enters exit
    while (1) {
        // Print the shell prompt
        printf("$ ");

        // Get the user input
        fgets(cmd, MAX_CMD_LEN, stdin);

        // Remove the newline character
        cmd[strcspn(cmd, "\n")] = '\0';

        // Parse the command
        char **argv = parse_cmd(argv, cmd);

        // Execute the command
        pid_t pid = fork();
        if (pid == 0) {
            execvp(argv[0], argv);
            exit(1);
        } else {
            wait(NULL);
        }

        // Free the memory allocated for argv
        free(argv);
    }

    return 0;
}