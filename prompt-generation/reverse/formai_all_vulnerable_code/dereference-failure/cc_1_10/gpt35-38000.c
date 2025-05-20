//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100 // Maximum command length supported

int execute(char** arguments, int background) {
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        if (execvp(arguments[0], arguments) == -1) {
            perror("Error executing command");
            exit(EXIT_FAILURE);
        }
    } else if (pid < 0) {
        // Forking failed
        perror("Error forking");
    } else {
        // Parent process
        if (!background) {
            // Wait for child to finish if not running in the background
            int status;
            waitpid(pid, &status, 0);
            return status;
        }
    }
    return 0;
}

char** split_command(char* command) {
    char** arguments = malloc(MAX_COMMAND_LENGTH * sizeof(char*));
    char* token = strtok(command, " ");
    int i = 0;
    while (token != NULL) {
        arguments[i] = strdup(token);
        token = strtok(NULL, " ");
        i++;
    }
    arguments[i] = NULL;
    return arguments;
}

int main(void) {
    char command[MAX_COMMAND_LENGTH];
    int status = 1;

    while (status) {
        printf("$ ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        // Remove newline character from command string
        command[strcspn(command, "\n")] = 0;

        // Check if running in the background
        int background = 0;
        if (command[strlen(command)-1] == '&') {
            background = 1;
            command[strlen(command)-1] = '\0';
        }

        // Split command into arguments
        char** arguments = split_command(command);

        if (strcmp(arguments[0], "exit") == 0) {
            // Exit shell if command is "exit"
            free(arguments);
            return 0;
        }

        // Execute command
        status = execute(arguments, background);

        // Free allocated memory for arguments
        free(arguments);
    }
    return 0;
}