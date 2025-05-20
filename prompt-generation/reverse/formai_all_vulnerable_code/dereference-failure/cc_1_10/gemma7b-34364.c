//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 256

int main()
{
    char cmd[MAX_CMD_LEN];
    char **argv;
    int argc;

    while (1)
    {
        printf("$ ");
        fgets(cmd, MAX_CMD_LEN, stdin);

        // Parse the command line
        argv = NULL;
        argc = parse_cmd(cmd, &argv);

        // Execute the command
        if (argc > 0)
        {
            execvp(argv[0], argv);
        }

        // Handle errors
        perror("Error:");
    }

    return 0;
}

int parse_cmd(char *cmd, char **argv)
{
    char *ptr, *argv_copy;
    int argc = 0;

    // Allocate memory for argv
    argv_copy = malloc(MAX_CMD_LEN * sizeof(char *));

    // Tokenize the command line
    ptr = strtok(cmd, " ");
    while (ptr)
    {
        argv_copy[argc++] = strdup(ptr);
        ptr = strtok(NULL, " ");
    }

    // Null terminate argv
    argv_copy[argc] = NULL;

    // Return the number of arguments
    return argc;
}