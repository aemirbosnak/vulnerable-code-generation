//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command);
int execute_command(char **args);

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;

    printf("Welcome to the Basic Unix-like Shell!\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        args = split_command(input);

        if (args[0] == NULL) {
            continue;
        }

        execute_command(args);
    }

    return 0;
}

char **split_command(char *command) {
    char *token;
    int argc = 0;
    char **args = malloc(sizeof(char *) * (MAX_COMMAND_LENGTH/2));

    token = strtok(command, DELIM);
    while (token!= NULL) {
        args[argc++] = token;
        token = strtok(NULL, DELIM);
    }
    args[argc] = NULL;

    return args;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        return 1;
    }

    if (strcmp(args[0], "exit") == 0) {
        return 0;
    } else if (strcmp(args[0], "cd") == 0) {
        if (args[1] == NULL) {
            fprintf(stderr, "Usage: cd [directory]\n");
        } else {
            if (chdir(args[1])!= 0) {
                perror("chdir");
            }
        }
    } else if (strcmp(args[0], "pwd") == 0) {
        char cwd[1024];
        getcwd(cwd, sizeof(cwd));
        printf("%s\n", cwd);
    } else {
        pid = fork();

        if (pid == -1) {
            perror("fork");
        } else if (pid == 0) {
            execvp(args[0], args);
            perror("execvp");
            exit(1);
        } else {
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}