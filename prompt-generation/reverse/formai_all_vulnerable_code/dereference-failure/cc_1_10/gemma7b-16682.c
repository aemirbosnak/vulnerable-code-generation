//Gemma-7B DATASET v1.0 Category: System administration ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 256

void parse_command(char **cmd, char **argv)
{
    int i = 0;

    *argv = malloc(MAX_CMD_LEN);

    // Strip whitespace and copy command and arguments
    for (i = 0; cmd[i] && cmd[i] != '\0'; i++)
    {
        if (cmd[i] != ' ')
        {
            (*argv)[i - 1] = cmd[i];
        }
        else
        {
            (*argv)[i - 1] = '\0';
            i--;
        }
    }

    (*argv)[i - 1] = '\0';
}

int main()
{
    char cmd[MAX_CMD_LEN];
    char *argv;

    printf("Enter a command: ");
    fgets(cmd, MAX_CMD_LEN, stdin);

    parse_command(&cmd, &argv);

    printf("Command: %s\n", argv[0]);
    printf("Arguments: ");
    for (int i = 1; argv[i] != '\0'; i++)
    {
        printf("%s, ", argv[i]);
    }

    printf("\n");

    return 0;
}