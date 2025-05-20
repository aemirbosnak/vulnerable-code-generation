//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_LEN 1024

int main() {

    char cmd[MAX_CMD_LEN];
    char **argv;
    int argc;
    int i;

    while (1) {
        printf("$ ");
        fgets(cmd, MAX_CMD_LEN, stdin);

        // Parse the command line
        argv = NULL;
        argc = 0;
        if (*cmd) {
            argv = malloc((MAX_CMD_LEN - 1) / sizeof(char *));
            argc = parse_cmd(cmd, argv);
        }

        // Execute the command
        if (argc) {
            execvp(argv[0], argv);
        }

        // Free resources
        free(argv);
    }

    return 0;
}

int parse_cmd(char *cmd, char **argv) {
    char *ptr;
    int i = 0;

    // Remove the newline character from the end of the command
    ptr = strchr(cmd, '\n');
    if (ptr) {
        *ptr = '\0';
    }

    // Split the command into arguments
    argv[0] = strdup(cmd);
    for (i = 1; ptr && (ptr = strchr(cmd, ' ')) != NULL; i++) {
        argv[i] = strdup(ptr + 1);
        cmd = ptr + 1;
    }

    // Null-terminate the argument list
    argv[i] = NULL;

    return i;
}