//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <wait.h>

#define MAX_LINE 1024
#define MAX_ARGS 100

void execute_command(char **args) {
    pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("exec");
        }
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

void parse_input(char *input, char **args) {
    int i = 0;
    char *token;

    token = strtok(input, " \n");
    while (token != NULL && i < MAX_ARGS - 1) {
        args[i++] = token;
        token = strtok(NULL, " \n");
    }
    args[i] = NULL;
}

bool is_exit_command(char *input) {
    return strcmp(input, "exit") == 0;
}

int main() {
    char *input = NULL;
    char *args[MAX_ARGS];
    size_t len = 0;
    ssize_t read;

    printf("Welcome to Minimalist Shell (Mish)\nType 'exit' to quit.\n");

    while (true) {
        printf("mish> ");
        
        read = getline(&input, &len, stdin);
        if (read == -1) {
            perror("getline");
            free(input);
            exit(EXIT_FAILURE);
        }

        if (is_exit_command(input)) {
            break;
        }

        parse_input(input, args);
        if (args[0] != NULL) {
            execute_command(args);
        }
    }

    free(input);
    printf("Goodbye!\n");
    return 0;
}