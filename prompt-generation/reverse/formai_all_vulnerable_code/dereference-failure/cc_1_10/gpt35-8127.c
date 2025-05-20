//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: statistical
/*
*  Statistical Unix-like Shell Program
*  Author: [Your Name]
*  Date: [Current Date]
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_ARGS 64

// Function to get user input
char* get_input()
{
    char *input = malloc(MAX_INPUT_LENGTH);
    fgets(input, MAX_INPUT_LENGTH, stdin);
    strtok(input, "\n");
    return input;
}

// Function to process input and execute commands
void execute(char **args)
{
    pid_t pid;
    int status;

    // Fork a new process
    pid = fork();

    if (pid < 0) {
        printf("Error: Fork Failed\n");
    }

    else if (pid == 0) {
        // Child process
        if (execvp(args[0], args) < 0) {
            printf("Error: Command not Found\n");
        }
        exit(0);
    }

    else {
        // Parent process
        waitpid(pid, &status, 0);
    }
}

// Function to parse input into separate arguments
char **parse_input(char *input)
{
    char **args = malloc(MAX_ARGS * sizeof(char*));
    char *token;
    int i = 0;

    token = strtok(input, " ");
    while (token != NULL) {
        args[i] = token;
        i++;
        token = strtok(NULL, " ");
    }

    args[i] = NULL;
    return args;
}

int main(void)
{
    char *input;
    char **args;
    int status;

    do {
        printf("Statistical Shell >>> ");
        input = get_input();
        args = parse_input(input);
        execute(args);

        free(input);
        free(args);
    } while (status);

    return 0;
}