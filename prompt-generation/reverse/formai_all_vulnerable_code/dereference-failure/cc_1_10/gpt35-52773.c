//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_COMMANDS 10

int execute(char *command) {
    // Splitting command string into words
    char *token = strtok(command, " ");
    char *args[MAX_COMMANDS];
    int argc = 0;
    while (token != NULL) {
        args[argc++] = token;
        token = strtok(NULL, " ");
    }
    args[argc] = NULL;

    // Executing the command
    pid_t pid = fork();
    if (pid == -1) {
        printf("Failed to fork!\n");
    } else if (pid == 0) {
        execvp(args[0], args);
        printf("Failed to execute command '%s'\n", args[0]);
        exit(EXIT_FAILURE);
    } else {
        wait(NULL);
    }
}

int run(char *commands[MAX_COMMANDS], int count) {
    if (count == 1) {
        return execute(commands[0]);
    } else {
        // Forking a child process to run the last command in the list
        pid_t pid = fork();
        if (pid == -1) {
            printf("Failed to fork!\n");
            return 0;
        } else if (pid == 0) {
            execute(commands[count - 1]);
            exit(EXIT_SUCCESS);
        } else {
            // Recursively calling run with the remaining commands
            commands[count - 1] = NULL;
            run(commands, count - 1);

            // Waiting for the child process to finish executing
            waitpid(pid, NULL, 0);
        }
    }
    return 1;
}

int main() {
    char command[MAX_COMMAND_LENGTH];
    char *commands[MAX_COMMANDS];
    int count = 0;

    printf("Enter commands separated by ';':\n");
    fgets(command, MAX_COMMAND_LENGTH, stdin);
    command[strcspn(command, "\n")] = 0; // Removing trailing new line

    // Splitting input string into individual commands
    char *token = strtok(command, ";");
    while (token != NULL) {
        commands[count++] = token;
        token = strtok(NULL, ";");
    }

    // Running the commands recursively
    if (run(commands, count)) {
        printf("All commands completed successfully!\n");
    } else {
        printf("Some commands failed to execute!\n");
    }

    return 0;
}