//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024

char **parse_cmd(char **cmd) {
    char **args = NULL;
    int i = 0;
    char *arg = NULL;

    while (*cmd) {
        arg = strchr(*cmd, ' ');
        if (arg) {
            args = realloc(args, (i + 1) * sizeof(char *));
            args[i++] = strdup(*cmd);
            *cmd = arg + 1;
        } else {
            args = realloc(args, (i + 1) * sizeof(char *));
            args[i++] = strdup(*cmd);
            *cmd = NULL;
        }
    }

    return args;
}

int main() {
    char cmd[MAX_CMD_LEN];

    printf("$ ");
    fgets(cmd, MAX_CMD_LEN, stdin);

    char **cmd_args = parse_cmd(&cmd);

    if (cmd_args) {
        pid_t pid = fork();

        if (pid == 0) {
            execvp(cmd_args[0], cmd_args);
            exit(1);
        } else if (pid > 0) {
            wait(NULL);
        } else {
            perror("Error");
        }
    }

    return 0;
}