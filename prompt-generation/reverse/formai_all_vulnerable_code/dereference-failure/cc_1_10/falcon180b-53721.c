//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 1024
#define DELIM " \t\r\n\a"

// Function to split a string into an array of strings
char **split_string(char *string) {
    int count = 0, i = 0;
    char **tokens = NULL;
    char *token;

    // Count the number of words in the string
    while (*string) {
        if (strchr(DELIM, *string)) {
            count++;
        }
        string++;
    }

    // Allocate memory for the array of strings
    tokens = (char **)malloc((count + 1) * sizeof(char *));
    if (tokens == NULL) {
        printf("Error: Failed to allocate memory\n");
        exit(1);
    }

    // Split the string into an array of strings
    i = 0;
    token = strtok(string, DELIM);
    while (token!= NULL) {
        tokens[i++] = token;
        token = strtok(NULL, DELIM);
    }
    tokens[i] = NULL;

    return tokens;
}

// Function to execute a command
void execute_command(char **tokens) {
    pid_t pid;
    int status;

    // Fork a new process to execute the command
    pid = fork();
    if (pid == -1) {
        printf("Error: Failed to fork\n");
        exit(1);
    } else if (pid == 0) {
        // Child process
        if (execvp(tokens[0], tokens) == -1) {
            printf("Error: Failed to execute command\n");
            exit(1);
        }
    } else {
        // Parent process
        waitpid(pid, &status, 0);
    }
}

// Function to handle input from the user
void handle_input(char *line) {
    char **tokens = split_string(line);
    int i;

    // Check if the input is a valid command
    for (i = 0; tokens[i]!= NULL; i++) {
        if (access(tokens[i], X_OK)!= 0) {
            printf("Error: Command not found\n");
            exit(1);
        }
    }

    // Execute the command
    execute_command(tokens);
}

// Main function
int main(void) {
    char line[MAX_LINE];

    printf("Welcome to the Basic Unix-like Shell\n");
    while (1) {
        printf("> ");
        fgets(line, MAX_LINE, stdin);
        handle_input(line);
    }

    return 0;
}