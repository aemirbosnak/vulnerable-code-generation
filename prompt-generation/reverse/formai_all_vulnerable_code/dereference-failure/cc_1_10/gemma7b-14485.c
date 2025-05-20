//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 1024

char cmd_buffer[MAX_CMD_LEN];

void parse_command(char *cmd)
{
    char **argv = NULL;
    char *arg = NULL;
    int argc = 0;

    // Tokenize the command
    argv = strtok(cmd, " ");

    // Count the number of arguments
    while (argv)
    {
        argc++;
        arg = strtok(NULL, " ");
        argv = strtok(NULL, " ");
    }

    // Allocate memory for the arguments
    argv = (char **)malloc(sizeof(char *) * argc);

    // Store the arguments
    for (int i = 0; i < argc; i++)
    {
        argv[i] = strdup(argv[i]);
    }

    // Execute the command
    execvp(argv[0], argv);
}

int main()
{
    // Prompt the user for a command
    printf("$ ");

    // Get the command
    fgets(cmd_buffer, MAX_CMD_LEN, stdin);

    // Parse the command
    parse_command(cmd_buffer);

    return 0;
}