//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

// Maximum line length
#define MAX_LINE 1024

// Maximum number of arguments
#define MAX_ARGS 64

// Delimiter for arguments
#define DELIM " "

// Built-in commands
#define BUILTIN_EXIT "exit"
#define BUILTIN_CD "cd"

// Handle built-in commands
int handle_builtin(char **args) {
    if (strcmp(args[0], BUILTIN_EXIT) == 0) {
        exit(0);
    } else if (strcmp(args[0], BUILTIN_CD) == 0) {
        if (args[1] == NULL) {
            fprintf(stderr, "Error: No directory specified\n");
            return 1;
        } else {
            if (chdir(args[1]) != 0) {
                perror("Error");
                return 1;
            }
        }
        return 0;
    } else {
        return -1;
    }
}

// Execute a command
int execute_command(char **args) {
    pid_t pid;
    int status;

    // Fork a child process
    pid = fork();
    if (pid == -1) {
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        // Child process
        // Redirect input/output if necessary
        if (args[1] != NULL && strcmp(args[1], ">") == 0) {
            int fd = open(args[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if (fd < 0) {
                perror("Error opening output file");
                exit(1);
            }
            dup2(fd, STDOUT_FILENO);
            close(fd);
            args[1] = NULL;
            args[2] = NULL;
        }
        if (args[1] != NULL && strcmp(args[1], "<") == 0) {
            int fd = open(args[2], O_RDONLY);
            if (fd < 0) {
                perror("Error opening input file");
                exit(1);
            }
            dup2(fd, STDIN_FILENO);
            close(fd);
            args[1] = NULL;
            args[2] = NULL;
        }
        // Execute the command
        if (execvp(args[0], args) == -1) {
            perror("Exec failed");
            exit(1);
        }
    } else {
        // Parent process
        // Wait for the child process to finish
        wait(&status);
    }

    return 0;
}

// Parse a line into arguments
char **parse_line(char *line) {
    char **args = malloc(sizeof(char *) * MAX_ARGS);
    char *arg;
    int i = 0;

    arg = strtok(line, DELIM);
    while (arg != NULL) {
        args[i] = arg;
        i++;
        arg = strtok(NULL, DELIM);
    }
    args[i] = NULL;

    return args;
}

// Read a line from the input
char *read_line() {
    char *line = malloc(sizeof(char) * MAX_LINE);
    size_t len = 0;

    if (getline(&line, &len, stdin) == -1) {
        if (feof(stdin)) {
            return NULL;
        } else {
            perror("Error reading line");
            exit(1);
        }
    }

    return line;
}

// Main loop
int main() {
    char *line;
    char **args;
    int status = 0;

    do {
        // Print the prompt
        printf("> ");

        // Read a line from the input
        line = read_line();

        // Parse the line into arguments
        args = parse_line(line);

        // Handle built-in commands
        if (handle_builtin(args) == 0) {
            continue;
        }

        // Execute the command
        if (execute_command(args) != 0) {
            status = 1;
        }

        // Free the arguments
        free(args);

        // Free the line
        free(line);

    } while (status == 0);

    return 0;
}