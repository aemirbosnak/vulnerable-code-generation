//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024

char **parse_cmd(char *cmd) {
    char **argv = NULL;
    int i = 0;

    // Allocate memory for argv
    argv = malloc(MAX_CMD_LEN * sizeof(char *));

    // Split the command into arguments
    char *arg = strtok(cmd, " ");
    while (arg) {
        argv[i++] = strdup(arg);
        arg = strtok(NULL, " ");
    }

    // Null terminate argv
    argv[i] = NULL;

    return argv;
}

int main() {
    char cmd[MAX_CMD_LEN];

    // Prompt for a command
    printf("$ ");

    // Get the command
    fgets(cmd, MAX_CMD_LEN, stdin);

    // Parse the command
    char **argv = parse_cmd(cmd);

    // Execute the command
    pid_t pid = fork();
    if (pid == 0) {
        execvp(argv[0], argv);
    } else {
        wait(NULL);
    }

    // Free the memory allocated for argv
    free(argv);

    return 0;
}