//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_LEN 256

int main()
{
    char cmd[MAX_CMD_LEN];
    char **args;
    int i;

    // Loop until the user enters "exit"
    while (1)
    {
        // Print the shell prompt
        printf("$ ");

        // Get the user input
        fgets(cmd, MAX_CMD_LEN, stdin);

        // Remove the newline character from the command
        cmd[strcspn(cmd, "\n")] = '\0';

        // Split the command into arguments
        args = malloc(MAX_CMD_LEN * sizeof(char *));
        i = 0;
        args[i++] = strtok(cmd, " ");
        while (args[i - 1] != NULL)
        {
            args[i++] = strtok(NULL, " ");
        }

        // Execute the command
        if (fork() == 0)
        {
            execvp(args[0], args);
            exit(1);
        }

        // Wait for the child process to complete
        wait(NULL);

        // Free the memory allocated for the arguments
        free(args);
    }

    return 0;
}