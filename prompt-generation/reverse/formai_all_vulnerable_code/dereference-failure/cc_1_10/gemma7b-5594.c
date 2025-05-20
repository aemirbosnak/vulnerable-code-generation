//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_CMD_LEN 1024

char shell_prompt[] = "$ ";

void execute_command(char *command)
{
    char **argv = NULL;
    char *path = NULL;
    int argc = 0;
    int i = 0;

    // Parse the command line arguments
    argv = malloc(MAX_CMD_LEN * sizeof(char *));
    path = malloc(MAX_CMD_LEN * sizeof(char));

    // Split the command into arguments and path
    char *token = strtok(command, " ");
    while (token)
    {
        argv[argc++] = token;
        token = strtok(NULL, " ");
    }

    // Set the path
    path = argv[0];

    // Execute the command
    if (fork() == 0)
    {
        execvp(path, argv);
    }
    else
    {
        wait(NULL);
    }

    // Free the memory
    free(argv);
    free(path);
}

int main()
{
    char command[MAX_CMD_LEN] = "";

    // Print the shell prompt
    printf("%s", shell_prompt);

    // Get the command from the user
    fgets(command, MAX_CMD_LEN, stdin);

    // Execute the command
    execute_command(command);

    return 0;
}