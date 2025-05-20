//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

#define MAX_LINE 1024
#define MAX_ARGS 32

typedef struct cmd {
    char *name;
    char **args;
    int argc;
    int in;
    int out;
} cmd;

cmd *parse_cmd(char *line) {
    cmd *cmd = malloc(sizeof(cmd));
    char *args[MAX_ARGS];
    char *token = strtok(line, " ");
    int argc = 0;

    while (token != NULL) {
        args[argc++] = token;
        token = strtok(NULL, " ");
    }

    cmd->name = args[0];
    cmd->args = args;
    cmd->argc = argc;
    cmd->in = 0;
    cmd->out = 1;

    return cmd;
}

int execute_cmd(cmd *cmd) {
    int pid = fork();

    if (pid == 0) {
        if (cmd->in != 0) {
            dup2(cmd->in, 0);
        }

        if (cmd->out != 1) {
            dup2(cmd->out, 1);
        }

        execvp(cmd->name, cmd->args);
        perror("execvp");
        exit(1);
    } else {
        int status;
        waitpid(pid, &status, 0);
        return status;
    }
}

int main() {
    char line[MAX_LINE];

    while (1) {
        printf("$ ");
        fgets(line, MAX_LINE, stdin);

        if (strcmp(line, "exit\n") == 0) {
            break;
        }

        cmd *cmd = parse_cmd(line);
        execute_cmd(cmd);
        free(cmd);
    }

    return 0;
}