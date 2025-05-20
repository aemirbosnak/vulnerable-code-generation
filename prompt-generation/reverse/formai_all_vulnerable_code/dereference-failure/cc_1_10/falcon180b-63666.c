//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"
#define MAX_ARGUMENTS 100

// Function to split the input string into an array of arguments
char** split_string(char* input) {
    char** args = malloc(MAX_ARGUMENTS * sizeof(char*));
    int count = 0;
    char* token = strtok(input, DELIM);

    while (token!= NULL) {
        args[count++] = token;
        if (count >= MAX_ARGUMENTS) {
            printf("Error: Too many arguments.\n");
            exit(1);
        }
        token = strtok(NULL, DELIM);
    }
    args[count] = NULL;

    return args;
}

// Function to execute a command and return its exit status
int execute_command(char** args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        return 1;
    }

    pid = fork();

    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("Error");
            exit(1);
        }
    } else if (pid < 0) {
        // Error forking
        perror("Error");
        exit(1);
    } else {
        // Parent process
        waitpid(pid, &status, 0);
        return WEXITSTATUS(status);
    }
}

// Main function to read commands from standard input and execute them
int main() {
    char input[MAX_COMMAND_LENGTH];
    char** args;

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        args = split_string(input);
        if (args[0] == NULL) {
            continue;
        }

        int status = execute_command(args);

        if (WIFEXITED(status)) {
            printf("Exit status: %d\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("Killed by signal %d\n", WTERMSIG(status));
        } else {
            printf("Unknown exit status\n");
        }
    }

    return 0;
}