//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE_SIZE 1024
#define DELIM " \t\r\n\a"

char **split_line(char *line) {
    int bufsize = 0, words = 0;
    char **tokens = NULL;
    char *token;
    char *saveptr;

    token = strtok_r(line, DELIM, &saveptr);
    while (token!= NULL) {
        words++;
        bufsize += strlen(token) + 1;
        token = strtok_r(NULL, DELIM, &saveptr);
    }

    tokens = malloc(sizeof(char *) * (words + 1));
    if (tokens == NULL) {
        fprintf(stderr, "Memory error\n");
        exit(1);
    }

    token = strtok_r(line, DELIM, &saveptr);
    for (int i = 0; i < words; i++) {
        tokens[i] = token;
        token = strtok_r(NULL, DELIM, &saveptr);
    }
    tokens[words] = NULL;

    return tokens;
}

void execute_command(char **tokens) {
    pid_t pid;
    int status;

    if (tokens[0] == NULL)
        return;

    if (strcmp(tokens[0], "exit") == 0) {
        exit(0);
    } else if (strcmp(tokens[0], "cd") == 0) {
        if (tokens[1] == NULL) {
            fprintf(stderr, "Expected argument to \"cd\"\n");
        } else {
            if (chdir(tokens[1])!= 0) {
                fprintf(stderr, "Directory not found\n");
            }
        }
    } else {
        pid = fork();

        if (pid == -1) {
            fprintf(stderr, "Fork error\n");
        } else if (pid == 0) {
            if (execvp(tokens[0], tokens) == -1) {
                fprintf(stderr, "Command not found\n");
                exit(1);
            }
        } else {
            waitpid(pid, &status, 0);
        }
    }
}

int main() {
    char input[MAX_LINE_SIZE];
    char **tokens;

    printf("Welcome to the cheerful shell!\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_LINE_SIZE, stdin);

        tokens = split_line(input);
        execute_command(tokens);

        free(tokens);
    }

    return 0;
}