//Gemma-7B DATASET v1.0 Category: System administration ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 256

int main()
{
    char cmd[MAX_CMD_LEN];
    char **cmds = NULL;
    int i = 0;

    printf("Welcome to the C System Administration Interface.\n");

    // Allocate memory for commands
    cmds = malloc(sizeof(char *) * 10);
    if (cmds == NULL)
    {
        printf("Error allocating memory.\n");
        return 1;
    }

    // Loop until the user enters "exit"
    while (strcmp(cmd, "exit") != 0)
    {
        // Get the user command
        printf("Enter a command: ");
        fgets(cmd, MAX_CMD_LEN, stdin);

        // Add the command to the list
        cmds[i] = strdup(cmd);
        i++;

        // Check if the command is valid
        if (valid_command(cmds[i - 1]) == 0)
        {
            printf("Error: invalid command.\n");
        }
    }

    // Free the allocated memory
    free(cmds);

    return 0;
}

int valid_command(char *cmd)
{
    // List of valid commands
    char *valid_commands[] = {"reboot", "shutdown", "update", "useradd", "userdel"};

    // Check if the command is in the list
    for (int i = 0; i < 5; i++)
    {
        if (strcmp(cmd, valid_commands[i]) == 0)
        {
            return 1;
        }
    }

    return 0;
}