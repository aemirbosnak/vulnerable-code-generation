//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

void execute(char **args) {
    pid_t pid = fork();
    
    // Child process
    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("Error executing command");
            exit(EXIT_FAILURE);
        }
    // Parent process
    } else if (pid < 0) {
        perror("Error forking process");
    } else {
        int status;
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

char **split_input(char *input) {
    char **args = malloc(BUFFER_SIZE * sizeof(char *));
    char *arg;
    int i = 0;

    if (!args) {
        perror("Allocation error");
        exit(EXIT_FAILURE);
    }

    arg = strtok(input, " \t\r\n\a");
    while (arg != NULL) {
        args[i++] = arg;
        arg = strtok(NULL, " \t\r\n\a");
    }
    args[i] = NULL;
    return args;
}

char *read_input(void) {
    char *input = NULL;
    size_t input_size = 0;
    getline(&input, &input_size, stdin);
    return input;
}

int main(int argc, char **argv) {
    char *input;
    char **args;
    int status;

    printf("Welcome to Secure Shell. Type 'exit' to quit.\n");

    do {
        printf("> ");
        input = read_input();
        args = split_input(input);
        execute(args);

        free(input);
        free(args);
    } while (status);

    return EXIT_SUCCESS;
}