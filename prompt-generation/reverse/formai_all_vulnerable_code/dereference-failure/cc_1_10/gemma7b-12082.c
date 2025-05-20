//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024

char **parse_cmd(char **argv, char **cmd) {
    int i = 0;
    char **new_argv = NULL;

    *cmd = malloc(MAX_CMD_LEN);
    scanf("%[^\n]%*c", cmd);

    // Split the command into arguments
    char *token = strtok(*cmd, " ");
    while (token) {
        argv[i++] = token;
        token = strtok(NULL, " ");
    }

    argv[i] = NULL;

    return new_argv;
}

int main() {
    char **cmd_line = NULL;
    char **argv = NULL;
    char **new_argv = NULL;

    // Allocate memory for the command line
    cmd_line = malloc(MAX_CMD_LEN);

    // Loop until the user enters "exit"
    while (strcmp(cmd_line, "exit") != 0) {
        // Parse the command line
        new_argv = parse_cmd(argv, cmd_line);

        // Execute the command
        execvp(new_argv[0], new_argv);

        // Free the memory allocated for the command line and arguments
        free(cmd_line);
        free(argv);
        free(new_argv);

        // Get the next command from the user
        cmd_line = malloc(MAX_CMD_LEN);
        scanf("%[^\n]%*c", cmd_line);
    }

    // Free the memory allocated for the command line and arguments
    free(cmd_line);
    free(argv);
    free(new_argv);

    return 0;
}