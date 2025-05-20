//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE_LENGTH 1024
#define DELIM " "
#define MAX_COMMAND_LENGTH 1024
#define MAX_ARG_COUNT 10

char **split_line(char *line) {
    char **tokens = malloc(MAX_ARG_COUNT * sizeof(char*));
    int count = 0;
    char *token;
    for (token = strtok(line, DELIM); token!= NULL; token = strtok(NULL, DELIM)) {
        tokens[count] = strdup(token);
        count++;
        if (count >= MAX_ARG_COUNT) {
            break;
        }
    }
    tokens[count] = NULL;
    return tokens;
}

int execute_command(char **tokens) {
    pid_t pid;
    int status;
    if (tokens[0] == NULL) {
        fprintf(stderr, "Error: command not found.\n");
        return 1;
    }
    if (strcmp(tokens[0], "exit") == 0) {
        return 0;
    }
    pid = fork();
    if (pid == -1) {
        fprintf(stderr, "Error: fork failed.\n");
        return 1;
    } else if (pid == 0) {
        if (execvp(tokens[0], tokens) == -1) {
            fprintf(stderr, "Error: %s not found.\n", tokens[0]);
            return 1;
        }
    } else {
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else {
            return 1;
        }
    }
}

int main() {
    char input[MAX_LINE_LENGTH];
    char **tokens;
    pid_t pid;
    int status;

    printf("Welcome to the Shell!\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_LINE_LENGTH, stdin);
        tokens = split_line(input);
        if (tokens[0] == NULL) {
            continue;
        }
        pid = fork();
        if (pid == -1) {
            fprintf(stderr, "Error: fork failed.\n");
            continue;
        } else if (pid == 0) {
            execute_command(tokens);
            exit(0);
        } else {
            waitpid(pid, &status, 0);
            if (WIFEXITED(status)) {
                printf("Command completed with exit code %d.\n", WEXITSTATUS(status));
            } else {
                printf("Command terminated abnormally.\n");
            }
        }
    }

    return 0;
}