//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    char *command = NULL;
    int command_length = 0;
    int i = 0;

    printf("Enter a command: ");

    // Get the user input
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    // Allocate memory for the command
    command = malloc(strlen(buffer) + 1);

    // Copy the user input into the command buffer
    strcpy(command, buffer);

    // Calculate the length of the command
    command_length = strlen(command);

    // Loop over the command to find the syntax
    for (i = 0; i < command_length; i++)
    {
        // Check if the character is a command keyword
        if (command[i] == 'c' || command[i] == 'r' || command[i] == 'a' || command[i] == 'h')
        {
            // Extract the command keyword
            char keyword = command[i];

            // Check if the command has a parameter
            if (command[i + 1] != '\0')
            {
                // Extract the parameter
                char parameter = command[i + 1];

                // Print the command and parameter
                printf("Command: %c, Parameter: %c\n", keyword, parameter);
            }
            else
            {
                // Print the command
                printf("Command: %c\n", keyword);
            }
        }
    }

    // Free the memory allocated for the command
    free(command);

    return 0;
}