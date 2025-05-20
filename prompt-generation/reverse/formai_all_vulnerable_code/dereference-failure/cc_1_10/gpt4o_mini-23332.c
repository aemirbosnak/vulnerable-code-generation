//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LINE 1024  // Maximum length for input line
#define MAX_ARGS 100   // Maximum number of arguments

void execute_command(char **args);
void display_help();
void change_directory(char *path);
char **parse_input(char *input);

int main() {
    char *input = NULL;
    size_t len = 0;

    printf("Welcome to My Exciting Shell! 🎉\n");
    printf("Type 'help' to see available commands or 'exit' to leave. Let's go!\n");

    while (1) {
        // Display a prompt
        printf("myshell> ");
        getline(&input, &len, stdin);

        // Strip newline character
        input[strcspn(input, "\n")] = 0;

        // Parse the input into arguments
        char **args = parse_input(input);

        // Execute the command
        if (args[0] != NULL) {
            if (strcmp(args[0], "exit") == 0) {
                free(args);
                break; // Exit the shell
            } else if (strcmp(args[0], "help") == 0) {
                display_help();
            } else if (strcmp(args[0], "cd") == 0) {
                change_directory(args[1]);
            } else {
                execute_command(args); // For other commands
            }
        }
        free(args); // Free allocated memory for arguments
    }

    free(input); // Clean up
    printf("Exiting My Exciting Shell. Goodbye! 👋\n");
    return 0;
}

void execute_command(char **args) {
    pid_t pid, wpid;
    int status;

    if ((pid = fork()) == -1) {
        perror("myshell: fork failed");
        return;
    }

    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("myshell: command not found");
        }
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

void display_help() {
    printf("Here are some commands you can try:\n");
    printf("  cd [directory]     Change current directory\n");
    printf("  help               Show this help message\n");
    printf("  exit               Exit the shell\n");
    printf("For more advanced commands, try executing regular Linux commands!\n");
}

void change_directory(char *path) {
    if (path == NULL) {
        fprintf(stderr, "myshell: cd: missing argument\n");
    } else if (chdir(path) != 0) {
        perror("myshell: cd failed");
    }
}

char **parse_input(char *input) {
    char **args = malloc(MAX_ARGS * sizeof(char *));
    char *token;
    int position = 0;

    token = strtok(input, " ");
    while (token != NULL) {
        args[position++] = token;
        token = strtok(NULL, " ");
    }
    args[position] = NULL; // Null-terminate the argument list 
    return args;
}