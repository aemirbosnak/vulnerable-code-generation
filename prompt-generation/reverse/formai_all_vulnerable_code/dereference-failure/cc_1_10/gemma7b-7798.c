//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Command
{
    char **arguments;
    char *command;
    int argc;
} Command;

Command parse_command(char **input)
{
    Command cmd;
    char *command = strtok(*input, " ");
    cmd.command = strdup(command);

    cmd.arguments = malloc(sizeof(char *) * MAX_BUFFER_SIZE);
    int i = 0;
    for (char **arg = strtok(NULL, " "); arg; arg++)
    {
        cmd.arguments[i++] = strdup(arg);
    }

    cmd.argc = i;

    return cmd;
}

int main()
{
    char input[MAX_BUFFER_SIZE];

    printf("Welcome to the Future Shell!\n");
    printf("Enter a command: ");

    fgets(input, MAX_BUFFER_SIZE, stdin);

    Command cmd = parse_command(&input);

    // Execute the command
    if (strcmp(cmd.command, "exit") == 0)
    {
        printf("Goodbye!\n");
        exit(0);
    }
    else
    {
        printf("Invalid command.\n");
    }

    return 0;
}