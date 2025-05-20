//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_NUM_ARGS 100

void execute_command(char **args);
void parse_input(char *input, char **args);
void shell_loop();

int main() {
    shell_loop();
    return 0;
}

void shell_loop() {
    char *input = NULL;
    size_t len = 0;
    char *args[MAX_NUM_ARGS];

    while (1) {
        printf("mysh> "); // shell prompt
        if (getline(&input, &len, stdin) == -1) {
            perror("getline");
            exit(EXIT_FAILURE);
        }
        
        // Remove newline character from input
        input[strcspn(input, "\n")] = 0;

        parse_input(input, args);

        if (args[0] == NULL) {
            continue; // Empty command
        }

        if (strcmp(args[0], "exit") == 0) {
            free(input);
            exit(EXIT_SUCCESS);
        }

        if (strcmp(args[0], "cd") == 0) {
            if (args[1] == NULL) {
                fprintf(stderr, "mysh: cd: missing argument\n");
            } else if (chdir(args[1]) != 0) {
                perror("mysh: cd");
            }
            continue;
        }

        execute_command(args);
    }

    free(input);
}

void parse_input(char *input, char **args) {
    char *token;
    int position = 0;

    token = strtok(input, " ");
    while (token != NULL) {
        args[position] = token;
        position++;
        if (position >= MAX_NUM_ARGS - 1) {
            fprintf(stderr, "mysh: too many arguments\n");
            break;
        }
        token = strtok(NULL, " ");
    }
    args[position] = NULL; // last argument must be NULL
}

void execute_command(char **args) {
    pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("mysh");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("mysh: fork");
    } else {
        // Parent process
        do {
            wpid = waitpid(pid, &status, WNOHANG);
        } while (wpid == 0);
    }
}