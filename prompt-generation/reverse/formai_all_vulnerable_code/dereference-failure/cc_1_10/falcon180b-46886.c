//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_string(char *str) {
    int count = 0;
    char **tokens = malloc(MAX_ARGUMENTS * sizeof(char*));
    char *token;

    for (token = strtok(str, DELIM); token!= NULL; token = strtok(NULL, DELIM)) {
        tokens[count++] = token;
        if (count >= MAX_ARGUMENTS) {
            break;
        }
    }
    tokens[count] = NULL;

    return tokens;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
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

int main(int argc, char **argv) {
    char input[MAX_COMMAND_LENGTH];
    char **args;

    printf("Unix-like Shell\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        args = split_string(input);
        if (args[0] == NULL) {
            continue;
        }

        execute_command(args);
    }

    return 0;
}