//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

char shell_buffer[MAX_BUFFER_SIZE];

int main()
{
    char *command;
    char **args;
    int i = 0;
    int status;

    while (1)
    {
        printf("$ ");
        command = fgets(shell_buffer, MAX_BUFFER_SIZE, stdin);

        // Remove newline character from the command
        command[strcspn(command, "\n")] = '\0';

        // Tokenize the command into arguments
        args = malloc(sizeof(char *) * (i + 1));
        args[i] = strdup(command);

        // Increment the number of arguments
        i++;

        // Execute the command
        status = fork();
        if (status == 0)
        {
            execvp(args[0], args);
            exit(1);
        }
        else if (status > 0)
        {
            wait(&status);
            printf("Exit status: %d\n", status);
        }

        // Free the memory allocated for arguments
        free(args);

        // Clear the shell buffer
        memset(shell_buffer, 0, MAX_BUFFER_SIZE);
    }

    return 0;
}