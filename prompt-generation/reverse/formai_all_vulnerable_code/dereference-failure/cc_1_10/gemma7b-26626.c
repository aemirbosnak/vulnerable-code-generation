//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_LEN 256

char **parse_command(char **cmd_line)
{
    char **argv = NULL;
    int i = 0;
    char *cmd_str = strdup(*cmd_line);

    // Allocate memory for argv
    argv = malloc(sizeof(char *) * MAX_CMD_LEN);

    // Split the command line into arguments
    char *token = strtok(cmd_str, " ");
    while (token)
    {
        argv[i++] = token;
        token = strtok(NULL, " ");
    }

    // Null terminate argv
    argv[i] = NULL;

    return argv;
}

int main()
{
    char cmd_line[MAX_CMD_LEN];

    // Prompt the user for a command
    printf("$ ");

    // Get the user's command
    fgets(cmd_line, MAX_CMD_LEN, stdin);

    // Parse the command line
    char **argv = parse_command(&cmd_line);

    // Execute the command
    execvp(argv[0], argv);

    // Free the allocated memory
    free(argv);

    return 0;
}