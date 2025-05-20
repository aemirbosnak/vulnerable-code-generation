//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 1024   /* Maximum input line size */
#define MAX_ARGS 100    /* Maximum number of arguments */

/* Function Declarations */
void print_prompt();
char *read_input();
char **parse_input(char *input);
void execute_command(char **args);
void handle_bg_command(char **args);
void handle_fg_command(int pid);

int main() {
    char *input;
    char **args;
    
    while (1) {
        print_prompt();
        input = read_input();
        args = parse_input(input);
        
        if (args[0] == NULL) {
            free(input);
            free(args);
            continue; // Empty command
        }

        if (strcmp(args[0], "exit") == 0) {
            free(input);
            free(args);
            break; // Exit the shell
        }

        // Handle background tasks
        if (args[0][strlen(args[0]) - 1] == '&') {
            args[0][strlen(args[0]) - 1] = '\0'; // Remove the '&'
            handle_bg_command(args);
        } else {
            execute_command(args);
        }

        free(input);
        free(args);
    }
    
    return 0;
}

void print_prompt() {
    printf("my_shell> ");
}

char *read_input() {
    char *input = (char *)malloc(MAX_LINE * sizeof(char));
    if (!input) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    if (fgets(input, MAX_LINE, stdin) == NULL) {
        free(input);
        perror("fgets failed");
        exit(EXIT_FAILURE);
    }
    return input;
}

char **parse_input(char *input) {
    char **args = (char **)malloc(MAX_ARGS * sizeof(char *));
    if (!args) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    
    char *arg = strtok(input, " \n");
    int index = 0;

    while (arg != NULL && index < MAX_ARGS - 1) {
        args[index++] = arg;
        arg = strtok(NULL, " \n");
    }
    args[index] = NULL; // Null-terminate the array
    return args;
}

void execute_command(char **args) {
    pid_t pid = fork(); // Create a child process
    if (pid < 0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("exec failed");
            exit(EXIT_FAILURE);
        }
    } else {
        // Parent process
        wait(NULL); // Wait for the child to complete
    }
}

void handle_bg_command(char **args) {
    pid_t pid = fork(); // Create a child process
    if (pid < 0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("exec failed");
            exit(EXIT_FAILURE);
        }
    } else {
        // Parent process
        printf("Started background job with PID %d\n", pid);
    }
}