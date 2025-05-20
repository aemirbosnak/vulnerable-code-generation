//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARG_SIZE 100

void execute_command(char **args) {
    pid_t pid, wpid;
    int status;

    // Create a child process
    pid = fork();
    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("Error executing command");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        // Fork failure
        perror("Fork failed");
    } else {
        // Parent process
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

void change_directory(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "cd: missing argument\n");
    } else {
        if (chdir(args[1]) != 0) {
            perror("cd error");
        }
    }
}

void parse_input(char *input, char **args) {
    while (*input) {
        while (*input == ' ') {
            input++;
        }
        if (*input == '\0') break;

        *args++ = input;

        while (*input && *input != ' ') {
            input++;
        }
        if (*input) {
            *input++ = '\0';
        }
    }
    *args = NULL; // Null-terminate the argument list
}

int main() {
    char *input = NULL; 
    size_t len = 0; 
    char *args[MAX_ARG_SIZE];
    
    while (1) {
        printf("myshell> "); // Print shell prompt
        getline(&input, &len, stdin); // Get user input

        // Remove newline character from input
        size_t input_length = strlen(input);
        if (input_length > 0 && input[input_length - 1] == '\n') {
            input[input_length - 1] = '\0';
        }

        parse_input(input, args);

        // Check for built-in commands
        if (args[0] == NULL) {
            continue; // Empty command
        } else if (strcmp(args[0], "exit") == 0) {
            break; // Exit the shell
        } else if (strcmp(args[0], "cd") == 0) {
            change_directory(args);
            continue; // Continue to the next command
        }

        execute_command(args); // Execute external commands
    }

    free(input);
    return 0;
}