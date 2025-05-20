//Gemma-7B DATASET v1.0 Category: Log analysis ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

int main()
{

    // Declare variables
    int num_proc = 4;
    int i = 0;
    int status = 0;
    char **commands = NULL;

    // Allocate memory for commands array
    commands = malloc(num_proc * sizeof(char *));
    for (i = 0; i < num_proc; i++)
    {
        commands[i] = malloc(20 * sizeof(char));
    }

    // Get commands from user
    for (i = 0; i < num_proc; i++)
    {
        printf("Enter command for process %d: ", i + 1);
        scanf("%s", commands[i]);
    }

    // Spawn processes
    for (i = 0; i < num_proc; i++)
    {
        status = fork();
        if (status == 0)
        {
            // Child process
            execlp("/bin/bash", "/bin/bash", "-c", commands[i], NULL);
            exit(0);
        }
        else if (status > 0)
        {
            // Parent process
            wait(NULL);
        }
    }

    // Free memory
    for (i = 0; i < num_proc; i++)
    {
        free(commands[i]);
    }
    free(commands);

    return 0;
}