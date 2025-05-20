//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LEN 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_string(char *str) {
    char **args = malloc(sizeof(char *) * MAX_ARGUMENTS);
    int count = 0;
    char *token = strtok(str, DELIM);

    while (token!= NULL) {
        args[count] = token;
        count++;
        if (count >= MAX_ARGUMENTS) {
            break;
        }
        token = strtok(NULL, DELIM);
    }
    args[count] = NULL;
    return args;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        fprintf(stderr, "Error: Empty command.\n");
        return 1;
    }

    pid = fork();

    if (pid == -1) {
        fprintf(stderr, "Error: Fork failed.\n");
        return 1;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            fprintf(stderr, "Error: %s not found.\n", args[0]);
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

int main(int argc, char **argv) {
    char input[MAX_COMMAND_LEN];
    char **args;

    printf("Welcome to the Shell!\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LEN, stdin);
        args = split_string(input);

        if (args[0] == NULL) {
            continue;
        }

        execute_command(args);
    }

    return 0;
}