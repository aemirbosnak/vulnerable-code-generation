//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>

#define MAX_LINE 1024
#define MAX_ARGS 1024

char **split_line(char *line);
void execute_command(char **args);
int is_builtin(char **args);

int main() {
    char input[MAX_LINE];
    char **args;
    pid_t pid;
    int status;

    while (1) {
        printf("> ");
        fgets(input, MAX_LINE, stdin);

        args = split_line(input);

        if (args[0] == NULL) {
            continue;
        }

        if (is_builtin(args)) {
            execute_command(args);
        } else {
            pid = fork();

            if (pid == -1) {
                perror("fork");
            } else if (pid == 0) {
                execute_command(args);
                exit(0);
            } else {
                waitpid(pid, &status, 0);
            }
        }
    }

    return 0;
}

char **split_line(char *line) {
    int argc = 0;
    char **args = malloc(MAX_ARGS * sizeof(char*));
    char *token;

    token = strtok(line, " ");

    while (token!= NULL) {
        args[argc] = malloc(strlen(token) + 1);
        strcpy(args[argc], token);
        argc++;

        token = strtok(NULL, " ");
    }

    args[argc] = NULL;

    return args;
}

void execute_command(char **args) {
    int i;

    for (i = 0; args[i]!= NULL; i++) {
        printf("%s ", args[i]);
    }

    printf("\n");
}

int is_builtin(char **args) {
    if (strcmp(args[0], "exit") == 0) {
        exit(0);
    } else {
        return 0;
    }
}