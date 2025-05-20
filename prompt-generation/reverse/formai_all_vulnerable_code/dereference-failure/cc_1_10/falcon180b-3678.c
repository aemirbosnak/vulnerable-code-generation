//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command);
pid_t fork(void);
int execute_command(char **args);

int main(void) {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    pid_t pid;

    printf("Unix-like Shell\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        args = split_command(input);
        pid = fork();

        if (pid == 0) {
            execute_command(args);
            exit(0);
        } else if (pid < 0) {
            printf("Fork failed\n");
        } else {
            int status;
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}

char **split_command(char *command) {
    char **args = malloc(sizeof(char *));
    char *token = strtok(command, DELIM);
    int count = 0;

    while (token!= NULL) {
        args[count] = token;
        count++;
        token = strtok(NULL, DELIM);
    }
    args[count] = NULL;

    return args;
}

pid_t fork(void) {
    return fork();
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
            printf("Expected argument for cd\n");
        } else {
            if (chdir(args[1])!= 0) {
                printf("cd failed\n");
            }
        }
    } else {
        pid = fork();

        if (pid == 0) {
            if (execvp(args[0], args) == -1) {
                printf("Command not found\n");
            }
        } else if (pid < 0) {
            printf("Fork failed\n");
        } else {
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}