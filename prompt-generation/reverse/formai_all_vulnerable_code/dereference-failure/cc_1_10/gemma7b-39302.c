//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 256

char shell_prompt[] = "prompt$ ";

void execute_command(char *command)
{
    char **argv = NULL;
    char *arg = NULL;
    int argc = 0;

    // Split the command into arguments
    arg = strtok(command, " ");
    while (arg)
    {
        argv = realloc(argv, (argc + 1) * sizeof(char *));
        argv[argc++] = arg;
        arg = strtok(NULL, " ");
    }

    // Execute the command
    if (argc > 0)
    {
        execvp(argv[0], argv);
    }
    else
    {
        printf("Error: invalid command.\n");
    }

    // Free the memory allocated for arguments
    free(argv);
}

int main()
{
    char command[MAX_CMD_LEN];

    // Enter the shell prompt
    printf("%s", shell_prompt);

    // Get the user command
    fgets(command, MAX_CMD_LEN, stdin);

    // Execute the command
    execute_command(command);

    return 0;
}