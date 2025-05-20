//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

// Function to split a string into an array of strings based on delimiter
char **split_string(char *str) {
    int count = 0;
    char **tokens = NULL;
    char *token = strtok(str, DELIM);

    while (token!= NULL) {
        count++;
        tokens = realloc(tokens, sizeof(char *) * count);
        tokens[count - 1] = strdup(token);
        token = strtok(NULL, DELIM);
    }

    tokens[count - 1] = NULL;
    return tokens;
}

// Function to execute a command and wait for it to finish
void execute_command(char **args) {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("Error executing command");
            exit(1);
        }
    } else if (pid < 0) {
        // Error forking
        perror("Error forking");
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
    }
}

// Function to handle a single command
void handle_command(char **args) {
    if (args[0] == NULL) {
        return;
    }

    if (strcmp(args[0], "exit") == 0) {
        exit(0);
    } else if (strcmp(args[0], "cd") == 0) {
        if (args[1] == NULL) {
            fprintf(stderr, "Usage: cd [directory]\n");
        } else {
            if (chdir(args[1]) == -1) {
                perror("Error changing directory");
            }
        }
    } else {
        execute_command(args);
    }
}

// Function to read a line of input from the user
char *read_line(void) {
    char *line = NULL;
    ssize_t bufsize = 0;
    getline(&line, &bufsize, stdin);
    return line;
}

// Main function
int main(void) {
    char *line;
    char **args;

    while (1) {
        printf("> ");
        line = read_line();
        args = split_string(line);

        if (args[0] == NULL) {
            continue;
        }

        handle_command(args);
        free(line);
        for (int i = 0; args[i]!= NULL; i++) {
            free(args[i]);
        }
        free(args);
    }

    return 0;
}