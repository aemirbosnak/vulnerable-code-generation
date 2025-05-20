//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *str) {
    int bufsize = 0, i = 0;
    char **tokens = NULL;
    char *token;

    while (*str) {
        if (strchr(DELIM, *str)) {
            *str = '\0';
            bufsize++;
        }
        str++;
    }

    tokens = malloc((bufsize + 1) * sizeof(char *));
    if (!tokens) {
        fprintf(stderr, "Error: memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    str = strtok_r(str, DELIM, &token);
    while (str) {
        tokens[i++] = strdup(str);
        str = strtok_r(NULL, DELIM, &token);
    }
    tokens[i] = NULL;

    return tokens;
}

int launch_shell(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        fprintf(stderr, "Error: command not found.\n");
        return 1;
    }

    pid = fork();
    if (pid == -1) {
        fprintf(stderr, "Error: fork failed.\n");
        return 1;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            fprintf(stderr, "Error: %s failed to launch.\n", args[0]);
            return 1;
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

int main(int argc, char *argv[]) {
    char input[MAX_COMMAND_LENGTH];
    char **args;

    printf("Welcome to the Ephemeral Shell!\n");
    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        args = split_string(input);

        if (args[0] == NULL) {
            continue;
        }

        launch_shell(args);
    }

    return 0;
}