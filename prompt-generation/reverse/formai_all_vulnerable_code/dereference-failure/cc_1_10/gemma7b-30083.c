//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_LEN 256

int main()
{
    char cmd[MAX_CMD_LEN];
    char **args;
    int i;
    pid_t pid;

    // Enter shell loop
    while (1)
    {
        // Print prompt
        printf("$ ");

        // Get user input
        fgets(cmd, MAX_CMD_LEN, stdin);

        // Parse command line arguments
        args = NULL;
        i = 0;
        cmd[strcspn(cmd, "\n")] = '\0';
        args = malloc(MAX_CMD_LEN * sizeof(char *));
        while ((args[i] = strtok(NULL, " ")) != NULL)
        {
            i++;
        }

        // Create child process
        pid = fork();

        // Child process
        if (pid == 0)
        {
            // Execute command
            execvp(args[0], args);

            // Error if execvp fails
            printf("Error executing command: %s\n", args[0]);
            exit(1);
        }

        // Parent process
        wait(NULL);

        // Free memory
        free(args);
    }

    return 0;
}