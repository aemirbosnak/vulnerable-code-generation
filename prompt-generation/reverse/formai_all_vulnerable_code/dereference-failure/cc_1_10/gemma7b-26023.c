//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 256

char shell_prompt[] = "$ ";

int main()
{
    char cmd[MAX_CMD_LEN];
    char **args;
    int i;

    // Loop until the user enters "exit"
    while (1)
    {
        // Print the shell prompt
        printf("%s", shell_prompt);

        // Get the user input
        fgets(cmd, MAX_CMD_LEN, stdin);

        // Remove the newline character from the end of the command
        cmd[strcspn(cmd, "\n")] = '\0';

        // Tokenize the command into arguments
        args = malloc(MAX_CMD_LEN * sizeof(char *));
        i = 0;
        args[i++] = strtok(cmd, " ");
        while (args[i - 1] != NULL)
        {
            args[i++] = strtok(NULL, " ");
        }

        // Execute the command
        if (strcmp(args[0], "exit") == 0)
        {
            exit(0);
        }
        else
        {
            // Handle other commands here
            printf("Command not found.\n");
        }

        // Free the memory allocated for the arguments
        free(args);
    }

    return 0;
}