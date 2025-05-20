//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: modular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_CMD_LEN 256

char **parse_command(char *cmd)
{
    char **args = NULL;
    int i = 0;
    char *arg = NULL;

    // Allocate memory for arguments
    args = malloc(MAX_CMD_LEN * sizeof(char *));

    // Split the command into arguments
    arg = strtok(cmd, " ");
    while (arg)
    {
        args[i++] = arg;
        arg = strtok(NULL, " ");
    }

    // Null terminate the arguments
    args[i] = NULL;

    return args;
}

int main()
{
    char cmd[MAX_CMD_LEN];

    // Get the user command
    printf("$ ");
    fgets(cmd, MAX_CMD_LEN, stdin);

    // Parse the command
    char **args = parse_command(cmd);

    // Execute the command
    if (args[0] != NULL)
    {
        execvp(args[0], args);
    }

    // Error message
    printf("Error: command not found.\n");

    return 0;
}