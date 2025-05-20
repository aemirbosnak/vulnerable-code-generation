//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE_LENGTH 1024
#define MAX_ARGS 64

typedef struct {
    char *name;
    char **args;
    int num_args;
} Command;

Command *parse_command(char *line) {
    Command *cmd = malloc(sizeof(Command));
    cmd->name = strtok(line, " ");
    cmd->args = malloc(sizeof(char *) * MAX_ARGS);
    cmd->num_args = 0;
    while ((cmd->args[cmd->num_args] = strtok(NULL, " ")) != NULL) {
        cmd->num_args++;
    }
    return cmd;
}

void free_command(Command *cmd) {
    free(cmd->name);
    free(cmd->args);
    free(cmd);
}

int main() {
    char line[MAX_LINE_LENGTH];
    while (1) {
        printf("shape> ");
        if (fgets(line, MAX_LINE_LENGTH, stdin) == NULL) {
            printf("\n");
            break;
        }
        Command *cmd = parse_command(line);
        if (strcmp(cmd->name, "exit") == 0) {
            break;
        }
        pid_t pid = fork();
        if (pid == 0) {
            execvp(cmd->name, cmd->args);
            perror("execvp");
            exit(1);
        } else {
            int status;
            waitpid(pid, &status, 0);
        }
        free_command(cmd);
    }
    return 0;
}