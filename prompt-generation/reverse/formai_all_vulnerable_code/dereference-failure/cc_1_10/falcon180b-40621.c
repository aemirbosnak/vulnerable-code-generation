//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *str) {
    int bufsize = 0, words = 0;
    char **tokens = NULL;
    char *token;
    char delimiter[2] = " ";

    token = strtok(str, delimiter);
    while (token!= NULL) {
        words++;
        bufsize += strlen(token) + 1;
        token = strtok(NULL, delimiter);
    }

    tokens = malloc(sizeof(char *) * (words + 1));
    if (tokens == NULL) {
        fprintf(stderr, "Memory error\n");
        exit(1);
    }

    bufsize = 0;
    words = 0;
    token = strtok(str, delimiter);
    while (token!= NULL) {
        tokens[words] = malloc(sizeof(char) * (strlen(token) + 1));
        if (tokens[words] == NULL) {
            fprintf(stderr, "Memory error\n");
            exit(1);
        }
        strcpy(tokens[words], token);
        words++;
        bufsize += strlen(token) + 1;
        token = strtok(NULL, delimiter);
    }
    tokens[words] = NULL;

    return tokens;
}

int launch_shell(char **args) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1) {
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            fprintf(stderr, "Exec failed\n");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else if (WIFSIGNALED(status)) {
            fprintf(stderr, "Child terminated by signal\n");
        } else {
            fprintf(stderr, "Unknown child status\n");
        }
    }

    return 0;
}

int main(int argc, char **argv) {
    char input[MAX_COMMAND_LENGTH];
    char **args;

    printf("Retro Shell\n");
    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        args = split_string(input);
        launch_shell(args);
        free(args);
    }

    return 0;
}