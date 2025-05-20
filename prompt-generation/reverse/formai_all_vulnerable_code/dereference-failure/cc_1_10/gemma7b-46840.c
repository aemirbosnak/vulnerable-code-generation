//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

char shell_buffer[MAX_BUFFER_SIZE];

void parse_shell_command(char **argv)
{
    char *command = strtok(shell_buffer, " ");
    int i = 0;

    while (command)
    {
        argv[i++] = command;
        command = strtok(NULL, " ");
    }

    argv[i] = NULL;
}

int main()
{
    char prompt[] = "Shell $ ";

    while (1)
    {
        // Print prompt
        printf("%s", prompt);

        // Get user input
        fgets(shell_buffer, MAX_BUFFER_SIZE, stdin);

        // Parse command
        char **argv = malloc(MAX_BUFFER_SIZE * sizeof(char *));
        parse_shell_command(argv);

        // Execute command
        if (argv[0] != NULL)
        {
            execvp(argv[0], argv);
        }

        // Free memory
        free(argv);
    }

    return 0;
}