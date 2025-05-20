//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024
#define MAX_ARGS 128
#define DELIM " \t\r\n\a"

char *read_cmd(void) {
    char *line = NULL;
    size_t bufsize = 0;
    getline(&line, &bufsize, stdin);
    return line;
}

char **parse_cmd(char *line) {
    int bufsize = MAX_ARGS;
    int position = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token;

    if (!tokens) {
        fprintf(stderr, "Error: allocation failed\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, DELIM);
    while (token != NULL) {
        tokens[position] = token;
        position++;

        if (position >= bufsize) {
            bufsize += MAX_ARGS;
            tokens = realloc(tokens, bufsize * sizeof(char*));
            if (!tokens) {
                fprintf(stderr, "Error: allocation failed\n");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, DELIM);
    }
    tokens[position] = NULL;
    return tokens;
}

void exec_cmd(char **args) {
    pid_t pid, wpid;
    int status;
    pid = fork();
    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("Error: exec failed\n");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("Error: fork failed\n");
    } else {
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

int main(void) {
    char *line;
    char **args;
    int status;

    printf("Welcome to my happy shell!\n");
    printf("Enter a command or 'exit' to quit\n");

    do {
        printf("> ");
        line = read_cmd();
        args = parse_cmd(line);

        if (strcmp(args[0], "exit") == 0) {
            free(line);
            free(args);
            exit(EXIT_SUCCESS);
        }

        exec_cmd(args);

        free(line);
        free(args);
    } while (status);

    return 0;
}