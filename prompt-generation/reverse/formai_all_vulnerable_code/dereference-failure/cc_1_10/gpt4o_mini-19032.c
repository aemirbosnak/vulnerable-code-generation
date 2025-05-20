//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024
#define MAX_ARGS 100
#define HISTORY_SIZE 10

void execute_command(char **args);
void parse_command(char *input, char **args);
void add_to_history(char *command, char history[][MAX_CMD_LEN], int *count);
void print_history(char history[][MAX_CMD_LEN], int count);

int main() {
    char *input = NULL;
    size_t len = 0;
    char *args[MAX_ARGS];
    char history[HISTORY_SIZE][MAX_CMD_LEN];
    int history_count = 0;

    printf("Welcome to MyShell! Type 'exit' to quit.\n");
    
    while (1) {
        printf("MyShell> ");
        if (getline(&input, &len, stdin) == -1) {
            perror("getline");
            free(input);
            exit(EXIT_FAILURE);
        }

        input[strcspn(input, "\n")] = 0; // Remove newline character
        
        // Handle exit command
        if (strcmp(input, "exit") == 0) {
            free(input);
            break;
        }

        // Add command to history
        add_to_history(input, history, &history_count);

        // Parse the input command
        parse_command(input, args);

        // Execute the command
        execute_command(args);
    }

    return 0;
}

void execute_command(char **args) {
    pid_t pid, wpid;
    int status;

    if (args[0] == NULL) return; // If there's nothing to run

    // Fork a child process
    pid = fork();
    if (pid == -1) {
        perror("fork");
        return;
    }

    if (pid == 0) { // Child process
        // Execute the command
        if (execvp(args[0], args) == -1) {
            perror("exec");
        }
        exit(EXIT_FAILURE); // Exit the child process
    } else { // Parent process
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

void parse_command(char *input, char **args) {
    char *token;
    int position = 0;

    // Split the input string into tokens
    token = strtok(input, " ");
    while (token != NULL) {
        args[position++] = token;
        token = strtok(NULL, " ");
    }
    args[position] = NULL; // Null terminate the array
}

void add_to_history(char *command, char history[][MAX_CMD_LEN], int *count) {
    if (*count < HISTORY_SIZE) {
        strncpy(history[*count], command, MAX_CMD_LEN);
        (*count)++;
    } else {
        // If history is full, shift up the oldest command
        for (int i = 1; i < HISTORY_SIZE; i++) {
            strncpy(history[i-1], history[i], MAX_CMD_LEN);
        }
        strncpy(history[HISTORY_SIZE-1], command, MAX_CMD_LEN);
    }
}

void print_history(char history[][MAX_CMD_LEN], int count) {
    for (int i = 0; i < count; i++) {
        printf("%d: %s\n", i + 1, history[i]);
    }
}