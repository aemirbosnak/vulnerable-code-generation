//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARG_SIZE 100

void handle_sigint(int sig) {
    printf("\nUse 'exit' to quit the shell.\n");
}

void execute_command(char *input) {
    char *args[MAX_ARG_SIZE];
    char *token;
    int arg_count = 0;

    // Tokenize the input string
    token = strtok(input, " \n");
    while (token != NULL && arg_count < MAX_ARG_SIZE - 1) {
        args[arg_count++] = token;
        token = strtok(NULL, " \n");
    }
    args[arg_count] = NULL; // Last element should be NULL for execvp

    if (arg_count == 0) {
        return; // No command entered
    }

    pid_t pid = fork();
    
    if (pid < 0) {
        perror("Fork failed");
        return;
    } else if (pid == 0) {
        // Child process
        if (execvp(args[0], args) < 0) {
            perror("Command execution failed");
            exit(EXIT_FAILURE);
        }
    } else {
        // Parent process
        wait(NULL); // Wait for child process to finish
    }
}

void prompt() {
    printf("myShell> ");
    fflush(stdout);
}

void trim_input(char *input) {
    char *end;

    // Trim leading whitespace
    while(isspace((unsigned char)*input)) input++;

    // Trim trailing whitespace
    end = input + strlen(input) - 1;
    while(end > input && isspace((unsigned char)*end)) end--;

    // Null terminate after the last non-whitespace character
    *(end + 1) = '\0';
}

int main() {
    char input[MAX_INPUT_SIZE];

    // Setup signal handler for SIGINT
    signal(SIGINT, handle_sigint);

    while (1) {
        prompt();
        if (fgets(input, sizeof(input), stdin) == NULL) {
            perror("Input error");
            continue;
        }

        trim_input(input);

        if (strcmp(input, "exit") == 0) {
            break; // Exit the shell
        }

        execute_command(input);
    }

    return 0;
}