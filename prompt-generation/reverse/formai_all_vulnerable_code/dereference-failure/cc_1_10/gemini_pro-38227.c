//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Custom data structures and definitions
typedef struct {
    char *command;
    char **args;
    int argc;
} Command;

// Custom functions
void print_intro() {
    printf("Welcome to the introspective shell!\n");
    printf("This shell allows you to inspect the commands you enter before executing them.\n");
    printf("Type 'help' for a list of commands.\n");
}

// Inspecting commands
void inspect(Command *command) {
    printf("Command: %s\n", command->command);
    printf("Arguments:\n");
    for (int i = 0; i < command->argc; i++) {
        printf(" - %s\n", command->args[i]);
    }
}

// Parsing commands
Command *parse(char *line) {
    Command *command = malloc(sizeof(Command));

    // Split the line into command and arguments
    char *command_str = strtok(line, " ");
    command->command = malloc(strlen(command_str) + 1);
    strcpy(command->command, command_str);

    // Allocate memory for the arguments
    int argc = 1;
    char **args = malloc(argc * sizeof(char *));
    args[0] = command_str;

    // Process the remaining arguments
    char *arg_str;
    while ((arg_str = strtok(NULL, " ")) != NULL) {
        argc++;
        args = realloc(args, argc * sizeof(char *));
        args[argc - 1] = arg_str;
    }

    // Update the command struct
    command->args = args;
    command->argc = argc;

    return command;
}

// Executing commands
int execute(Command *command) {
    pid_t pid = fork();
    int status;

    if (pid == 0) {
        // Child process
        execvp(command->command, command->args);
        exit(1);
    } else if (pid > 0) {
        // Parent process
        waitpid(pid, &status, 0);
    } else {
        // Error
        perror("fork");
        return 1;
    }

    return 0;
}

// Freeing memory
void free_command(Command *command) {
    free(command->command);
    for (int i = 0; i < command->argc; i++) {
        free(command->args[i]);
    }
    free(command->args);
    free(command);
}

// Main loop
int main() {
    // Print the welcome message
    print_intro();

    // Read from standard input
    char line[1024];
    while (1) {
        printf("> ");
        fgets(line, sizeof(line), stdin);

        // Remove the newline character
        line[strcspn(line, "\n")] = 0;

        // Exit the shell if the user enters 'exit'
        if (strcmp(line, "exit") == 0) {
            break;
        }

        // Parse the command
        Command *command = parse(line);

        // Inspect the command
        inspect(command);

        // Execute the command
        if (execute(command) != 0) {
            printf("Error executing command.\n");
        }

        // Free the memory allocated for the command
        free_command(command);
    }

    return 0;
}