//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 512
#define MAX_ARGUMENTS 256
#define DELIM " "

char **split_string(char *str) {
    int count = 0;
    char **tokens = malloc(MAX_ARGUMENTS * sizeof(char*));
    char *token = strtok(str, DELIM);
    while (token!= NULL) {
        tokens[count] = token;
        count++;
        token = strtok(NULL, DELIM);
        if (count >= MAX_ARGUMENTS) {
            break;
        }
    }
    tokens[count] = NULL;
    return tokens;
}

pid_t fork() {
    pid_t pid;
    if ((pid = fork()) == 0) {
        return pid;
    } else if (pid < 0) {
        fprintf(stderr, "Error: fork failed\n");
        exit(1);
    } else {
        return pid;
    }
}

int execute_command(char **args) {
    pid_t pid;
    int status;
    if (args[0] == NULL) {
        fprintf(stderr, "Error: command not found\n");
        return 1;
    }
    if (strcmp(args[0], "exit") == 0) {
        return 0;
    }
    pid = fork();
    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            fprintf(stderr, "Error: %s not found\n", args[0]);
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
    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        args = split_string(input);
        if (args[0] == NULL) {
            continue;
        }
        execute_command(args);
        free(args);
    }
    return 0;
}