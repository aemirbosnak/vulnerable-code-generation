//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_CMD_LEN 256

char **parse_cmd(char *cmd) {
    char **argv = NULL;
    char *arg = NULL;
    int i = 0;

    // Allocate memory for argv
    argv = malloc(MAX_CMD_LEN * sizeof(char *));
    if (argv == NULL) {
        perror("malloc");
        exit(1);
    }

    // Split the command into arguments
    arg = strtok(cmd, " ");
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

    // Prompt the user for a command
    printf("$ ");
    fgets(cmd, MAX_CMD_LEN, stdin);

    // Parse the command
    char **argv = parse_cmd(cmd);

    // Execute the command
    if (argv[0] == NULL) {
        printf("Error: command not found.\n");
    } else if (fork() == 0) {
        execvp(argv[0], argv);
    } else {
        wait(NULL);
    }

    // Free memory
    free(argv);

    return 0;
}