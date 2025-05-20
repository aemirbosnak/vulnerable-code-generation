//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LEN 1024
#define MAX_NUM_ARGS 100

// Function prototypes
void display_prompt();
char* read_command();
char** parse_command(char* command);
void execute_command(char** args);
void free_arguments(char** args);

int main() {
    char* command;
    char** args;

    while (1) {
        display_prompt();
        command = read_command();
        if (command == NULL) {
            perror("Failed to read command");
            continue;
        }

        args = parse_command(command);
        if (args == NULL) {
            fprintf(stderr, "Failed to parse command\n");
            free(command);
            continue;
        }

        if (args[0] == NULL) {
            free(command);
            free_arguments(args);
            continue; // Blank command
        }

        if (strcmp(args[0], "exit") == 0) {
            free(command);
            free_arguments(args);
            break; // Exit shell
        }

        execute_command(args);

        free(command);
        free_arguments(args);
    }

    return 0;
}

void display_prompt() {
    printf("mysh> ");
}

char* read_command() {
    char* command = malloc(MAX_COMMAND_LEN);
    if (fgets(command, MAX_COMMAND_LEN, stdin) == NULL) {
        free(command);
        return NULL; // Failed to read command
    }
    command[strcspn(command, "\n")] = '\0'; // Remove newline character
    return command;
}

char** parse_command(char* command) {
    char** args = malloc(MAX_NUM_ARGS * sizeof(char*));
    if (args == NULL) {
        return NULL; // Failed to allocate memory for arguments
    }

    int index = 0;
    char* token = strtok(command, " ");
    while (token != NULL && index < MAX_NUM_ARGS - 1) {
        args[index++] = token;
        token = strtok(NULL, " ");
    }
    args[index] = NULL; // Null-terminate the arguments array

    return args;
}

void execute_command(char** args) {
    pid_t pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        return;
    } else if (pid == 0) {
        // Child process
        if (execvp(args[0], args) < 0) {
            perror("Exec failed");
            exit(EXIT_FAILURE);
        }
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0); // Wait for child process to finish
    }
}

void free_arguments(char** args) {
    free(args); // Free arguments array
}