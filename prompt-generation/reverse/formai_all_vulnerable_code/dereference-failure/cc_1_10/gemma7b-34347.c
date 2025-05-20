//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_LEN 1024

char shell_prompt[] = "myshell $ ";

void do_shell()
{
    char cmd[MAX_CMD_LEN];
    char **args;
    int i;

    printf(shell_prompt);
    fgets(cmd, MAX_CMD_LEN, stdin);

    // Split the command into arguments
    args = malloc(sizeof(char *) * MAX_CMD_LEN);
    i = 0;
    args[i] = strtok(cmd, " ");
    while (args[i] != NULL)
    {
        i++;
        args[i] = strtok(NULL, " ");
    }

    // Execute the command
    if (fork() == 0)
    {
        execvp(args[0], args);
    }
    else
    {
        wait(NULL);
    }

    // Free the memory allocated for arguments
    free(args);
}

int main()
{
    while (1)
    {
        do_shell();
    }

    return 0;
}