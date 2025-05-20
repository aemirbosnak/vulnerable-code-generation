//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024
#define TOKEN_DELIMITER " \t\r\n\a"

// function to read input from user
char *read_input(void) {
    char *buffer = malloc(sizeof(char) * BUFFER_SIZE);
    fgets(buffer, BUFFER_SIZE, stdin);

    return buffer;
}

// function to parse input into tokens
char **parse_input(char *input) {
    int buffer_size = BUFFER_SIZE, index = 0;
    char **tokens = malloc(buffer_size * sizeof(char*));
    char *token;

    if (!tokens) {
        fprintf(stderr, "Memory allocation error");
        exit(EXIT_FAILURE);
    }

    token = strtok(input, TOKEN_DELIMITER);
    while (token != NULL) {
        tokens[index++] = token;

        if (index >= buffer_size) {
            buffer_size += BUFFER_SIZE;
            tokens = realloc(tokens, buffer_size * sizeof(char*));
            if (!tokens) {
                fprintf(stderr, "Memory allocation error");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, TOKEN_DELIMITER);
    }

    tokens[index] = NULL;
    return tokens;
}

// function to execute command
int execute_command(char **args) {
    pid_t pid, wait_pid;
    int status;

    pid = fork();
    if (pid == 0) {
        // child process
        if (execvp(args[0], args) == -1) {
            perror("shell");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        // error forking
        perror("shell");
    } else {
        // parent process
        do {
            wait_pid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}

// shell loop
void shell_loop(void) {
    char *input;
    char **args;
    int status;

    do {
        printf("> ");
        input = read_input();
        args = parse_input(input);
        status = execute_command(args);

        free(input);
        free(args);
    } while (status);
}

int main() {
    shell_loop();
    return EXIT_SUCCESS;
}