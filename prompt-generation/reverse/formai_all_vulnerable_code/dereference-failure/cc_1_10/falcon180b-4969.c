//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

// Function prototypes
char **split_command(char *command);
int execute_command(char **args);

// Main function
int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    int status;

    printf("Welcome to the post-apocalyptic shell!\n");
    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        args = split_command(input);
        status = execute_command(args);

        if (status == 1) {
            printf("Child process terminated abnormally.\n");
        } else if (status == 0) {
            printf("Child process terminated normally.\n");
        }
    }

    return 0;
}

// Function to split command into arguments
char **split_command(char *command) {
    int argc = 0;
    char **args = NULL;
    char *token;

    token = strtok(command, DELIM);
    while (token!= NULL) {
        argc++;
        args = realloc(args, sizeof(char *) * argc);
        args[argc - 1] = token;
        token = strtok(NULL, DELIM);
    }
    args[argc] = NULL;

    return args;
}

// Function to execute command
int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        fprintf(stderr, "No command specified.\n");
        return 1;
    }

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        execvp(args[0], args);
        perror("execvp");
        exit(1);
    } else {
        waitpid(pid, &status, 0);
        return status;
    }
}