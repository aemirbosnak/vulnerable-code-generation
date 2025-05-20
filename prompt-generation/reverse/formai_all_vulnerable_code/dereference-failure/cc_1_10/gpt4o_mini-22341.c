//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARG_SIZE 100
#define DELIM " \t\r\n\a"

void print_prompt() {
    printf("mysh> ");
}

char* read_input() {
    char *input = malloc(MAX_INPUT_SIZE * sizeof(char));
    if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL) {
        free(input);
        return NULL; // EOF
    }
    return input;
}

char** parse_input(char* input) {
    char **args = malloc(MAX_ARG_SIZE * sizeof(char*));
    char *arg;
    int position = 0;

    arg = strtok(input, DELIM);
    while (arg != NULL) {
        args[position++] = arg;
        arg = strtok(NULL, DELIM);
    }
    args[position] = NULL; // Null-terminate the array
    return args;
}

int execute_command(char** args) {
    if (args[0] == NULL) {
        return 1; // Empty command
    }

    pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == 0) { // Child process
        if (execvp(args[0], args) == -1) {
            perror("mysh");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("mysh");
    } else { // Parent process
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    return 1;
}

void free_memory(char* input, char** args) {
    free(input);
    free(args);
}

int main() {
    char *input;
    char **args;
    int status = 1;

    do {
        print_prompt();
        input = read_input();
        if (input == NULL) {
            break; // End of input
        }
        args = parse_input(input);
        status = execute_command(args);
        free_memory(input, args);
    } while (status);

    return 0;
}