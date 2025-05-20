//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 255

int main()
{
    char cmd[MAX_CMD_LEN];
    char **args;
    int i, status;

    // Loop until the user enters "exit"
    while (1)
    {
        printf("$ ");
        fgets(cmd, MAX_CMD_LEN, stdin);

        // Tokenize the command into arguments
        args = NULL;
        i = 0;
        args = malloc((MAX_CMD_LEN + 1) * sizeof(char *));
        while ((cmd[i] != '\0') && (cmd[i] != '\n'))
        {
            args[i] = malloc(MAX_CMD_LEN * sizeof(char));
            strcpy(args[i], cmd + i);
            i++;
        }
        args[i] = NULL;

        // Execute the command
        status = system(args[0]);

        // Free memory
        for (i = 0; args[i] != NULL; i++)
        {
            free(args[i]);
        }
        free(args);

        // Check if the command was successful
        if (status == 0)
        {
            printf("Command successful.\n");
        }
        else
        {
            printf("Error executing command.\n");
        }

        // Check if the user wants to exit
        if (strcmp(cmd, "exit") == 0)
        {
            break;
        }
    }

    return 0;
}