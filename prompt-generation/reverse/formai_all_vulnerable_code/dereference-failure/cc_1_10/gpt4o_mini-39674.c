//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT 1024
#define MAX_ARGS 100

void execute_command(char **args) {
    pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == -1) {
        perror("fork failed");
        return;
    } else if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("execution error");
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
    int position = 0;
    char *token = strtok(input, " \n");

    while (token != NULL) {
        args[position++] = token;
        token = strtok(NULL, " \n");
    }
    args[position] = NULL; // last element must be NULL for execvp
}

void shell_loop() {
    char *input = NULL;
    char *args[MAX_ARGS];
    size_t bufsize = 0;

    printf("Welcome to My Simple Shell!\n");
    printf("Type 'exit' to leave the shell.\n");

    while (1) {
        printf("myshell> ");
        getline(&input, &bufsize, stdin);
        
        // If input is "exit", break the loop and terminate
        if (strcmp(input, "exit\n") == 0) {
            free(input);
            printf("Exiting shell...\n");
            exit(0);
        }

        parse_input(input, args);
        if (args[0] != NULL) {
            execute_command(args);
        }
    }
}

int main() {
    shell_loop();
    return 0;
}