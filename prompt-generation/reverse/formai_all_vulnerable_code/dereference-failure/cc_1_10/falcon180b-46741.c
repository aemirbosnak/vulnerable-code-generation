//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"
#define MAX_ARGUMENTS 100
#define PIPE_READ 0
#define PIPE_WRITE 1

// Function to split a string into an array of strings
char** split(char* str, char delimiter) {
    int count = 0;
    char* token = strtok(str, delimiter);
    char** result = malloc(sizeof(char*) * (MAX_ARGUMENTS + 1));
    result[count++] = token;

    while (token!= NULL) {
        result[count++] = token;
        token = strtok(NULL, delimiter);
    }

    result[count] = NULL;
    return result;
}

// Function to execute a command
void execute_command(char** arguments) {
    pid_t pid;
    int status;

    if (arguments[0] == NULL) {
        return;
    }

    if (strcmp(arguments[0], "cd") == 0) {
        if (chdir(arguments[1])!= 0) {
            perror("Error");
        }
        return;
    }

    pid = fork();

    if (pid == 0) {
        if (execvp(arguments[0], arguments) == -1) {
            perror("Error");
            exit(1);
        }
        exit(0);
    } else if (pid < 0) {
        perror("Error");
        exit(1);
    } else {
        waitpid(pid, &status, 0);
    }
}

// Function to handle input
void handle_input(char* input) {
    char** arguments = split(input, DELIM);
    execute_command(arguments);
}

// Main function
int main() {
    char input[MAX_COMMAND_LENGTH];

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        handle_input(input);
    }

    return 0;
}