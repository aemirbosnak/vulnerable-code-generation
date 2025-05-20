//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 256

char **parse_command(char **cmd) {
    char **args = NULL;
    int i = 0;
    *cmd = strdup(*cmd);
    cmd = strchr(*cmd, ' ');
    if (cmd) {
        *cmd = NULL;
        args = malloc(sizeof(char *) * MAX_CMD_LEN);
        args[i++] = strdup(*cmd);
        while ((cmd = strchr(cmd + 1, ' ')) != NULL) {
            *cmd = NULL;
            args[i++] = strdup(cmd + 1);
        }
        args[i] = NULL;
    }
    return args;
}

int main() {
    char cmd[MAX_CMD_LEN];

    while (1) {
        printf("$ ");
        fgets(cmd, MAX_CMD_LEN, stdin);

        char **args = parse_command(&cmd);

        if (args) {
            pid_t pid = fork();
            if (pid == 0) {
                execvp(args[0], args);
            } else if (pid > 0) {
                wait(NULL);
            } else {
                perror("fork");
            }
            free(args);
        } else {
            printf("Error: Invalid command.\n");
        }
    }

    return 0;
}