//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_SIZE 1024
#define MAX_ARG_SIZE 100

void print_prompt() {
    printf(">>> ");
}

void parse_input(char *input, char **args) {
    char *token;
    int position = 0;

    token = strtok(input, " \n");
    while (token != NULL) {
        args[position++] = token;
        token = strtok(NULL, " \n");
    }
    args[position] = NULL;
}

void execute_command(char **args) {
    pid_t pid, wpid;
    int status;

    if ((pid = fork()) == -1) {
        perror("fork");
        return;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
        }
        exit(EXIT_FAILURE); // Exit child process if exec fails
    } else {
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

void loop() {
    char *input = malloc(MAX_CMD_SIZE);
    char *args[MAX_ARG_SIZE];

    while (1) {
        print_prompt();
        if (!fgets(input, MAX_CMD_SIZE, stdin)) {
            break; // Exit on Ctrl+D
        }
        parse_input(input, args);

        if (args[0] == NULL) {
            // Empty command, just continue
            continue;
        } else if (strcmp(args[0], "exit") == 0) {
            free(input);
            exit(0);
        }

        execute_command(args);
    }
    free(input);
}

int main() {
    printf("Welcome to the Puzzling Shell!\n");
    printf("Type 'exit' to quit and solve the mystery of the shell...\n");
    loop();
    return 0;
}