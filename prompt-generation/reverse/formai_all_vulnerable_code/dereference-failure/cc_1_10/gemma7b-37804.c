//Gemma-7B DATASET v1.0 Category: System administration ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_LEN 256

int main()
{
    char cmd[MAX_CMD_LEN];
    char **argv;
    int argc;
    int i;

    printf("Welcome to the C System Administration Interface!\n");

    // Get the user command
    printf("Enter a command: ");
    fgets(cmd, MAX_CMD_LEN, stdin);

    // Parse the command line arguments
    argv = NULL;
    argc = parse_command_line(cmd, &argv);

    // Execute the command
    if (argc)
    {
        for (i = 0; i < argc; i++)
        {
            printf("argv[%d] = %s\n", i, argv[i]);
        }

        execvp(argv[0], argv);
    }

    // Error message
    printf("Invalid command.\n");

    return 0;
}

int parse_command_line(char *cmd, char **argv)
{
    char *ptr;
    int argc = 0;

    ptr = strtok(cmd, " ");
    while (ptr)
    {
        argv[argc++] = strdup(ptr);
        ptr = strtok(NULL, " ");
    }

    return argc;
}