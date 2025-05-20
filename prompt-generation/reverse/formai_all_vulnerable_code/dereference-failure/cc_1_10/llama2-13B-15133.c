//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

#define MAX_CMD_LEN 1024
#define MAX_ARGS 64

struct command {
    char *name;
    char *args[MAX_ARGS];
};

int main(void) {
    char *cmd_name;
    char *cmd_args[MAX_ARGS];
    int i;

    // Initialize command and argument arrays
    cmd_name = malloc(MAX_CMD_LEN);
    cmd_args[0] = malloc(MAX_CMD_LEN);

    // Get command from user
    printf("Enter a command: ");
    fgets(cmd_name, MAX_CMD_LEN, stdin);

    // Tokenize command
    i = 0;
    char *token = strtok(cmd_name, " ");
    while (token != NULL && i < MAX_ARGS) {
        cmd_args[i++] = token;
        token = strtok(NULL, " ");
    }

    // Execute command
    if (cmd_name[0] == '.' && cmd_name[1] == 'x') {
        // Execute external command
        char *exec_cmd[MAX_ARGS];
        for (i = 0; i < MAX_ARGS; i++) {
            exec_cmd[i] = cmd_args[i];
        }
        execvp(cmd_name, exec_cmd);
    } else {
        // Execute internal command
        char *internal_cmd[MAX_ARGS];
        for (i = 0; i < MAX_ARGS; i++) {
            internal_cmd[i] = cmd_args[i];
        }
        system(internal_cmd[0]);
    }

    // Clean up
    free(cmd_name);
    for (i = 0; i < MAX_ARGS; i++) {
        free(cmd_args[i]);
    }

    return 0;
}