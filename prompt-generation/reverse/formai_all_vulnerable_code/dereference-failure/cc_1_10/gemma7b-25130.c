//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 1024

char shell_prompt[] = "$ ";

void parse_command(char **argv)
{
    char cmd[MAX_CMD_LEN];

    printf("%s", shell_prompt);
    fgets(cmd, MAX_CMD_LEN, stdin);

    *argv = malloc(MAX_CMD_LEN);
    strcpy(*argv, cmd);

    // Split the command into arguments
    char *arg = strtok(*argv, " ");
    int i = 0;
    while (arg)
    {
        argv[i++] = arg;
        arg = strtok(NULL, " ");
    }

    argv[i] = NULL;
}

int main()
{
    char **argv = NULL;

    while (1)
    {
        parse_command(argv);

        // Check if the command is built-in or external
        if (strcmp(argv[0], "exit") == 0)
        {
            exit(0);
        }
        else
        {
            // Execute the command
            system(argv[0]);
        }
    }

    return 0;
}