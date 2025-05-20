//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT 1024
#define MAX_ARGS 100

void execute_command(char **args) {
    pid_t pid = fork();

    if (pid == -1) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // We are in the child process
        if (execvp(args[0], args) == -1) {
            perror("Execution failed");
            exit(EXIT_FAILURE);
        }
    } else {
        // We are in the parent process
        int status;
        waitpid(pid, &status, 0);
    }
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

int main() {
    char *input = NULL;
    char *args[MAX_ARGS];
    size_t bufsize = 0;

    printf("Welcome to MyShell! Type 'quit' to exit.\n");

    while (1) {
        printf("> ");
        getline(&input, &bufsize, stdin);
        
        // Remove leading/trailing whitespace
        char *end = input + strlen(input) - 1;
        while (end > input && (*end == '\n' || *end == ' ')) end--;
        *(end + 1) = '\0';

        if (strcmp(input, "quit") == 0) {
            free(input);
            printf("Exiting MyShell. Goodbye!\n");
            exit(EXIT_SUCCESS);
        }

        parse_input(input, args);
        
        if (args[0] != NULL) {
            execute_command(args);
        }
    }

    return 0;
}