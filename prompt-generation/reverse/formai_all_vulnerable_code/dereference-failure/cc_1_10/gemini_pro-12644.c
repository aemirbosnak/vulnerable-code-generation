//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_ARGS 10
#define MAX_LINE_LENGTH 1024

// Function to split a string into an array of strings
char **split_string(char *str, char *delim)
{
    char **result = malloc(sizeof(char *) * MAX_ARGS);
    int i = 0;
    char *token = strtok(str, delim);
    while (token != NULL)
    {
        result[i] = token;
        i++;
        token = strtok(NULL, delim);
    }
    result[i] = NULL;
    return result;
}

// Function to execute a command
int execute_command(char **args)
{
    pid_t pid = fork();
    if (pid == 0)
    {
        if (execvp(args[0], args) == -1)
        {
            perror("Error executing command");
            exit(1);
        }
    }
    else if (pid > 0)
    {
        waitpid(pid, NULL, 0);
    }
    else
    {
        perror("Error creating child process");
        return 1;
    }
    return 0;
}

// Main function
int main()
{
    char line[MAX_LINE_LENGTH];
    while (1)
    {
        printf("enter command: ");
        fgets(line, MAX_LINE_LENGTH, stdin);
        char **args = split_string(line, " ");
        if (strcmp(args[0], "exit") == 0)
        {
            break;
        }
        else
        {
            execute_command(args);
        }
    }
    return 0;
}