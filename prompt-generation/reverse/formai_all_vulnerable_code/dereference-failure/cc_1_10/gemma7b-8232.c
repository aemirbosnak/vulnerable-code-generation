//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_CMD_LEN 256

char **parse_cmd(char **cmd) {
    char **argv = NULL;
    int i = 0;
    char *cmd_cpy = strdup(*cmd);

    // Tokenize the command
    char *token = strtok(cmd_cpy, " ");
    while (token) {
        argv = realloc(argv, (i + 1) * sizeof(char *));
        argv[i++] = token;
        token = strtok(NULL, " ");
    }

    // Free the command copy
    free(cmd_cpy);

    return argv;
}

int main() {
    char cmd[MAX_CMD_LEN];

    // Enter the shell prompt
    printf("$ ");

    // Get the user input
    fgets(cmd, MAX_CMD_LEN, stdin);

    // Parse the command
    char **argv = parse_cmd(&cmd);

    // Execute the command
    if (argv[0] != NULL) {
        execvp(argv[0], argv);
    } else {
        printf("Error: command not found.\n");
    }

    // Free the memory
    free(argv);

    return 0;
}