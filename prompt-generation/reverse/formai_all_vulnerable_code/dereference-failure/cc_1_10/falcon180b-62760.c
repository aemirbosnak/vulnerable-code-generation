//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *str) {
    int bufsize = MAX_COMMAND_LENGTH;
    int words = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token = strtok(str, DELIM);

    while (token!= NULL) {
        tokens[words] = token;
        words++;
        if (words >= bufsize) {
            bufsize += MAX_COMMAND_LENGTH;
            tokens = realloc(tokens, bufsize * sizeof(char*));
        }
        token = strtok(NULL, DELIM);
    }
    tokens[words] = NULL;
    return tokens;
}

void execute_command(char **args) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }
}

void handle_signal(int signum) {
    switch (signum) {
        case SIGINT:
            printf("\nInterrupted by user.\n");
            break;
        case SIGQUIT:
            printf("\nQuit by user.\n");
            break;
        case SIGTERM:
            printf("\nTerminated.\n");
            break;
        default:
            printf("\nUnknown signal %d received.\n", signum);
    }
    exit(1);
}

int main(int argc, char *argv[]) {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    int i;

    signal(SIGINT, handle_signal);
    signal(SIGQUIT, handle_signal);
    signal(SIGTERM, handle_signal);

    printf("Sherlock Holmes' Basic Unix-like Shell\n");
    printf("Enter 'exit' to terminate the shell.\n\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        args = split_string(input);

        if (strcmp(args[0], "exit") == 0) {
            break;
        } else {
            execute_command(args);
        }
    }

    return 0;
}