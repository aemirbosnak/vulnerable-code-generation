//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 1024

char shell_prompt[] = "$ ";

void parse_command(char *command)
{
    char **args = NULL;
    int num_args = 0;
    char *arg = NULL;

    // Tokenize the command into arguments
    arg = strtok(command, " ");
    while (arg)
    {
        args = realloc(args, (num_args + 1) * sizeof(char *));
        args[num_args++] = arg;
        arg = strtok(NULL, " ");
    }

    // Execute the command
    if (num_args > 0)
    {
        args[num_args] = NULL;
        execvp(args[0], args);
    }
    else
    {
        printf("Error: command not found.\n");
    }

    // Free the allocated memory
    free(args);
}

int main()
{
    char command[MAX_CMD_LEN];

    // Enter the shell loop
    while (1)
    {
        // Print the shell prompt
        printf(shell_prompt);

        // Get the command from the user
        fgets(command, MAX_CMD_LEN, stdin);

        // Parse the command
        parse_command(command);
    }

    return 0;
}