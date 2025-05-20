//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LENGTH 1024
#define MAX_NUM_ARGS 100

void execute_command(char **args) {
    pid_t pid = fork();
    
    if (pid == 0) { // Child process
        if (execvp(args[0], args) == -1) {
            perror("Error executing command");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("Fork failed");
    } else { // Parent process
        int status;
        waitpid(pid, &status, 0);
    }
}

void parse_input(char *input, char **args) {
    char *token = strtok(input, " \n");
    int position = 0;

    while (token != NULL) {
        args[position++] = token;
        token = strtok(NULL, " \n");
    }
    args[position] = NULL;
}

void display_prompt() {
    char cwd[MAX_CMD_LENGTH];
    getcwd(cwd, sizeof(cwd));
    printf("MyShell: %s$ ", cwd);
}

int main() {
    char *input = NULL;
    size_t len = 0;
    char *args[MAX_NUM_ARGS];

    while (1) {
        display_prompt();

        if (getline(&input, &len, stdin) == -1) {
            perror("getline failed");
            free(input);
            exit(EXIT_FAILURE);
        }

        if (strlen(input) == 1) {
            // If only a newline is entered, skip to next iteration
            continue;
        }

        parse_input(input, args);

        // Exit command
        if (strcmp(args[0], "exit") == 0) {
            free(input);
            exit(EXIT_SUCCESS);
        }

        execute_command(args);
    }

    free(input);
    return 0;
}