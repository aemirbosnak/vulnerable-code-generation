//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_line(char *line);
int execute_command(char **args);

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    pid_t pid;
    int status;

    printf("Welcome to the Basic Unix-like Shell!\n");
    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        args = split_line(input);
        if (args[0] == NULL)
            continue;
        pid = fork();
        if (pid == -1) {
            printf("Error forking process.\n");
            exit(1);
        } else if (pid == 0) {
            execute_command(args);
            exit(0);
        } else {
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}

char **split_line(char *line) {
    int argc = 0;
    char **args = malloc(MAX_ARGUMENTS * sizeof(char*));
    char *token;

    token = strtok(line, DELIM);
    while (token!= NULL) {
        args[argc++] = token;
        if (argc >= MAX_ARGUMENTS) {
            printf("Too many arguments.\n");
            exit(1);
        }
        token = strtok(NULL, DELIM);
    }
    args[argc] = NULL;

    return args;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL)
        return 1;

    if (strcmp(args[0], "exit") == 0) {
        return 0;
    } else if (strcmp(args[0], "cd") == 0) {
        if (args[1] == NULL) {
            printf("Usage: cd [directory]\n");
        } else {
            if (chdir(args[1])!= 0) {
                printf("Error changing directory.\n");
            }
        }
        return 1;
    } else {
        pid = fork();
        if (pid == -1) {
            printf("Error forking process.\n");
            exit(1);
        } else if (pid == 0) {
            if (execvp(args[0], args) == -1) {
                printf("Error executing command.\n");
                exit(1);
            }
        } else {
            waitpid(pid, &status, 0);
        }
    }

    return 1;
}