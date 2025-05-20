//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *str) {
    int bufsize = 0, i = 0;
    char **tokens = NULL;
    char *token;

    token = strtok(str, DELIM);
    while (token!= NULL) {
        bufsize++;
        tokens = realloc(tokens, bufsize * sizeof(char*));
        tokens[i] = strdup(token);
        token = strtok(NULL, DELIM);
        i++;
    }
    tokens[i] = NULL;

    return tokens;
}

pid_t fork() {
    pid_t pid;

    pid = vfork();
    if (pid == -1) {
        perror("vfork");
        exit(1);
    }

    if (pid == 0) {
        setsid();
    }

    return pid;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    int bg = 0;

    printf("Unix-like Shell\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        args = split_string(input);

        if (args[0] == NULL)
            continue;

        if (strcmp(args[0], "exit") == 0) {
            break;
        } else if (strcmp(args[0], "bg") == 0) {
            bg = 1;
        } else {
            execute_command(args);
        }

        if (bg == 0) {
            bg = 0;
        }
    }

    return 0;
}