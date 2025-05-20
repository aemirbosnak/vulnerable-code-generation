//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define MAX_LINE_LENGTH 1024

typedef struct cmd_t {
    char *args[MAX_ARGS];
    int num_args;
} cmd_t;

void print_prompt() {
    printf("> ");
}

cmd_t *parse_line(char *line) {
    cmd_t *cmd = malloc(sizeof(cmd_t));
    memset(cmd, 0, sizeof(cmd_t));

    char *token = strtok(line, " ");
    while (token != NULL) {
        cmd->args[cmd->num_args] = token;
        cmd->num_args++;
        token = strtok(NULL, " ");
    }

    return cmd;
}

void execute_cmd(cmd_t *cmd) {
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        if (execvp(cmd->args[0], cmd->args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else if (pid > 0) {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
    } else {
        // Error
        perror("fork");
    }
}

int main() {
    char line[MAX_LINE_LENGTH];

    while (1) {
        print_prompt();
        fgets(line, MAX_LINE_LENGTH, stdin);

        if (strcmp(line, "exit\n") == 0) {
            break;
        }

        cmd_t *cmd = parse_line(line);
        execute_cmd(cmd);
        free(cmd);
    }

    return 0;
}