//Gemma-7B DATASET v1.0 Category: System administration ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 255

int main()
{
    char cmd[MAX_CMD_LEN] = "";
    char **cmds = NULL;
    int cmd_num = 0;

    // Allocates memory for commands
    cmds = malloc(sizeof(char *) * 10);

    // Infinite loop to get commands from user
    while (1)
    {
        printf("Enter a command: ");
        fgets(cmd, MAX_CMD_LEN, stdin);

        // Checks if the command is valid
        if (strcmp(cmd, "exit") == 0)
        {
            printf("Exiting...\n");
            break;
        }
        else if (strcmp(cmd, "list") == 0)
        {
            // Lists all commands
            for (int i = 0; i < cmd_num; i++)
            {
                printf("%s\n", cmds[i]);
            }
        }
        else if (strcmp(cmd, "add") == 0)
        {
            // Adds a new command to the list
            cmds[cmd_num++] = malloc(MAX_CMD_LEN);
            printf("Enter the new command: ");
            fgets(cmds[cmd_num - 1], MAX_CMD_LEN, stdin);
        }
        else
        {
            printf("Invalid command. Please try again.\n");
        }
    }

    // Free allocated memory
    free(cmds);

    return 0;
}