//Gemma-7B DATASET v1.0 Category: System administration ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_CMD_LEN 255

void parse_command(char **command);
void execute_command(char **command);

int main()
{
    char command[MAX_CMD_LEN];

    printf("Welcome to the C System Administration Interface!\n");
    printf("Enter a command: ");

    fgets(command, MAX_CMD_LEN, stdin);

    parse_command(&command);
    execute_command(&command);

    return 0;
}

void parse_command(char **command)
{
    char **args = NULL;
    int i = 0;

    *command = strchr(*command, '\n');
    *command = NULL;

    args = malloc(MAX_CMD_LEN * sizeof(char *));

    while (*command)
    {
        args[i++] = strtok(*command, " ");
        *command = NULL;
    }

    args[i] = NULL;

    *command = args;
}

void execute_command(char **command)
{
    char **args = *command;

    if (strcmp(args[0], "help") == 0)
    {
        printf("Available commands:\n");
        printf("help\n");
        printf("shutdown\n");
        printf("add user\n");
    }
    else if (strcmp(args[0], "shutdown") == 0)
    {
        printf("Shutting down...\n");
        exit(0);
    }
    else if (strcmp(args[0], "add user") == 0)
    {
        printf("Adding user...\n");
        // Implement add user functionality
    }
    else
    {
        printf("Invalid command.\n");
    }
}