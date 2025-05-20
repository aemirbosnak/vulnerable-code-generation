//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 1024

char shell_prompt[] = "$ ";

void execute_command(char *command)
{
    char **args = NULL;
    char *arg = NULL;
    int i = 0;

    // Tokenize the command
    args = malloc(MAX_CMD_LEN * sizeof(char *));
    arg = strtok(command, " ");

    // Loop over the arguments
    while (arg)
    {
        args[i++] = arg;
        arg = strtok(NULL, " ");
    }

    // Null terminate the arguments
    args[i] = NULL;

    // Execute the command
    system(args[0]);

    // Free the memory allocated for the arguments
    free(args);
}

int main()
{
    char command[MAX_CMD_LEN];

    // Loop until the user enters "exit"
    while (1)
    {
        // Print the shell prompt
        printf("%s", shell_prompt);

        // Get the user's command
        fgets(command, MAX_CMD_LEN, stdin);

        // Remove the newline character from the command
        command[strcspn(command, "\n")] = '\0';

        // Execute the command
        if (strcmp(command, "exit") == 0)
        {
            exit(0);
        }
        else
        {
            execute_command(command);
        }
    }

    return 0;
}