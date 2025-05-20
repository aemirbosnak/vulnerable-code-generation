//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 256

char **parse_cmd(char **cmd) {
    char **args = NULL;
    int i = 0;

    *cmd = strdup(*cmd);
    cmd = strchr(*cmd, ' ');

    if (cmd) {
        *cmd++ = NULL;
        args = malloc(sizeof(char *) * MAX_CMD_LEN);

        while (*cmd) {
            args[i++] = strdup(*cmd);
            cmd = strchr(*cmd, ' ');
            if (cmd) {
                *cmd++ = NULL;
            }
        }
    }

    return args;
}

int main() {
    char cmd[MAX_CMD_LEN];
    char **args = NULL;
    int status;

    printf("$ ");
    scanf("%s", cmd);

    args = parse_cmd(&cmd);

    if (args) {
        pid_t pid = fork();

        if (pid == 0) {
            execvp(args[0], args);
            exit(1);
        } else {
            wait(&status);
            free(args);
        }
    }

    return 0;
}