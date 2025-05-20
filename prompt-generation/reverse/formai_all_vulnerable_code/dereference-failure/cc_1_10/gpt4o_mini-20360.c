//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024
#define MAX_ARG_LEN 100
#define MAX_ARGS 20

void execute_command(char **args);
void change_directory(char *path);
char *read_input();
char **parse_input(char *input);

int main() {
    char *input;
    char **args;
    char *prompt = "mysh> ";

    while (1) {
        printf("%s", prompt);
        input = read_input();

        // Exit if input is NULL
        if (input == NULL) {
            break;
        }

        // Parse the input
        args = parse_input(input);
        if (args[0] == NULL) {
            free(input);
            free(args);
            continue; // Skip empty commands
        }

        // Check for built-in commands
        if (strcmp(args[0], "exit") == 0) {
            free(input);
            free(args);
            exit(0); // Exit the shell
        } else if (strcmp(args[0], "cd") == 0) {
            change_directory(args[1]);
        } else {
            execute_command(args);
        }

        // Free allocated memory
        free(input);
        free(args);
    }
    return 0;
}

char *read_input() {
    char *input = (char *)malloc(MAX_CMD_LEN);
    if (!fgets(input, MAX_CMD_LEN, stdin)) {
        free(input);
        return NULL; // Handle EOF or error
    }
    // Remove trailing new line character
    input[strcspn(input, "\n")] = 0;
    return input;
}

char **parse_input(char *input) {
    char **args = (char **)malloc(MAX_ARGS * sizeof(char *));
    char *token;
    int index = 0;

    token = strtok(input, " ");
    while (token != NULL) {
        args[index++] = token;
        token = strtok(NULL, " ");
        if (index >= MAX_ARGS - 1) break; // Prevent overflow
    }
    args[index] = NULL; // Null-terminate the arguments
    return args;
}

void change_directory(char *path) {
    if (path == NULL || strlen(path) == 0) {
        chdir(getenv("HOME")); // Change to home directory if no path is provided
    } else if (chdir(path) != 0) {
        perror("cd error"); // Print error if chdir fails
    }
}

void execute_command(char **args) {
    pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == 0) {
        // In child process
        if (execvp(args[0], args) == -1) {
            perror("Command execution failed");
        }
        exit(EXIT_FAILURE); // Exit child if exec fails
    } else if (pid < 0) {
        perror("Forking error");
    } else {
        // In parent process
        do {
            wpid = waitpid(pid, &status, WUNTRACED); // Wait for the child to finish
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}