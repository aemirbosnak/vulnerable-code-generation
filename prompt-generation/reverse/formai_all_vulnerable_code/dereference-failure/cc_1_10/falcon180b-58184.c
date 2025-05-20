//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 1024
#define DELIM " \t\r\n\a"

char **split_string(char *str) {
    char **tokens = malloc(sizeof(char *) * (MAX_ARGUMENTS + 1));
    int argc = 0;
    char *token = strtok(str, DELIM);
    while (token!= NULL) {
        tokens[argc++] = token;
        token = strtok(NULL, DELIM);
    }
    tokens[argc] = NULL;
    return tokens;
}

pid_t fork() {
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    }
    return pid;
}

int execute_command(char **args) {
    pid_t pid = fork();
    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        int status;
        waitpid(pid, &status, 0);
    }
    return 0;
}

void handle_sigint(int signum) {
    fprintf(stderr, "Interrupted\n");
    exit(1);
}

int main() {
    signal(SIGINT, handle_sigint);
    char input[MAX_COMMAND_LENGTH];
    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        char **args = split_string(input);
        execute_command(args);
    }
    return 0;
}