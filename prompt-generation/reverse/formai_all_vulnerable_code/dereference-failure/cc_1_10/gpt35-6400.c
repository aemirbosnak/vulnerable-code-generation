//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 64

char* read_command() {
    char* command = (char*) malloc(sizeof(char) * MAX_COMMAND_LENGTH);

    printf(">>> ");
    fgets(command, MAX_COMMAND_LENGTH, stdin);

    command[strcspn(command, "\n")] = '\0'; // Remove newline character

    return command;
}

char** split_command(char* command) {
    char** arguments = (char**) malloc(sizeof(char*) * MAX_ARGUMENTS);

    char* argument = strtok(command, " ");
    int i = 0;

    while (argument != NULL) {
        arguments[i] = argument;
        argument = strtok(NULL, " ");
        i++;
    }

    arguments[i] = NULL; // Set final argument to NULL for execvp

    return arguments;
}

int execute_command(char** arguments) {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        return -1;
    } else if (pid == 0) { // Child process
        if (execvp(arguments[0], arguments) == -1) {
            perror("execvp");
            return -1;
        }
    } else { // Parent process
        int status;
        waitpid(pid, &status, 0); // Wait for child process to complete

        if (WIFEXITED(status) && WEXITSTATUS(status) != 0) {
            printf("Command failed with exit code %d\n", WEXITSTATUS(status));
            return -1;
        }
    }

    return 0;
}

int main() {
    while (1) {
        char* command = read_command();

        if (strcmp(command, "exit") == 0) { // Exit shell
            free(command);
            printf("Goodbye!\n");
            break;
        }

        char** arguments = split_command(command);

        if (arguments[0] == NULL) { // Empty command
            free(command);
            free(arguments);
            continue;
        }

        if (execute_command(arguments) == -1) { // Failed to execute command
            free(command);
            free(arguments);
            continue;
        }

        free(command);
        free(arguments);
    }

    return 0;
}