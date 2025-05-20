//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 1024

char **parse_cmd(char **cmd) {
    char **argv = NULL;
    int i = 0;
    char *cmd_ptr = *cmd;
    char delims[] = " \t\n";

    // Allocate memory for argv
    argv = malloc(sizeof(char *) * MAX_CMD_LEN);

    // Split the command into arguments
    while (cmd_ptr && *cmd_ptr) {
        char *arg = strchr(cmd_ptr, delims);
        argv[i++] = arg ? strndup(cmd_ptr, arg - cmd_ptr) : strndup(cmd_ptr, "");
        cmd_ptr = arg ? arg + 1 : NULL;
    }

    // Null terminate the argv array
    argv[i] = NULL;

    return argv;
}

int main() {
    char cmd[MAX_CMD_LEN];

    // Prompt the user for a command
    printf("$ ");
    fgets(cmd, MAX_CMD_LEN, stdin);

    // Parse the command
    char **argv = parse_cmd(&cmd);

    // Print the parsed arguments
    for (int i = 0; argv[i] != NULL; i++) {
        printf("%s ", argv[i]);
    }

    printf("\n");

    // Free the allocated memory
    for (int i = 0; argv[i] != NULL; i++) {
        free(argv[i]);
    }

    free(argv);

    return 0;
}