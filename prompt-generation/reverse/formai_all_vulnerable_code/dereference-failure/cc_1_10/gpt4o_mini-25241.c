//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARG_SIZE 100
#define MAX_HISTORY 20

// Function declarations
void print_welcome_message();
void execute_command(char *input);
void change_directory(char *path);
void print_history();
void add_to_history(char *command);
void free_memory(char **args);

// Declare a history array
char *history[MAX_HISTORY];
int history_count = 0;

int main() {
    print_welcome_message();
    
    char input[MAX_INPUT_SIZE];

    while (true) {
        printf("myshell> ");
        fflush(stdout); // Ensure the prompt is displayed immediately
        
        // Read user input
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("\nExiting shell. Thank you for using this program!\n");
            exit(0);
        }

        // Remove newline character from input
        input[strcspn(input, "\n")] = 0;

        // If input is empty, skip to the next iteration
        if (strlen(input) == 0) {
            continue;
        }

        // Execute the command
        execute_command(input);
    }
    
    return 0;
}

void print_welcome_message() {
    printf("Welcome to MyShell!\n");
    printf("Thank you for using this simple shell program!\n");
    printf("Type 'exit' to leave, or 'history' to see previous commands.\n");
}

void execute_command(char *input) {
    char *args[MAX_ARG_SIZE];
    char *token;
    int arg_count = 0;

    // Split string input into tokens
    token = strtok(input, " ");
    while (token != NULL) {
        args[arg_count++] = token;
        token = strtok(NULL, " ");
    }
    args[arg_count] = NULL; // Null-terminate the array of arguments

    // Command handling logic
    if (arg_count == 0) {
        // No command entered, do nothing
        return;
    } else if (strcmp(args[0], "exit") == 0) {
        printf("Exiting shell. Thank you for using this program!\n");
        exit(0);
    } else if (strcmp(args[0], "cd") == 0) {
        change_directory(args[1]);
        return;
    } else if (strcmp(args[0], "history") == 0) {
        print_history();
        return;
    } else {
        // Add to history before executing
        add_to_history(input);
    }

    // Create a child process to execute the command
    pid_t pid = fork();
    if (pid == 0) {
        // In the child process
        if (execvp(args[0], args) < 0) {
            perror("Error executing command");
        }
        exit(1); // Exit child process on error
    } else if (pid < 0) {
        perror("Fork failed");
    } else {
        // In the parent process, wait for the child to finish
        wait(NULL);
    }
}

void change_directory(char *path) {
    if (path == NULL) {
        fprintf(stderr, "cd: missing argument\n");
        return;
    }
    
    if (chdir(path) != 0) {
        perror("cd failed");
    }
}

void print_history() {
    printf("Command History:\n");
    for (int i = 0; i < history_count; i++) {
        printf("%d: %s\n", i + 1, history[i]);
    }
}

void add_to_history(char *command) {
    if (history_count < MAX_HISTORY) {
        history[history_count++] = strdup(command);
    } else {
        free(history[0]);
        for (int i = 1; i < MAX_HISTORY; i++) {
            history[i - 1] = history[i];
        }
        history[MAX_HISTORY - 1] = strdup(command);
    }
}

void free_memory(char **args) {
    for (int i = 0; args[i] != NULL; i++) {
        free(args[i]);
    }
}