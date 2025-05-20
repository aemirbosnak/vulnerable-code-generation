//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#include<errno.h>

#define MAXLINE 1024

char **split_line(char *line) {
    int bufsize = 64, position = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token;

    token = strtok(line, " ");
    while (token!= NULL) {
        tokens[position] = token;
        position++;

        if (position >= bufsize) {
            bufsize += 64;
            tokens = realloc(tokens, bufsize * sizeof(char*));
        }

        token = strtok(NULL, " ");
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
        if (tokens[1]!= NULL) {
            if (chdir(tokens[1])!= 0) {
                perror("Error");
            }
        } else {
            fprintf(stderr, "Expected argument to \"cd\"\n");
        }
    } else {
        pid = fork();

        if (pid == -1) {
            perror("Error");
        } else if (pid == 0) {
            if (execvp(tokens[0], tokens) == -1) {
                perror("Error");
            }
        } else {
            waitpid(pid, &status, 0);
        }
    }
}

void loop(char *line) {
    char **tokens = split_line(line);
    execute_command(tokens);
    free(tokens);
}

int main() {
    char input[MAXLINE];

    while (1) {
        printf("> ");
        if (fgets(input, MAXLINE, stdin) == NULL) {
            fprintf(stderr, "Error reading input\n");
            exit(1);
        }
        loop(input);
    }

    return 0;
}