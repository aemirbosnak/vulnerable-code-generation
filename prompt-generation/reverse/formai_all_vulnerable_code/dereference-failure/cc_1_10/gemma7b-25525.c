//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_LEN 256

int main()
{
    char cmd[MAX_CMD_LEN];
    char **argv;
    int argc;
    int i;
    pid_t pid;
    int status;

    while (1)
    {
        printf("$ ");
        fgets(cmd, MAX_CMD_LEN, stdin);

        argv = NULL;
        argc = 0;
        i = 0;

        // Parse the command line
        while (cmd[i] && cmd[i] != '\0')
        {
            if (cmd[i] == ' ')
            {
                argv = realloc(argv, (argc + 1) * sizeof(char *));
                argv[argc++] = malloc(MAX_CMD_LEN);
                i++;
            }
            else
            {
                argv[argc] = malloc(MAX_CMD_LEN);
                strcpy(argv[argc], &cmd[i]);
                argc++;
            }
        }

        // Execute the command
        pid = fork();
        if (pid == 0)
        {
            execvp(argv[0], argv);
            exit(1);
        }
        else
        {
            wait(&status);
            printf("Exit status: %d\n", status);
        }

        free(argv);
    }

    return 0;
}