//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_LEN 255

char shellPrompt[] = "msh$ ";

void executeCommand(char *command)
{
    char **args = NULL;
    char *arg = NULL;
    int i = 0;

    // Tokenize the command
    args = strtok(command, " ");

    // Allocate memory for arguments
    arg = malloc((MAX_CMD_LEN - 1) * sizeof(char *));

    // Store arguments
    while (args)
    {
        arg[i++] = strdup(args);
        args = strtok(NULL, " ");
    }

    // Null terminate arguments
    arg[i] = NULL;

    // Execute the command
    execvp(arg[0], arg);

    // Free memory
    free(arg);
}

int main()
{
    char command[MAX_CMD_LEN];

    // Print the shell prompt
    printf("%s", shellPrompt);

    // Get the command from the user
    fgets(command, MAX_CMD_LEN, stdin);

    // Execute the command
    executeCommand(command);

    return 0;
}