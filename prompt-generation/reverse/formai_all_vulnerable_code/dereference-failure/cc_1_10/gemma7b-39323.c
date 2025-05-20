//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 1024

char **parse_cmd(char **cmd_line);

int main()
{
    char **cmd_line = NULL;
    char **commands = NULL;
    size_t i = 0;

    printf("osh>");

    // Allocate memory for the command line
    cmd_line = malloc(MAX_CMD_LEN);

    // Get the command line input
    fgets(cmd_line, MAX_CMD_LEN, stdin);

    // Parse the command line
    commands = parse_cmd(cmd_line);

    // Execute the commands
    for (i = 0; commands[i] != NULL; i++)
    {
        printf("Command: %s\n", commands[i]);
    }

    // Free the memory
    free(cmd_line);
    free(commands);

    return 0;
}

char **parse_cmd(char **cmd_line)
{
    char **commands = NULL;
    char *cmd_ptr = NULL;
    size_t i = 0;

    // Allocate memory for the commands
    commands = malloc(MAX_CMD_LEN);

    // Split the command line into commands
    cmd_ptr = strtok(cmd_line, " ");
    while (cmd_ptr)
    {
        commands[i++] = strdup(cmd_ptr);
        cmd_ptr = strtok(NULL, " ");
    }

    return commands;
}