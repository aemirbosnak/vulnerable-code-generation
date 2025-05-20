//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LINE 1024 // Maximum input line size
#define MAX_ARGS 100  // Maximum number of arguments

// Function to execute built-in commands
int execute_builtin(char **args) {
    if (strcmp(args[0], "exit") == 0) {
        exit(0);
    } else if (strcmp(args[0], "cd") == 0) {
        if (args[1] == NULL) {
            fprintf(stderr, "cd: missing argument\n");
        } else if (chdir(args[1]) != 0) {
            perror("cd failed");
        }
        return 1; // indicate that a built-in command was executed
    }
    return 0; // indicate no built-in command was executed
}

// Function to read a line from standard input
char *read_line() {
    char *line = malloc(MAX_LINE);
    if (fgets(line, MAX_LINE, stdin) == NULL) {
        free(line);
        return NULL; // EOF or error
    }
    line[strcspn(line, "\n")] = 0; // Remove newline character
    return line;
}

// Function to split a line into arguments
char **split_line(char *line) {
    char **args = malloc(MAX_ARGS * sizeof(char *));
    char *arg;
    int position = 0;

    arg = strtok(line, " ");
    while (arg != NULL) {
        args[position++] = arg;
        arg = strtok(NULL, " ");
    }
    args[position] = NULL; // NULL-terminate the list of arguments
    return args;
}

// Main loop for the shell
void shell_loop() {
    char *line;
    char **args;
    int status;

    do {
        printf("> "); // Display the shell prompt
        line = read_line();
        if (line == NULL) {
            break; // EOF or error
        }
        
        args = split_line(line);
        if (execute_builtin(args)) {
            free(line);
            free(args);
            continue; // A built-in command was executed
        }

        pid_t pid = fork();
        if (pid == 0) { // Child process
            if (execvp(args[0], args) == -1) {
                perror("execution failed");
            }
            exit(EXIT_FAILURE); // Exit child process if exec fails
        } else if (pid < 0) {
            perror("fork failed");
        } else { // Parent process
            do {
                waitpid(pid, &status, WUNTRACED);
            } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        }

        free(line);
        free(args);
    } while (1);
}

int main() {
    shell_loop(); // Start the shell loop
    return 0;
}