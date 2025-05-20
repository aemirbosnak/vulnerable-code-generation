//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: high level of detail
/**
 * This is a Unix-like Shell program written in C Language.
 *
 * Authors: AI Chatbot
 * Created on: 22nd Sep, 2021
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS_COUNT 10
#define MAX_COMMANDS_COUNT 10
#define MAX_PATH_LENGTH 100

char* split_command_arguments(char* command) {
    char* argument = strtok(NULL, " ");
    if (argument != NULL && argument[0] == '$') {
        // Get the value of any environment variable used as argument
        char* env_var = getenv(argument + 1);
        if (env_var != NULL) {
            return env_var;
        } else {
            printf("%s does not exist in environment variables.\n", argument + 1);
        }
    }
    return argument;
}

int main(int argc, char** argv) {
    char command_input[MAX_COMMAND_LENGTH];
    char* commands[MAX_COMMANDS_COUNT][MAX_ARGUMENTS_COUNT];
    int commands_count = 0;

    // Infinite loop, until user enters the exit command
    while (1) {
        printf("\n$ ");

        // Read user command input
        fgets(command_input, MAX_COMMAND_LENGTH, stdin);

        // Remove newline character from command input
        command_input[strcspn(command_input, "\n")] = 0;

        // Splitting the command input by whitespace
        char* command = strtok(command_input, " ");
        int command_arguments_count = 0;
        while (command != NULL) {
            char* argument = split_command_arguments(command);
            if (argument != NULL) {
                // Allocate and copy command and arguments into separate memory location
                char* command_argument = malloc(strlen(argument) + 1);
                strcpy(command_argument, argument);
                commands[commands_count][command_arguments_count] = command_argument;
                command_arguments_count++;
            }
            command = strtok(NULL, " ");
        }

        // Check for any built-in commands
        if (strcmp(commands[commands_count][0], "cd") == 0) {
            // Change directory to specified path
            if (command_arguments_count > 1) {
                int result = chdir(commands[commands_count][1]);
                if (result != 0) {
                    printf("cd: %s: No such file or directory\n", commands[commands_count][1]);
                }
            } else {
                printf("cd: missing operand\n");
            }
        } else if (strcmp(commands[commands_count][0], "exit") == 0) {
            // Exit the shell
            printf("Goodbye!\n");
            break;
        } else {
            // Fork a new process to run the external command
            pid_t pid = fork();
            if (pid == 0) {
                // Child process

                // Build the command path by examining PATH environment variable
                char path_env[MAX_PATH_LENGTH];
                strcpy(path_env, getenv("PATH"));
                char* path = strtok(path_env, ":");
                while (path != NULL) {
                    char command_path[MAX_PATH_LENGTH];
                    strcpy(command_path, path);
                    strcat(command_path, "/");
                    strcat(command_path, commands[commands_count][0]);
                    if (access(command_path, X_OK) == 0) {
                        // Execute the external command
                        execv(command_path, commands[commands_count]);
                    }
                    path = strtok(NULL, ":");
                }

                // End the child process if external command is not found
                printf("Command not found: %s\n", commands[commands_count][0]);
                exit(EXIT_FAILURE);
            } else if (pid < 0) {
                // Error occurred while forking the process
                printf("An error occurred while forking the process.\n");
                exit(EXIT_FAILURE);
            } else {
                // Parent process

                // Wait for the child process to complete
                int status;
                do {
                    waitpid(pid, &status, WUNTRACED);
                } while (!WIFEXITED(status) && !WIFSIGNALED(status));
            }
        }

        // Freeing the allocated memory
        for (int i = 0; i < command_arguments_count; i++) {
            free(commands[commands_count][i]);
        }
        commands_count++;
    }

    return 0;
}