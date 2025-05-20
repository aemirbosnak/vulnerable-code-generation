//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARG_SIZE 100
#define MAX_HISTORY 10

// Function to execute shell commands
void execute_command(char **args) {
    pid_t pid = fork();
    
    if (pid < 0) {
        perror("Fork failed");
        return;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("Error executing command");
        }
        exit(EXIT_FAILURE);
    } else {
        wait(NULL);
    }
}

// Function to read a line from input
char *read_line() {
    char *line = malloc(MAX_INPUT_SIZE);
    if (fgets(line, MAX_INPUT_SIZE, stdin) == NULL) {
        perror("Error reading command");
        exit(EXIT_FAILURE);
    }
    return line;
}

// Function to split command into arguments
char **split_line(char *line) {
    int bufsize = MAX_ARG_SIZE;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token;
    int position = 0;

    token = strtok(line, " \n");
    while (token != NULL) {
        tokens[position++] = token;
        if (position >= bufsize) {
            bufsize += MAX_ARG_SIZE;
            tokens = realloc(tokens, bufsize * sizeof(char*));
            if (!tokens) {
                perror("Allocation error");
                exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL, " \n");
    }
    tokens[position] = NULL;
    return tokens;
}

// Function to add command to history
void add_to_history(char *history[], char *command, int *history_count) {
    if (*history_count < MAX_HISTORY) {
        history[*history_count] = strdup(command);
        (*history_count)++;
    } else {
        free(history[0]);
        for (int i = 1; i < MAX_HISTORY; i++) {
            history[i - 1] = history[i];
        }
        history[MAX_HISTORY - 1] = strdup(command);
    }
}

// Function to print command history
void print_history(char *history[], int history_count) {
    for (int i = 0; i < history_count; i++) {
        printf("%d  %s\n", i + 1, history[i]);
    }
}

int main() {
    char *line;
    char **args;
    char *history[MAX_HISTORY];
    int history_count = 0;
    
    printf("Welcome to MyShell! Type 'exit' to quit.\n");

    while (1) {
        printf("myshell> ");
        line = read_line();

        // Exit command
        if (strcmp(line, "exit\n") == 0) {
            free(line);
            break;
        }
        
        // Add command to history
        add_to_history(history, line, &history_count);

        // Handle history command
        if (strcmp(line, "history\n") == 0) {
            print_history(history, history_count);
            free(line);
            continue;
        }

        args = split_line(line);
        execute_command(args);

        free(args);
        free(line);
    }

    // Freeing up allocated memory for history
    for (int i = 0; i < history_count; i++) {
        free(history[i]);
    }

    printf("Exiting MyShell. Goodbye!\n");
    return 0;
}