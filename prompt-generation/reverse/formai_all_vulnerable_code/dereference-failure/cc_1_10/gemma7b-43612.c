//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_CMD_LEN 256

char **parse_command(char **argv)
{
    char **new_argv = malloc(MAX_CMD_LEN * sizeof(char *));
    int i = 0;

    for (i = 0; argv[i] != NULL; i++)
    {
        new_argv[i] = strdup(argv[i]);
    }

    new_argv[i] = NULL;

    return new_argv;
}

int main()
{
    char cmd[MAX_CMD_LEN];

    while (1)
    {
        printf("$ ");
        fgets(cmd, MAX_CMD_LEN, stdin);

        char **argv = parse_command(cmd);

        if (argv[0] == NULL)
        {
            continue;
        }

        if (fork() == 0)
        {
            execvp(argv[0], argv);
            exit(1);
        }

        wait(NULL);

        free(argv);
    }

    return 0;
}