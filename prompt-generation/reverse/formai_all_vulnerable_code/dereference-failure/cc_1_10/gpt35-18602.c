//FormAI DATASET v1.0 Category: System administration ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_ARGS 10

/* Function prototypes */
void execute_command(char **args);
char **parse_args(char *input);

int main(int argc, char **argv) {
    char input[256];
    char **args;

    while (1) {
        printf(">> ");
        fgets(input, sizeof(input), stdin);

        /* Remove trailing newline character from input */
        if (strlen(input) > 0 && input[strlen(input) - 1] == '\n') {
            input[strlen(input) - 1] = '\0';
        }

        args = parse_args(input);
        execute_command(args);

        /* Free allocated memory */
        free(args);
    }

    return 0;
}

/* Execute a command with given arguments */
void execute_command(char **args) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == 0) {
        /* Child process */
        if (execvp(args[0], args) == -1) {
            perror("Error executing command");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("Error forking");
    } else {
        /* Parent process */
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

/* Parse input into an array of arguments */
char **parse_args(char *input) {
    char **args = malloc(MAX_ARGS * sizeof(char *));
    char *arg;
    int i = 0;

    arg = strtok(input, " ");
    while (arg != NULL) {
        args[i] = arg;
        i++;
        arg = strtok(NULL, " ");
    }
    args[i] = NULL;

    return args;
}