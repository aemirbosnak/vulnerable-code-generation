//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMANDS 1000
#define DELIM " \t\r\n\a"

char **split(char *line, int *n) {
    char **tokens = malloc(sizeof(char *) * MAX_COMMANDS);
    int count = 0;
    char *token = strtok(line, DELIM);
    while (token!= NULL) {
        tokens[count++] = token;
        if (count >= MAX_COMMANDS) {
            fprintf(stderr, "Too many arguments.\n");
            exit(1);
        }
        token = strtok(NULL, DELIM);
    }
    tokens[count] = NULL;
    *n = count;
    return tokens;
}

pid_t fork() {
    pid_t pid;
    if ((pid = fork()) == -1) {
        perror("fork");
        exit(1);
    }
    return pid;
}

int main() {
    char input[1024];
    char **args;
    pid_t pid;
    int status;

    printf("Welcome to the Basic Unix-like Shell!\n");
    while (1) {
        printf("> ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            fprintf(stderr, "Error reading input.\n");
            exit(1);
        }
        args = split(input, &status);
        if (status == 0) {
            continue;
        }
        if (strcmp(args[0], "exit") == 0) {
            break;
        } else if (strcmp(args[0], "cd") == 0) {
            if (args[1] == NULL) {
                fprintf(stderr, "Missing argument for cd.\n");
            } else {
                if (chdir(args[1]) == -1) {
                    perror("chdir");
                }
            }
        } else if (strcmp(args[0], "pwd") == 0) {
            char cwd[1024];
            if (getcwd(cwd, sizeof(cwd))!= NULL) {
                printf("%s\n", cwd);
            } else {
                perror("getcwd");
            }
        } else {
            pid = fork();
            if (pid == 0) {
                execvp(args[0], args);
                perror("execvp");
                exit(1);
            } else if (pid == -1) {
                perror("fork");
            }
            waitpid(pid, &status, 0);
        }
    }
    return 0;
}