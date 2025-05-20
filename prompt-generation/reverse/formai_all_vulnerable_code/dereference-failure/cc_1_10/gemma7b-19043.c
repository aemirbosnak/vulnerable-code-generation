//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: standalone
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CMD_LEN 256

char shell_prompt[] = ">> ";

void execute_command(char *command)
{
    char **argv = NULL;
    char *arg = NULL;
    int argc = 0;
    int i = 0;

    // Tokenize the command into arguments
    argv = malloc(MAX_CMD_LEN * sizeof(char *));
    arg = strtok(command, " ");

    while (arg)
    {
        argv[argc++] = arg;
        arg = strtok(NULL, " ");
    }

    // Execute the command
    if (argc > 0)
    {
        execvp(argv[0], argv);
    }

    // Free memory
    free(argv);
}

int main()
{
    char command[MAX_CMD_LEN];

    // Display the shell prompt
    printf("%s", shell_prompt);

    // Get the command from the user
    fgets(command, MAX_CMD_LEN, stdin);

    // Execute the command
    execute_command(command);

    return 0;
}