//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

char buffer[MAX_BUFFER_SIZE];

int main()
{
    char *command;
    char **args;
    int argc;

    printf("Shell prompt: $ ");

    // Read a command from the user
    command = fgets(buffer, MAX_BUFFER_SIZE, stdin);

    // Remove the newline character from the command
    command[strcspn(command, "\n")] = '\0';

    // Tokenize the command into arguments
    args = malloc(MAX_BUFFER_SIZE * sizeof(char *));
    argc = 0;

    while ((args[argc] = strtok(NULL, " ")) != NULL)
    {
        argc++;
    }

    // Execute the command
    switch (argc)
    {
        case 0:
            printf("Error: Invalid command.\n");
            break;
        case 1:
            printf("Error: Missing arguments.\n");
            break;
        default:
            // Execute the command with its arguments
            execvp(args[0], args);
            break;
    }

    // Free the memory allocated for arguments
    free(args);

    return 0;
}