//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: rigorous
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_LINE_SIZE 1024
#define DELIM " \t\r\n\a"

char **split_line(char *line) {
    int buf_size = 0;
    int words = 0;
    char **tokens = NULL;
    char *token;
    char *saveptr = NULL;

    token = strtok_r(line, DELIM, &saveptr);
    while (token!= NULL) {
        words++;
        buf_size += strlen(token) + 1;
        token = strtok_r(NULL, DELIM, &saveptr);
    }

    tokens = malloc(sizeof(char *) * (words + 1));
    if (tokens == NULL) {
        fprintf(stderr, "Error: malloc failed\n");
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

int launch_shell(char **args) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1) {
        fprintf(stderr, "Error: fork failed\n");
        return 1;
    } else if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            fprintf(stderr, "Error: execvp failed\n");
            return 1;
        }
    } else {
        // Parent process
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) &&!WIFSIGNALED(status));

        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else if (WIFSIGNALED(status)) {
            fprintf(stderr, "Error: child process terminated by signal %d\n", WTERMSIG(status));
            return 1;
        } else {
            fprintf(stderr, "Error: unknown wait status\n");
            return 1;
        }
    }
}

int main(int argc, char **argv) {
    char input_buffer[MAX_LINE_SIZE];
    char **args = NULL;

    while (1) {
        fprintf(stdout, "> ");
        if (fgets(input_buffer, MAX_LINE_SIZE, stdin) == NULL) {
            fprintf(stderr, "Error: fgets failed\n");
            return 1;
        }

        args = split_line(input_buffer);
        if (args[0] == NULL) {
            continue;
        }

        int exit_status = launch_shell(args);
        if (exit_status!= 0) {
            fprintf(stderr, "Error: command failed with exit status %d\n", exit_status);
        }

        free(args);
    }

    return 0;
}