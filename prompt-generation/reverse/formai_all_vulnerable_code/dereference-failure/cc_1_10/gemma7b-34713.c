//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_LEN 1024

char cmd_buffer[MAX_CMD_LEN];

void execute_command(char *cmd)
{
    char **args = NULL;
    char *arg = NULL;
    int i = 0;

    // Split the command into arguments
    args = malloc(MAX_CMD_LEN * sizeof(char *));
    arg = strtok(cmd, " ");
    while (arg)
    {
        args[i++] = arg;
        arg = strtok(NULL, " ");
    }

    // Execute the command
    if (fork() == 0)
    {
        execvp(args[0], args);
        exit(1);
    }

    // Wait for the child process to complete
    wait(NULL);

    // Free the memory allocated for arguments
    free(args);
}

int main()
{
    char prompt[] = "Shell $ ";

    // Enter the shell loop
    while (1)
    {
        // Print the prompt
        printf("%s", prompt);

        // Get the user input
        fgets(cmd_buffer, MAX_CMD_LEN, stdin);

        // Execute the command
        execute_command(cmd_buffer);
    }

    return 0;
}