//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1000 // Maximum length of the command
#define MAX_NUMBER_OF_ARGUMENTS 100 // Maximum number of arguments in the command
#define MAX_PATH_LENGTH 500 // Maximum length of the path

int main() {

    char command[MAX_COMMAND_LENGTH];
    char *arguments[MAX_NUMBER_OF_ARGUMENTS];
    char *path = getenv("PATH");
    char path_list[MAX_PATH_LENGTH];
    char *path_ptr;
    int status;

    // Print a welcome message
    printf("\nWelcome to the Energized Unix Shell!\n");

    while (1) {
        // Print a prompt
        printf("\nEnergized-Shell> ");

        // Read the command
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        // Remove the new line character from the end of the command
        command[strcspn(command, "\n")] = 0;

        // Parse the command into the arguments
        char *token;
        int i = 0;
        token = strtok(command, " ");
        while (token != NULL) {
            arguments[i++] = token;
            token = strtok(NULL, " ");
        }
        arguments[i] = NULL;

        // Check if the user wants to exit the shell
        if (strcmp(arguments[0], "exit") == 0) {
            printf("Goodbye!\n");
            break;
        }

        // Execute the command
        pid_t pid = fork();
        if (pid == 0) {
            // Child process
            // Search for the command in the PATH
            strcpy(path_list, path);
            path_ptr = strtok(path_list, ":");
            while (path_ptr != NULL) {
                char command_path[MAX_PATH_LENGTH];
                strcpy(command_path, path_ptr);
                strcat(command_path, "/");
                strcat(command_path, arguments[0]);
                execv(command_path, arguments);
                path_ptr = strtok(NULL, ":");
            }
            // Could not find the command in the PATH
            printf("Command not found\n");
            exit(EXIT_FAILURE);
        } else if (pid < 0) {
            // Error forking
            printf("Fork failed\n");
        } else {
            // Parent process
            // Wait for the child process to finish
            wait(&status);
        }
    }

    return 0;
}