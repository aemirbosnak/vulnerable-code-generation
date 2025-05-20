//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LENGTH 1024 // Maximum number of characters in a command
#define MAX_ARGS 128    // Maximum number of arguments in a command

void shell_loop();
char *read_input();
char **parse_input(char *input);
int execute_command(char **args);

int main()
{
    printf("Welcome to the Unix-like Shell!\n");

    shell_loop();

    return 0;
}

// Main loop of the shell
void shell_loop()
{
    char *input;
    char **args;
    int status;

    do
    {
        printf("> ");
        input = read_input();
        args = parse_input(input);
        status = execute_command(args);

        // Free memory
        free(input);
        free(args);

    } while (status);
}

// Read user input from the command line
char *read_input()
{
    char *input = NULL;
    ssize_t buffer_size = 0;

    getline(&input, &buffer_size, stdin);

    return input;
}

// Parse user input into arguments
char **parse_input(char *input)
{
    char **args = malloc(MAX_ARGS * sizeof(char *));
    char *arg;
    int i = 0;

    arg = strtok(input, " \t\n");
    while (arg != NULL)
    {
        args[i] = arg;
        i++;

        // Check for maximum number of arguments
        if (i == MAX_ARGS)
        {
            fprintf(stderr, "Too many arguments!\n");
            exit(EXIT_FAILURE);
        }

        arg = strtok(NULL, " \t\n");
    }
    args[i] = NULL;

    return args;
}

// Execute the user command
int execute_command(char **args)
{
    pid_t pid, wpid;
    int status;

    if (args[0] == NULL)
    {
        // Empty command
        return 1;
    }

    if (strcmp(args[0], "exit") == 0)
    {
        // Exit command
        return 0;
    }

    pid = fork();
    if (pid == 0)
    {
        // Child process
        if (execvp(args[0], args) == -1)
        {
            perror("lsh");
        }
        exit(EXIT_FAILURE);
    }
    else if (pid < 0)
    {
        // Error forking
        perror("lsh");
    }
    else
    {
        // Parent process
        do
        {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}