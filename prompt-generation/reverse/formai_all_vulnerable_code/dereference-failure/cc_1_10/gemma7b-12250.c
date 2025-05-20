//Gemma-7B DATASET v1.0 Category: System administration ; Style: lively
#include <stdio.h>
#include <string.h>

#define MAX_CMD_LEN 256

int main()
{
    char cmd[MAX_CMD_LEN];
    char **argv = NULL;
    int argc = 0;
    int i = 0;

    printf("Welcome to the C System Admin Shell!\n");

    // Loop until the user enters "exit"
    while (strcmp(cmd, "exit") != 0)
    {
        printf("Enter a command: ");
        scanf("%s", cmd);

        // Parse the command line arguments
        argv = malloc(MAX_CMD_LEN * sizeof(char *));
        argc = 0;
        for (i = 0; cmd[i] != '\0'; i++)
        {
            if (cmd[i] == ' ')
            {
                argv[argc++] = malloc(MAX_CMD_LEN * sizeof(char));
                argv[argc - 1] = strndup(&cmd[i + 1], MAX_CMD_LEN - i - 1);
            }
        }

        // Execute the command
        if (argc > 0)
        {
            execvp(argv[0], argv);
        }

        // Free the memory allocated for argv
        for (i = 0; argv[i] != NULL; i++)
        {
            free(argv[i]);
        }
        free(argv);
    }

    printf("Exiting...\n");

    return 0;
}