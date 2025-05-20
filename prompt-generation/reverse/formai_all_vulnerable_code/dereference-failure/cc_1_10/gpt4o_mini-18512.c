//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGS_LENGTH 100
#define HISTORY_SIZE 10

// Function prototypes
void shell_loop();
void execute_command(char *input);
void add_history(char *input);
void print_history();
char **parse_input(char *input);
void free_args(char **args);

char *history[HISTORY_SIZE];
int history_count = 0;

// Main function
int main() {
    shell_loop();
    return 0;
}

// Shell loop function
void shell_loop() {
    char input[MAX_COMMAND_LENGTH];

    while (1) {
        printf("mysh> ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            perror("fgets");
            continue;
        }

        // Remove the newline character
        input[strcspn(input, "\n")] = 0;
        if (strlen(input) == 0) continue;

        add_history(input);
        execute_command(input);
    }
}

// Function to execute the command
void execute_command(char *input) {
    char **args = parse_input(input);
    
    if (args[0] == NULL) {
        free_args(args);
        return; // No command entered
    }

    if (strcmp(args[0], "exit") == 0) {
        free_args(args);
        exit(0);
    } else if (strcmp(args[0], "cd") == 0) {
        if (args[1] == NULL) {
            fprintf(stderr, "mysh: cd: missing argument\n");
        } else if (chdir(args[1]) != 0) {
            perror("mysh: cd");
        }
    } else if (strcmp(args[0], "history") == 0) {
        print_history();
    } else {
        pid_t pid = fork();
        if (pid == 0) { // Child process
            execvp(args[0], args);
            perror("mysh: exec");
            exit(EXIT_FAILURE);
        } else if (pid < 0) {
            perror("mysh: fork");
        } else { // Parent process
            waitpid(pid, NULL, 0);
        }
    }

    free_args(args);
}

// Function to add command to history
void add_history(char *input) {
    if (history_count < HISTORY_SIZE) {
        history[history_count++] = strdup(input);
    } else {
        free(history[0]);
        memmove(history, history + 1, (HISTORY_SIZE - 1) * sizeof(char *));
        history[HISTORY_SIZE - 1] = strdup(input);
    }
}

// Function to print command history
void print_history() {
    for (int i = 0; i < history_count; i++) {
        printf("%d %s\n", i + 1, history[i]);
    }
}

// Function to parse input into arguments
char **parse_input(char *input) {
    char **args = malloc(MAX_ARGS_LENGTH * sizeof(char *));
    char *token;
    int position = 0;

    token = strtok(input, " ");
    while (token != NULL) {
        args[position++] = token;
        token = strtok(NULL, " ");
    }
    args[position] = NULL; // Null-terminate the array of arguments
    return args;
}

// Function to free allocated memory for arguments
void free_args(char **args) {
    free(args);
}