//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *str) {
    char **tokens = malloc(sizeof(char *));
    int count = 0;
    char *token = strtok(str, DELIM);

    while (token!= NULL) {
        tokens[count] = malloc(sizeof(char) * (strlen(token) + 1));
        strcpy(tokens[count], token);
        count++;
        token = strtok(NULL, DELIM);
    }

    tokens[count] = NULL;
    return tokens;
}

int execute_command(char **args) {
    pid_t pid = fork();

    if (pid == -1) {
        printf("Fork failed\n");
        return 1;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            printf("Failed to execute command\n");
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

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        args = split_string(input);
        if (args[0] == NULL)
            continue;

        execute_command(args);
    }

    return 0;
}