//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_LEN 1024
#define MAX_ARGS 100

void print_welcome() {
    printf("Welcome to the Grateful Shell!\n");
    printf("Your friendly command-line companion.\n\n");
}

void execute_command(char *command) {
    char *args[MAX_ARGS];
    char *token = strtok(command, " \n");
    int i = 0;

    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " \n");
    }
    args[i] = NULL;

    if (strcmp(args[0], "exit") == 0) {
        printf("Thank you for using the Grateful Shell. Goodbye!\n");
        exit(0);
    } else if (strcmp(args[0], "cd") == 0) {
        if (i < 2) {
            fprintf(stderr, "cd: missing argument\n");
        } else if (chdir(args[1]) != 0) {
            perror("cd failed");
        }
    } else {
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork failed");
        } else if (pid == 0) {
            // Child process
            if (execvp(args[0], args) == -1) {
                perror("Command execution failed");
            }
            exit(EXIT_FAILURE);
        } else {
            // Parent process
            wait(NULL);
        }
    }
}

void read_and_execute_command() {
    char command[MAX_CMD_LEN];

    while (1) {
        printf("grateful-shell> ");
        if (fgets(command, sizeof(command), stdin) == NULL) {
            perror("fgets failed");
            continue;
        }
        execute_command(command);
    }
}

int main() {
    print_welcome();
    read_and_execute_command();
    return 0;
}