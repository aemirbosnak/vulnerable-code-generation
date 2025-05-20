//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *str) {
    char **tokens = malloc(sizeof(char *));
    int count = 0;
    char *token = strtok(str, DELIM);

    while (token!= NULL) {
        tokens[count++] = token;
        token = strtok(NULL, DELIM);
    }
    tokens[count] = NULL;

    return tokens;
}

pid_t fork() {
    pid_t pid = -1;
    switch (pid = fork()) {
        case -1:
            printf("fork error\n");
            break;
        case 0:
            break;
        default:
            waitpid(pid, NULL, 0);
            break;
    }
    return pid;
}

int execute_command(char **args) {
    pid_t pid = fork();

    if (pid == -1) {
        printf("fork failed\n");
        return 1;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            printf("command not found\n");
            return 1;
        }
    } else {
        waitpid(pid, NULL, 0);
    }

    return 0;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;

    printf("Unix-like Shell\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        args = split_string(input);

        if (args[0] == NULL)
            continue;

        if (strcmp(args[0], "exit") == 0)
            break;

        execute_command(args);
    }

    return 0;
}