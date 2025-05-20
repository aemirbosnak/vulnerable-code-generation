//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT 1024
#define MAX_ARGS 100
#define DELIM " \t\r\n"

// Function prototypes
void execute_command(char **args);
char **parse_input(char *input);
void prompt(void);
void handle_sigint(int sig);
void handle_sigchld(int sig);

int main() {
    char input[MAX_INPUT];
    char **args;

    // Set up signal handlers for CTRL+C and zombie processes
    signal(SIGINT, handle_sigint);
    signal(SIGCHLD, handle_sigchld);

    while (1) {
        prompt(); // Display the custom shell prompt
        if (!fgets(input, sizeof(input), stdin)) {
            break; // Exit on EOF (Ctrl+D)
        }

        if (input[0] == '\n') {
            continue; // Ignore empty input
        }

        args = parse_input(input);
        if (args[0] != NULL) {
            execute_command(args);
        }

        free(args); // Free allocated memory for command arguments
    }

    return 0;
}

// Display the shell prompt
void prompt(void) {
    printf("MyShell> ");
}

// Execute the command
void execute_command(char **args) {
    pid_t pid, wpid;
    int status;

    pid = fork(); // Create a new process
    if (pid == -1) {
        perror("fork");
        return;
    }
    if (pid == 0) { // Child process
        if (execvp(args[0], args) == -1) {
            perror("exec");
        }
        exit(EXIT_FAILURE);
    } else { // Parent process
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

// Parse the user input into command and arguments
char **parse_input(char *input) {
    char **args = malloc(MAX_ARGS * sizeof(char*));
    char *token;
    int position = 0;

    token = strtok(input, DELIM);
    while (token != NULL) {
        args[position++] = token;
        token = strtok(NULL, DELIM);
    }
    args[position] = NULL; // Null-terminate the list of arguments
    return args;
}

// Handle Ctrl+C signal
void handle_sigint(int sig) {
    printf("\nCaught signal %d, but I am still alive!\n", sig);
    fflush(stdout); // Flush the output buffer
}

// Handle child process termination
void handle_sigchld(int sig) {
    // Remove zombie processes caused by the child
    while (waitpid(-1, NULL, WNOHANG) > 0);
}