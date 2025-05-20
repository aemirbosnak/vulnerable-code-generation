//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#define MAX_CMD_LEN 1024

char **parse_cmd(char *cmd) {
    char **argv = NULL;
    char *arg = NULL;
    int i = 0;

    // Allocate memory for argv
    argv = malloc(MAX_CMD_LEN * sizeof(char *));

    // Tokenize the command
    arg = strtok(cmd, " ");
    while (arg) {
        argv[i++] = strdup(arg);
        arg = strtok(NULL, " ");
    }

    // Null-terminate argv
    argv[i] = NULL;

    return argv;
}

int main() {
    char cmd[MAX_CMD_LEN];

    // Prompt for the command
    printf("$ ");

    // Get the command
    fgets(cmd, MAX_CMD_LEN, stdin);

    // Parse the command
    char **argv = parse_cmd(cmd);

    // Check if the command is valid
    if (argv[0] == NULL) {
        printf("Error: invalid command.\n");
    } else {
        // Execute the command
        system(argv[0]);
    }

    // Free memory
    free(argv);

    return 0;
}