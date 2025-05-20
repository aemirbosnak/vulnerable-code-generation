//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_LEN 256

char **parse_cmd(char *cmd) {
    char **argv = NULL;
    int i = 0;
    char *delim = "";

    // Allocate memory for argv
    argv = malloc(MAX_CMD_LEN * sizeof(char *));

    // Tokenize the command
    delim = strchr(cmd, ' ');
    while (delim) {
        argv[i++] = strdup(delim + 1);
        cmd = delim + 1;
        delim = strchr(cmd, ' ');
    }

    // Add the last token to argv
    argv[i] = strdup(cmd);

    // Return the argv array
    return argv;
}

int main() {

    char cmd[MAX_CMD_LEN];

    // Prompt the user for a command
    printf("$ ");

    // Get the user's command
    fgets(cmd, MAX_CMD_LEN, stdin);

    // Parse the command
    char **argv = parse_cmd(cmd);

    // Execute the command
    execvp(argv[0], argv);

    // Free the memory allocated for argv
    free(argv);

    return 0;
}