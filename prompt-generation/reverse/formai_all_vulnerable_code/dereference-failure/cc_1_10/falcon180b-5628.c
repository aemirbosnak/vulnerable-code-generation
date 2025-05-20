//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

// Function declarations
char **split_string(char *string);
pid_t launch_shell(char **args);
void execute_command(char **args);

// Main function
int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    pid_t pid;

    printf("Welcome to the Funky Shell!\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        args = split_string(input);

        if (args[0] == NULL)
            continue;

        if (strcmp(args[0], "exit") == 0) {
            printf("Exiting...\n");
            break;
        } else {
            pid = launch_shell(args);
            if (pid == -1) {
                printf("Error: Failed to launch shell.\n");
            }
        }
    }

    return 0;
}

// Function to split a string into an array of strings using delimiter
char **split_string(char *string) {
    int count = 0;
    char **tokens = NULL;
    char *token = strtok(string, DELIM);

    while (token!= NULL) {
        count++;
        tokens = realloc(tokens, sizeof(char *) * count);
        tokens[count - 1] = strdup(token);
        token = strtok(NULL, DELIM);
    }

    tokens[count - 1] = NULL;
    return tokens;
}

// Function to launch a shell and execute commands
pid_t launch_shell(char **args) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("Error");
            exit(EXIT_FAILURE);
        }
    } else if (pid < 0) {
        // Error forking
        perror("Error");
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        waitpid(pid, &status, 0);
    }

    return pid;
}

// Function to execute commands in the shell
void execute_command(char **args) {
    int i;

    for (i = 0; args[i]!= NULL; i++) {
        printf("%s ", args[i]);
    }
    printf("\n");
}