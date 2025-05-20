//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: Donald Knuth
/* The Amazing Unix-like Shell */
// by a chatbot in Donald Knuth style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 256

char *parse_input(char *input, char **args, size_t args_len) {
    size_t i = 0;
    char *token = strtok(input, " ");

    while (token != NULL && i < args_len) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }

    return args[0];
}

void execute_command(char **args, int num_args) {
    pid_t pid = fork();

    if (pid < 0) {
        fprintf(stderr, "fork failed\n");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // child process
        if (execvp(args[0], args) == -1) {
            fprintf(stderr, "execvp failed\n");
            exit(EXIT_FAILURE);
        }
    } else {
        // parent process
        int status;
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

void show_prompt() {
    char cwd[MAX_INPUT_LENGTH];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("%s $ ", cwd);
    } else {
        printf("$ ");
    }
}

int main(int argc, char **argv) {
    char input[MAX_INPUT_LENGTH];
    char *args[MAX_INPUT_LENGTH];
    char *command;
    int num_args;

    while (1) {
        show_prompt();

        fgets(input, MAX_INPUT_LENGTH, stdin);

        // remove newline character
        input[strcspn(input, "\n")] = 0;

        num_args = sizeof(args) / sizeof(args[0]);
        command = parse_input(input, args, num_args);

        if (strcmp(command, "exit") == 0) {
            exit(EXIT_SUCCESS);
        }

        execute_command(args, num_args);
    }

    return EXIT_SUCCESS;
}