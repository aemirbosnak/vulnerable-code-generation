//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX_CMD_LEN 1024

char shell_prompt[] = "$ ";

void execute_command(char *command)
{
    char **args = NULL;
    int i = 0;

    // Tokenize the command
    args = malloc(MAX_CMD_LEN * sizeof(char *));
    args[0] = command;

    // Count the number of arguments
    while (args[i] = strchr(command, ' ') != NULL)
    {
        i++;
        command = strchr(command, ' ') + 1;
    }

    // Execute the command
    if (args[0] != NULL)
    {
        execvp(args[0], args);
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

        // Get the user input
        fgets(command, MAX_CMD_LEN, stdin);

        // Execute the command
        execute_command(command);
    }

    return 0;
}