//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *str) {
    int bufsize = 64, position = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token = strtok(str, DELIM);

    while (token!= NULL) {
        tokens[position] = token;
        position++;

        if (position >= bufsize) {
            bufsize += 64;
            tokens = realloc(tokens, bufsize * sizeof(char*));
        }

        token = strtok(NULL, DELIM);
    }

    tokens[position] = NULL;
    return tokens;
}

pid_t launch_shell(char **args) {
    pid_t pid;

    if (args[0] == NULL) {
        fprintf(stderr, "No command specified.\n");
        return -1;
    }

    pid = fork();

    if (pid == -1) {
        perror("fork");
        return -1;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    } else {
        waitpid(pid, NULL, 0);
    }

    return pid;
}

void handle_signal(int signum) {
    fprintf(stdout, "Interrupted by signal %d\n", signum);
}

int main(void) {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    pid_t shell_pid;

    signal(SIGINT, handle_signal);

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        args = split_string(input);
        shell_pid = launch_shell(args);

        free(args);

        if (shell_pid == -1) {
            continue;
        }

        waitpid(shell_pid, NULL, 0);
    }

    return 0;
}