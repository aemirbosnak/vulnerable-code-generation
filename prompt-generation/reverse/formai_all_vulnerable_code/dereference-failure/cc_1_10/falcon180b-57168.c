//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <ctype.h>

#define MAX_COMMAND_LENGTH 4096
#define MAX_ARGUMENTS 1000
#define DELIM " \t\n\r\a"
#define BUFFER_SIZE 1024

char **split_string(char *str) {
    int count = 0, i = 0;
    char **tokens = NULL;
    char *token;

    while ((token = strtok(str, DELIM))) {
        count++;
        tokens = realloc(tokens, sizeof(char *) * count);
        tokens[i] = token;
        i++;
    }
    tokens[i] = NULL;

    return tokens;
}

void execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        fprintf(stderr, "Error: command not found\n");
        return;
    }

    pid = fork();

    if (pid == -1) {
        perror("fork");
        return;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }
}

void signal_handler(int signum) {
    if (signum == SIGINT) {
        fprintf(stdout, "\n");
    }
}

int main(void) {
    char input[BUFFER_SIZE];
    char **args = NULL;
    pid_t pid;
    int status;

    signal(SIGINT, signal_handler);

    while (1) {
        fprintf(stdout, "> ");
        fgets(input, BUFFER_SIZE, stdin);

        args = split_string(input);

        if (args[0] == NULL) {
            continue;
        }

        execute_command(args);

        free(args);
        args = NULL;
    }

    return 0;
}