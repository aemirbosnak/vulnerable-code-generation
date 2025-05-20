//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>

// Debug mode flag
int debug = 0;

// Tokenize a string into an array of strings
char **tokenize(char *str) {
    char **tokens = malloc(sizeof(char *) * 100);
    int i = 0;
    char *token = strtok(str, " ");
    while (token != NULL) {
        tokens[i++] = token;
        token = strtok(NULL, " ");
    }
    tokens[i] = NULL;
    return tokens;
}

// Execute a command
int execute(char **argv) {
    pid_t pid = fork();
    if (pid == 0) {
        if (debug) {
            fprintf(stderr, "Child: Executing %s\n", argv[0]);
        }
        execvp(argv[0], argv);
        fprintf(stderr, "Child: Failed to execute %s\n", argv[0]);
        exit(1);
    } else {
        int status;
        waitpid(pid, &status, 0);
        if (debug) {
            fprintf(stderr, "Parent: Child %d exited with status %d\n", pid, status);
        }
        return status;
    }
}

// Built-in command: cd
int cd(char **argv) {
    if (argv[1] == NULL) {
        fprintf(stderr, "cd: No argument specified\n");
        return 1;
    }
    if (chdir(argv[1]) != 0) {
        fprintf(stderr, "cd: Failed to change directory to %s\n", argv[1]);
        return 1;
    }
    return 0;
}

// Built-in command: exit
int exit_(char **argv) {
    exit(0);
}

// Built-in command: help
int help_(char **argv) {
    printf("Usage: %s [command] [arguments]\n", argv[0]);
    printf("Available commands:\n");
    printf("  cd [directory]    Change the current working directory\n");
    printf("  exit              Exit the shell\n");
    printf("  help              Print this help message\n");
    return 0;
}

// Main loop
int main() {
    while (1) {
        // Print the current working directory
        char cwd[1024];
        if (getcwd(cwd, sizeof(cwd)) == NULL) {
            fprintf(stderr, "Failed to get current working directory\n");
            exit(1);
        }
        printf("%s > ", cwd);

        // Read a line of input from the user
        char line[1024];
        if (fgets(line, sizeof(line), stdin) == NULL) {
            fprintf(stderr, "Failed to read input from user\n");
            exit(1);
        }

        // Tokenize the input line
        char **argv = tokenize(line);

        // Check if the command is built-in
        if (strcmp(argv[0], "cd") == 0) {
            cd(argv);
        } else if (strcmp(argv[0], "exit") == 0) {
            exit_(argv);
        } else if (strcmp(argv[0], "help") == 0) {
            help_(argv);
        } else {
            // Execute the command
            execute(argv);
        }

        // Free the memory allocated by tokenize
        free(argv);
    }

    return 0;
}