//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_NUM_ARGS 100

void execute_command(char **args) {
    pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == 0) { // Child process
        if (execvp(args[0], args) == -1) {
            perror("shell");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("shell");
    } else { // Parent process
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

void parse_input(char *input, char **args) {
    int position = 0;
    char *token;

    token = strtok(input, " \n");
    while (token != NULL) {
        args[position++] = token;
        token = strtok(NULL, " \n");
    }
    args[position] = NULL;
}

void shell_loop() {
    char *input = NULL;
    size_t len = 0;
    char *args[MAX_NUM_ARGS];

    while (1) {
        printf("my_shell> ");
        getline(&input, &len, stdin);
        if (feof(stdin)) {
            free(input);
            break; // Exit shell on Ctrl+D
        }

        // Check for empty input
        if (strlen(input) == 0) {
            continue;
        }

        parse_input(input, args);

        if (args[0] == NULL) {
            continue; // No command entered
        }

        // Built-in command to exit
        if (strcmp(args[0], "exit") == 0) {
            free(input);
            exit(0);
        }

        execute_command(args);
    }
}

int main() {
    printf("Welcome to My Simple Shell!\n");
    printf("Type 'exit' to leave the shell.\n");

    shell_loop();
    return 0;
}