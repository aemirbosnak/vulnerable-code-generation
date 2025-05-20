//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_ARGS 64

char **parse_input(char *input);
int execute(char **args);

int main(void) {
    char input[MAX_INPUT_LENGTH];
    char **args;
    int status;

    printf("Welcome to MyShell!\n");
    printf("Type 'exit' to quit.\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_INPUT_LENGTH, stdin);
        if (strcmp(input, "exit\n") == 0) {
            break;
        }
        args = parse_input(input);
        status = execute(args);
        free(args);
    }
    printf("Goodbye!\n");
    return 0;
}

char **parse_input(char *input) {
    char **args = malloc(MAX_ARGS * sizeof(char *));
    char *arg;
    int i = 0;

    if (args == NULL) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }

    arg = strtok(input, " \t\r\n");
    while (arg != NULL) {
        args[i++] = arg;
        arg = strtok(NULL, " \t\r\n");
    }
    args[i] = NULL;
    return args;
}

int execute(char **args) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        /* child process */
        if (execvp(args[0], args) == -1) {
            perror("execvp failed");
            exit(EXIT_FAILURE);
        }
    } else {
        /* parent process */
        do {
            if (waitpid(pid, &status, WUNTRACED) == -1) {
                perror("waitpid failed");
                exit(EXIT_FAILURE);
            }
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    return 1;
}