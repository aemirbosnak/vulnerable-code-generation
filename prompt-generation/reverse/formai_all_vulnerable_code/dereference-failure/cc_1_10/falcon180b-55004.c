//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 1024
#define DELIM " \t\r\n\a"

char **split_line(char *line) {
    int buf_size = 64, position = 0;
    char **tokens = malloc(buf_size * sizeof(char *));
    char *token = strtok(line, DELIM);

    while (token!= NULL) {
        if (position >= buf_size) {
            buf_size += 64;
            tokens = realloc(tokens, buf_size * sizeof(char *));
        }

        tokens[position++] = token;
        token = strtok(NULL, DELIM);
    }

    tokens[position] = NULL;
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
                perror("chdir");
            }
        }
    } else {
        pid = fork();

        if (pid == -1) {
            fprintf(stderr, "Fork failed\n");
        } else if (pid == 0) {
            if (execvp(tokens[0], tokens) == -1) {
                fprintf(stderr, "Command not found: %s\n", tokens[0]);
            }
        } else {
            waitpid(pid, &status, 0);
        }
    }
}

void loop(void) {
    char input[MAX_LINE];
    char **tokens;

    printf("> ");
    fgets(input, MAX_LINE, stdin);

    tokens = split_line(input);
    execute_command(tokens);

    free(tokens);
}

int main(void) {
    loop();

    return 0;
}