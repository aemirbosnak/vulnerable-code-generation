//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_LENGTH 1024
#define MAX_ARGS 64

void execute_command(char **cmd, int argc) {
    char *cmd_str = NULL;
    char *args[MAX_ARGS];
    int status;

    // Build the command string
    cmd_str = malloc(sizeof(char) * (strlen(cmd[0]) + 1));
    strcpy(cmd_str, cmd[0]);
    for (int i = 1; i < argc; i++) {
        strcat(cmd_str, " ");
        strcat(cmd_str, cmd[i]);
    }

    // Execute the command
    if (execv(cmd[0], args) == -1) {
        perror("execv");
        exit(EXIT_FAILURE);
    }

    // Wait for the command to complete
    wait(&status);

    // Print the command output
    if (WIFEXITED(status)) {
        printf("Command output: %s\n", cmd_str);
    } else {
        printf("Command failed with status %d\n", status);
    }
}

int main() {
    char *cmd[3];
    int argc;

    // Example 1: Run a command and capture its output
    cmd[0] = "/bin/ls";
    argc = 1;
    execute_command(cmd, argc);

    // Example 2: Run a command with arguments
    cmd[0] = "/bin/grep";
    argc = 2;
    cmd[1] = "-i";
    cmd[2] = "example";
    execute_command(cmd, argc);

    // Example 3: Run a command with input
    cmd[0] = "/bin/cat";
    argc = 1;
    cmd[1] = "-";
    execute_command(cmd, argc);

    return 0;
}